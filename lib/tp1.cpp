#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "Graph.h"

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
        
        Graph graph = Graph(n, ages);

        int v1;
        int v2;
        for (int k = 0; k < m; k++) {
            file >> v1 >> v2;
            graph.add_edge(v2-1,v1-1);
        }
        
        char command;
        for (int l=0;l<i;l++) {
            file >> command;
            if (command == 'C'){
                int index;
                file >> index;
                int yc = graph.getYoungest(index-1);
                if (yc == -1) 
                    cout << "C *" << endl;
                else 
                    cout << "C " << yc << endl;

            } else if (command == 'S') {
                int V1,V2;
                file >> V1 >> V2;
                bool w = graph.swap(V1-1,V2-1);
                if (w)
                    cout << "S T" << endl;
                else 
                    cout << "S N" << endl;

            } else if (command == 'M') {
                cout << "M ";
                graph.printMeeting();
                cout << endl;
            }
        }
        file.close();
    }


    

    return 0;
}