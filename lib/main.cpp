#include <stdlib.h>
#include <iostream>
#include <sstream>

#include "MatrixGraph.h"

using namespace std;

int main() {
    
    int *ages = new int[8];
    ages[0] = 22;
    ages[1] = 21;
    ages[2] = 23;
    ages[3] = 18;
    ages[4] = 18;
    ages[5] = 18;
    ages[6] = 18;
    ages[7] = 18;

    MatrixGraph graph = MatrixGraph(8, ages);

    graph.add_edge(1,2);
    graph.add_edge(1,3);
    graph.add_edge(2,5);
    graph.add_edge(3,5);
    graph.add_edge(3,6);
    graph.add_edge(4,6);
    graph.add_edge(4,7);
    graph.add_edge(6,7);
    graph.add_edge(4,5);
    
    graph.print_graph();
    graph.del_edge(4,6);
    graph.print_graph();
    //graph.printMeeeting();

    // bool w = graph.swap(4,7);
    
    // if (w) {
    //     cout << "true" << endl;
    // } else {
    //     cout << "false" << endl;
    // }

    //cout << endl << graph.youngest_commander(0) << endl;
    return 0;
}