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
    ages[4] = 10;
    ages[5] = 14;
    ages[6] = 18;
    ages[7] = 19;
    ages[8] = 55;
    ages[9] = 56;

    MatrixGraph graph = MatrixGraph(10, ages);

    graph.add_edge(0,7);
    graph.add_edge(0,1);
    graph.add_edge(1,5);
    graph.add_edge(2,3);
    graph.add_edge(2,4);
    graph.add_edge(3,4);
    graph.add_edge(1,2);
    graph.add_edge(4,5);
    graph.add_edge(7,6);
    graph.add_edge(9,8);

    
    graph.print_graph();
    cout << endl;
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