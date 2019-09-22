#include "MatrixGraph.h"
#include <iostream>
#include <sstream>

using namespace std;

MatrixGraph::MatrixGraph(int num_students, int *_ages) {
    this->num_students = num_students;
    this->vertex_matrix = new int*[num_students];
    this->ages = _ages;

    for (int i=0; i<num_students; i++) {
        this->vertex_matrix[i] = new int[num_students];
    }

    for (int i=0; i<num_students; i++) {
        for (int j=0; j<num_students; j++) {
            this->vertex_matrix[i][j] = 0;
        }
    }
}

MatrixGraph::~MatrixGraph() {
    for (int i=0; i<this->num_students; i++) {
        delete[] this->vertex_matrix[i];
    }
    delete[] this->vertex_matrix;
}

void MatrixGraph::add_edge(int v1, int v2) {
    if(this->vertex_matrix[v1][v2] == 0) {
        this->vertex_matrix[v1][v2] = 1;
    }
}

void MatrixGraph::del_edge(int v1, int v2) {
    if(this->vertex_matrix[v1][v2] == 1) {
        this->vertex_matrix[v1][v2] = 0;
    }
}

int MatrixGraph::youngest_commander(int v1) {
    int youngest_age = 1000;
    for (int i=0; i<this->num_students; i++) {
        if (this->vertex_matrix[i][v1] == 1) {
            if (this->ages[i] < youngest_age) {
                youngest_age = this->ages[i];
            }
        }
    }
    if (youngest_age == 1000)
        return -1;
    else
        return youngest_age;
    
}

bool MatrixGraph::swap(int v1, int v2) {
    this->vertex_matrix[v1][v2] = 0;
    this->vertex_matrix[v2][v1] = 1;
   
   
    bool canSwap = verifySwap(v1,v2);
    if (canSwap == false) {
        this->vertex_matrix[v1][v2] = 1;
        this->vertex_matrix[v2][v1] = 0;
        return false;
    } else {
        return true;
    }
    
}

bool MatrixGraph::verifySwap(int v1, int v2) {
    int *checkList = new int[this->num_students];
    for (int j=0;j<this->num_students;j++) {
        checkList[j] == -1;
    }
    
    int k = 0;
    for (int i=0; i<this->num_students; i++) {
        if (this->vertex_matrix[v1][i] == 1) {
            checkList[k] = i;
            k++;
        }
    }
    if (checkList[0] == -1)
        return true;
    
    bool passHere = false;
    bool alreadyThere = false;
    int now = checkList[0];
    while(1) {
        
        passHere = false;
        for (int a=0; a<this->num_students; a++) {
            if (this->vertex_matrix[now][a] == 1) {
                if(a == v2) {
                    return false;
                }
                for (int u=0;u<this->num_students;u++) {
                    if (checkList[u] == a) {
                        alreadyThere = true;
                    }
                }
                if(!alreadyThere) {
                    checkList[k] = a;
                    k++;
                }
                
            }
            alreadyThere = false;
        }
        for (int y=0; y<this->num_students;y++) {
            if(checkList[y] == now) {
                checkList[y] = -1;
            }
        }
        for (int z=0; z<this->num_students; z++) {
            if (checkList[z] != -1 ) {
                now = checkList[z];
                passHere = true;
            }
        }
        if(!passHere)
            break;   
        
    }
    return true;
}

void MatrixGraph::printMeeeting() {
    int *meetingList = new int[this->num_students];
    for (int i=0;i<this->num_students;i++) {
        meetingList[i] = i;
    }
    bool passToNext = true;
    int j = 0;
    for (int k=0; k<this->num_students; k++) {
        j = 0;
        while(j < this->num_students) {
            passToNext = true;
            if (this->vertex_matrix[j][meetingList[k]] == 1) {
                if(isInMyRight(k,j,meetingList)) {
                    changeInMeeting(k,j,&*meetingList);
                    passToNext = false;
                }
            }
            if (passToNext == false) {
                j = 0;
            } else {
                j++;
            }
        }
    }
    for(int m=0;m<this->num_students;m++) {
        cout << meetingList[m] << " ";
    }
    cout << endl;
}

void MatrixGraph::changeInMeeting(int v1, int v2, int *meetingList) {
    int pos1;
    int pos2;
    for (int i=0;i<this->num_students;i++) {
        if (meetingList[i] == v1)
            pos1 = i;
        if (meetingList[i] == v2)
            pos2 = i;
    }
    cout << pos1 << " " << pos2 << endl;
    meetingList[pos1] = v2;
    meetingList[pos2] = v1;
}

bool MatrixGraph::isInMyRight(int v1, int v2, int *meetingList) {
    int pos1;
    int pos2;
    for (int i=0;i<this->num_students;i++)  {
        if (meetingList[i] == v1)
            pos1 = i;
        if (meetingList[i] == v2)
            pos2 = i;
    }
    cout << pos1 << " " << pos2 << endl;
    if (pos2 > pos1)
        return true;
    else
        return false;
    
}

void MatrixGraph::print_graph() {
    for (int i=0; i<this->num_students; i++) {
        for (int j=0; j<this->num_students; j++) {
            cout << this->vertex_matrix[i][j] << " ";
        }
        cout << endl;
    }
}