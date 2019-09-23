#include <stdlib.h>
#include <iostream>
#include <sstream>

#include "MatrixGraph.h"

using namespace std;

int main() {
    
    int *ages = new int[8];
    ages[0] = 0;
    ages[1] = 21;
    ages[2] = 33;
    ages[3] = 34;

    MatrixGraph graph = MatrixGraph(4, ages);

    graph.add_edge(0,1);
    graph.add_edge(1,2);
    graph.add_edge(2,3);
    graph.add_edge(0,3);

    
    graph.print_graph();
    cout << endl;
    graph.printMeeeting();
    //graph.printMeeeting();

    bool w = graph.swap(0,3);
    
    if (w) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    //cout << endl << graph.youngest_commander(0) << endl;
    return 0;
}