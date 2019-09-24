#ifndef GRAPH_
#define GRAPH_

#include <iostream>
#include <sstream>
#include "LinkedList.h"

class Graph  {
    private:
        LinkedList ** vertex_list ;
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
        Graph(int num_students, int *ages);
        ~Graph();
        void add_edge(int v1, int v2);
        void del_edge(int v1, int v2);
        int getYoungest(int v);
        bool swap(int v1, int v2);
        void printMeeting();
        void print_graph(); //debug
};




#endif