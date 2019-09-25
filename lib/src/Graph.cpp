#include "Graph.h"
#include <iostream>
#include <sstream>

using namespace std;

Graph::Graph(int num_students, int *_ages) {
    this->num_students = num_students;
    this->vertex_list = new LinkedList*[num_students];
    this->ages = _ages;
    this->printList = new int[this->num_students];
    this->canSwap = true;
    this->youngest = 1000;

    for (int i=0; i<num_students; i++) {
        this->vertex_list[i] = new LinkedList();
    }

    for (int p=0; p<this->num_students; p++) {
        this->printList[p] = p;
    }
}

Graph::~Graph() {
    
}
void Graph::updatePrintList(int index) {
    this->printList[index] = -1;
}

void Graph::add_edge(int v1, int v2) {
    this->vertex_list[v1]->insertElement(v2,this->ages[v2]);
}

void Graph::del_edge(int v1, int v2) {
    this->vertex_list[v1]->deleteElement(v2);
}

void Graph::youngest_commander(int v1) {
    for (int i=0;i<this->vertex_list[v1]->size();i++) {
        int next = this->vertex_list[v1]->getByPosition(i);
        if (this->ages[next] < this->youngest) {
            this->youngest = this->ages[next];
        }
        this->youngest_commander(next);
    }
    return;
}
int Graph::getYoungest(int v) {
    this->youngest_commander(v);
    if (this->youngest == 1000) {
        return -1;
    } else {
        int y = this->youngest;
        this->youngest = 1000;
        return y;
    }

}

bool Graph::swap(int v1, int v2) {
    bool t = this->vertex_list[v1]->deleteForSwap(v2);
    bool x = this->vertex_list[v2]->deleteForSwap(v1);
    if (t == true) {
        bool canSwap = true;
        this->add_edge(v2,v1);
        this->verifySwap(v2,v2);
        if (this->canSwap == false) {
            this->del_edge(v2,v1);
            this->add_edge(v1,v2);
            this->canSwap = true;
            return false;
        } else {
            return true;
        }
    } if (x == true) {
        bool canSwap = true;
        this->add_edge(v1,v2);
        this->verifySwap(v1,v1);
        if (this->canSwap == false) {
            this->del_edge(v1,v2);
            this->add_edge(v2,v1);
            this->canSwap = true;
            return false;
        } else {
            return true;
        }
        return true;

    } if (x == false && t == false)
            return false;
    
}

void Graph::verifySwap(int v, int verify) {
    for (int i=0;i<this->vertex_list[v]->size();i++) {
        if (this->vertex_list[v]->getByPosition(i) == verify) {
            this->canSwap = false;
            break;
        }
        this->verifySwap(this->vertex_list[v]->getByPosition(i),verify);
    }
    return;
}

void Graph::printMeeting(bool debug) {
    for (int i=0; i<this->num_students; i++) {
        if (this->printList[i] != -1) {
            this->posOrder(i, debug);
        }
    }
    for (int p=0; p<this->num_students; p++) {
        this->printList[p] = p;
    }
}

void Graph::posOrder(int index, bool debug) {
    for (int i=0;i<this->vertex_list[index]->size();i++) {
        this->posOrder(this->vertex_list[index]->getByPosition(i),debug);
    }
    if (this->printList[index] != -1) {
        if (!debug)
            cout << index+1 << " ";
        this->updatePrintList(index);
    }
    return;
}

void Graph::print_graph() {
    for (int i=0; i<this->num_students; i++) {
        cout << i+1 << " | " ;
        this->vertex_list[i]->printList();
        cout << endl;
    }
}