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
    ages[3] = 18;
    ages[4] = 24;
    ages[5] = 19;
    ages[6] = 26;
    ages[7] = 27;
    ages[8] = 28;
    ages[9] = 29;

    MatrixGraph graph = MatrixGraph(10, ages);

    graph.add_edge(0,1);
    graph.add_edge(9,8);
    graph.add_edge(2,0);
    graph.add_edge(3,0);
    graph.add_edge(5,0);
    graph.print_graph();
    cout << endl << graph.youngest_commander(0) << endl;
    return 0;
}