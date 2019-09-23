#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "MatrixGraph.h"

using namespace std;

int main(int argc, char **argv) {

    if (argc < 2)
    {
        return 0;
    }
    
    int n;
    int m;
    int i;

    string line;
    ifstream file(argv[1]);
    if (file.is_open()) {
        
        file >> n >> m >> i;
        int *ages = new int[n];
        for (int j=0;j<n;j++) {
            file >> ages[j]; 
        }
        
        MatrixGraph graph = MatrixGraph(n, ages);

        int v1;
        int v2;
        
        for (int k = 0; k < m; k++) {
            file >> v1 >> v2;
            graph.add_edge(v2-1,v1-1);
        }
        
        char command;
        //file >> command;
        for (int l=0;l<i;l++) {
            file >> command;
            if (command == 'C'){
                int index;
                file >> index;
                cout << graph.youngest_commander(index-1) << endl;
            } else if (command == 'S') {
                int V1,V2;
                file >> V1 >> V2;
                if (graph.swap(V1-1,V2-1))
                    cout << "S T" << endl;
                else 
                    cout << "S N" << endl;
            } else if (command == 'M') {
                graph.printMeeeting();
                cout << endl;
            }
        }
        

        file.close();
    }


    
    // int *ages = new int[8];
    // ages[0] = 0;
    // ages[1] = 21;
    // ages[2] = 33;
    // ages[3] = 34;

    // MatrixGraph graph = MatrixGraph(4, ages);

    // graph.add_edge(0,1);
    // graph.add_edge(1,2);
    // graph.add_edge(2,3);
    // graph.add_edge(0,3);

    
    // graph.print_graph();
    // cout << endl;
    // graph.printMeeeting();
    // //graph.printMeeeting();

    // bool w = graph.swap(0,3);
    
    // if (w) {
    //     cout << "true" << endl;
    // } else {
    //     cout << "false" << endl;
    // }

    //cout << endl << graph.youngest_commander(0) << endl;
    return 0;
}