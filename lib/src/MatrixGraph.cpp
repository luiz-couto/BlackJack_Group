#include "MatrixGraph.h"
#include <iostream>
#include <sstream>

using namespace std;

MatrixGraph::MatrixGraph(int num_students, int *_ages) {
    this->num_students = num_students;
    this->vertex_matrix = new LinkedList*[num_students];
    this->ages = _ages;
    this->printList = new int[this->num_students];

    for (int i=0; i<num_students; i++) {
        this->vertex_matrix[i] = new LinkedList();
    }

    for (int p=0; p<this->num_students; p++) {
        this->printList[p] = p;
    }
}

MatrixGraph::~MatrixGraph() {
    
}
void MatrixGraph::updatePrintList(int index) {
    this->printList[index] = -1;
}

void MatrixGraph::add_edge(int v1, int v2) {
    this->vertex_matrix[v1]->insertElement(v2,this->ages[v2]);
}

void MatrixGraph::del_edge(int v1, int v2) {
    this->vertex_matrix[v1]->deleteElement(v2);
}

int MatrixGraph::youngest_commander(int v1) {
    return this->vertex_matrix[v1]->youngest();
}

bool MatrixGraph::swap(int v1, int v2) {
    if (this->vertex_matrix[v1]->deleteForSwap(v2) == true) {
        bool canSwap = true;
        this->add_edge(v2,v1);
        canSwap = this->verifySwap(v2);
        if (!canSwap) {
            this->del_edge(v2,v1);
            this->add_edge(v1,v2);
            return false;
        } else {
            return true;
        }
    } else if (this->vertex_matrix[v2]->deleteForSwap(v1) == true) {
        bool canSwap = true;
        this->add_edge(v1,v2);
        canSwap = this->verifySwap(v1);
        if (!canSwap) {
            this->del_edge(v1,v2);
            this->add_edge(v2,v1);
            return false;
        } else {
            return true;
        }

    } else {
        return false;
    }
    
}

bool MatrixGraph::verifySwap(int v) {
    for (int i=0;i<this->vertex_matrix[v]->size();i++) {
        if (this->vertex_matrix[v]->getByPosition(i) == v) {
            return false;
        }
        this->verifySwap(this->vertex_matrix[v]->getByPosition(i));
    }
    return true;
}

void MatrixGraph::printMeeeting() {
    for (int i=0; i<this->num_students; i++) {
        if (this->printList[i] != -1) {
            this->posOrder(i);
        }
    }
}

void MatrixGraph::posOrder(int index) {
    for (int i=0;i<this->vertex_matrix[index]->size();i++) {
        this->posOrder(this->vertex_matrix[index]->getByPosition(i));
    }
    if (this->printList[index] != -1) {
        cout << index << " ";
        this->updatePrintList(index);
    }
    return;
}

void MatrixGraph::print_graph() {
    for (int i=0; i<this->num_students; i++) {
        cout << i << " | " ;
        this->vertex_matrix[i]->printList();
        cout << endl;
    }
}