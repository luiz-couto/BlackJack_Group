#include <stdlib.h>
#include <iostream>
#include <sstream>

#include "MatrixGraph.h"

using namespace std;

int main() {
    
    int *ages = new int[10];
    ages[0] = 22;
    ages[1] = 21;
    ages[2] = 23;
    ages[3] = 30;
    ages[4] = 24;
    ages[5] = 25;
    ages[6] = 26;
    ages[7] = 27;
    ages[8] = 28;
    ages[9] = 29;

    MatrixGraph graph = MatrixGraph(10, ages);

    graph.add_edge(0,1);
    graph.add_edge(9,8);
    graph.del_edge(8,8);
    graph.print_graph();
    return 0;
}