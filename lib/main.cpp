#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <chrono>
#include <string.h>
#include <ios>

#include "Graph.h"


int main(int argc, char **argv) {

    if (argc < 2)
    {
        return 0;
    }
    
    int n;
    int m;
    int i;

    std::string line;
    std::ifstream file(argv[1]);

    if (file.is_open()) {
        if (strcmp(argv[2],"-d") == 0) {
            double media = 0;
            for (int d=0; d<=20; d++) {
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

                auto start = std::chrono::high_resolution_clock::now();
                char command;
                for (int l=0;l<i;l++) {
                    file >> command;
                    if (command == 'C'){
                        int index;
                        file >> index;
                        int yc = graph.getYoungest(index-1);

                    } else if (command == 'S') {
                        int V1,V2;
                        file >> V1 >> V2;
                        bool w = graph.swap(V1-1,V2-1);

                    } else if (command == 'M') {
                        graph.printMeeting(true);
                    }
                }
                file.clear();
                file.seekg(0, std::ios::beg);

                auto stop = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
                media = media + duration.count();

            }
            std::cout << media/20 << std::endl;
            return 0;
        }

        // file >> n >> m >> i;
        // int *ages = new int[n];
        // for (int j=0;j<n;j++) {
        //     file >> ages[j]; 
        // }
        
        // Graph graph = Graph(n, ages);

        // int v1;
        // int v2;
        // for (int k = 0; k < m; k++) {
        //     file >> v1 >> v2;
        //     graph.add_edge(v2-1,v1-1);
        // }
        
        // char command;
        // for (int l=0;l<i;l++) {
        //     file >> command;
        //     if (command == 'C'){
        //         int index;
        //         file >> index;
        //         int yc = graph.getYoungest(index-1);
        //         if (yc == -1) 
        //             std::cout << "C *" << endl;
        //         else 
        //             std::cout << "C " << yc << endl;

        //     } else if (command == 'S') {
        //         int V1,V2;
        //         file >> V1 >> V2;
        //         bool w = graph.swap(V1-1,V2-1);
        //         if (w)
        //             std::cout << "S T" << endl;
        //         else 
        //             std::cout << "S N" << endl;

        //     } else if (command == 'M') {
        //         std::cout << "M ";
        //         graph.printMeeting(false);
        //         std::cout << endl;
        //     }
        // }
        // file.close();
    }


    

    return 0;
}