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

void MatrixGraph::print_graph() {
    for (int i=0; i<this->num_students; i++) {
        for (int j=0; j<this->num_students; j++) {
            cout << this->vertex_matrix[i][j] << " ";
        }
        cout << endl;
    }
}