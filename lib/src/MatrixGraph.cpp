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

// bool MatrixGraph::swap(int v1, int v2) {
//     this->vertex_matrix[v1][v2] = 0;
//     this->vertex_matrix[v2][v1] = 1;
   
   
//     bool canSwap = verifySwap(v1,v2);
//     if (canSwap == false) {
//         this->vertex_matrix[v1][v2] = 1;
//         this->vertex_matrix[v2][v1] = 0;
//         return false;
//     } else {
//         return true;
//     }
    
// }

// bool MatrixGraph::verifySwap(int v1, int v2) {
//     int *checkList = new int[this->num_students];
//     for (int j=0;j<this->num_students;j++) {
//         checkList[j] == -1;
//     }
    
//     int k = 0;
//     for (int i=0; i<this->num_students; i++) {
//         if (this->vertex_matrix[v1][i] == 1) {
//             checkList[k] = i;
//             k++;
//         }
//     }
//     if (checkList[0] == -1)
//         return true;
    
//     bool passHere = false;
//     bool alreadyThere = false;
//     int now = checkList[0];
//     while(1) {
        
//         passHere = false;
//         for (int a=0; a<this->num_students; a++) {
//             if (this->vertex_matrix[now][a] == 1) {
//                 if(a == v2) {
//                     return false;
//                 }
//                 for (int u=0;u<this->num_students;u++) {
//                     if (checkList[u] == a) {
//                         alreadyThere = true;
//                     }
//                 }
//                 if(!alreadyThere) {
//                     checkList[k] = a;
//                     k++;
//                 }
                
//             }
//             alreadyThere = false;
//         }
//         for (int y=0; y<this->num_students;y++) {
//             if(checkList[y] == now) {
//                 checkList[y] = -1;
//             }
//         }
//         for (int z=0; z<this->num_students; z++) {
//             if (checkList[z] != -1 ) {
//                 now = checkList[z];
//                 passHere = true;
//             }
//         }
//         if(!passHere)
//             break;   
        
//     }
//     return true;
// }

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