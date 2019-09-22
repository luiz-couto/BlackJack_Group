#include <stdlib.h>
#include <iostream>
#include <sstream>

#include "MatrixGraph.h"

using namespace std;

int main() {
    
    int *ages = new int[7];
    ages[0] = 21;
    ages[1] = 33;
    ages[2] = 34;
    ages[3] = 18;
    ages[4] = 42;
    ages[5] = 22;
    ages[6] = 26;

    MatrixGraph graph = MatrixGraph(7, ages);

    graph.add_edge(1,0);
    graph.add_edge(2,0);
    graph.add_edge(4,1);
    graph.add_edge(4,2);
    graph.add_edge(2,5);
    graph.add_edge(5,3);
    graph.add_edge(6,3);
    graph.add_edge(6,5);

    
    graph.print_graph();
    //cout << endl;
    graph.printMeeeting();
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