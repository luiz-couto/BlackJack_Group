#include <stdlib.h>
#include <iostream>
#include <sstream>

#include "MatrixGraph.h"

using namespace std;

int main() {
    MatrixGraph graph = MatrixGraph(10);
    graph.add_edge(0,1);
    graph.add_edge(9,8);
    graph.print_graph();
    return 0;
}