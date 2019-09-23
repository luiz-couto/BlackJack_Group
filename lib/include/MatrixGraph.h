#ifndef MATRIX_GRAPH_
#define MATRIX_GRAPH_

#include <iostream>
#include <sstream>
#include "LinkedList.h"

class MatrixGraph  {
    private:
        LinkedList ** vertex_matrix;
        int num_students;
        int *ages;
        int *printList;
        bool canSwap;
        int youngest;
        
        void verifySwap(int v,int verify);
        void youngest_commander(int v1);
        void posOrder(int index);
        void updatePrintList(int index);
    
    public:
        MatrixGraph(int num_students, int *ages);
        ~MatrixGraph();
        void add_edge(int v1, int v2);
        void del_edge(int v1, int v2);
        int getYoungest(int v);
        bool swap(int v1, int v2);
        void printMeeting();
        void print_graph(); //debug
};




#endif