#include <iostream>
#include "Graph.h"


using namespace std;


int main(int argc, char** argv) {
    graph g;
    if (argc < 2){
        cerr << "Missing input file" << endl;
        exit(1);
    }
    fill_graph(g, argv[1]);

    print_graph(g);

    cout << "Calc dependecies for node: ";
    int node;
    cin >> node;

    dependences(g, node);

    return 0;
}
