#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

void generateTesteCase(const char *filename, int N, int S, int C, int M) {
    std::ofstream myfile;
    myfile.open(filename);
    int A = N>0? N-1:0;
    myfile << N << " " << A << " " << S+C+M << endl;
    for (int i=20;i<20+N;i++) {
        myfile << i;
        if (i!=20+N-1) {
            myfile << " ";
        }
    }
    myfile << endl;
    for (int i=1; i<N; i++) {
        myfile << i << " " << i+1 << endl;
    }
    for (int i=N; i>N-C; i--) {
        myfile << "C " << i << endl;
    }
    for (int i=0; i<=S; i++) {
        myfile << "S " << N-i-1 << " " << N-i << endl;
    }
    for (int i=1; i<=M; i++) {
        myfile << "M" << endl;
    }
    myfile.close();
}

int main(int argc, char **argv) {

    generateTesteCase(argv[1], atoi(argv[2]), atoi(argv[3]), atoi(argv[4]),atoi(argv[5]));
    return 0;
}