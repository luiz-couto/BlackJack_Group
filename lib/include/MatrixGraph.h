#ifndef MATRIX_GRAPH_
#define MATRIX_GRAPH_

#include <iostream>
#include <sstream>

class MatrixGraph  {
    private:
        int ** vertex_matrix;
        int num_students;
        int *ages;
        
        bool verifySwap(int v1, int v2);
    
    public:
        MatrixGraph(int num_students, int *ages);
        ~MatrixGraph();
        void add_edge(int v1, int v2);
        void del_edge(int v1, int v2);
        int youngest_commander(int v1);
        bool swap(int v1, int v2);
        void print_graph();
};




#endif