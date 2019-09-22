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
        
        bool isInMyRight(int v1, int v2, int *meetingList);
        bool verifySwap(int v1, int v2);
        void changeInMeeting(int v1, int v2, int *meetingList);
    
    public:
        MatrixGraph(int num_students, int *ages);
        ~MatrixGraph();
        void add_edge(int v1, int v2);
        void del_edge(int v1, int v2);
        int youngest_commander(int v1);
        bool swap(int v1, int v2);
        void posOrder(int index);
        void printMeeeting();
        void updatePrintList(int index);
        void print_graph(); //debug
};




#endif