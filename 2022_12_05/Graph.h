//
// Created by sebmc on 03/12/2021.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

struct graph{
    int** adjMatrix = nullptr;
    int number_of_nodes = 0;
};

void init(graph& g, int number_of_nodes);
void fill_graph(graph& g, const char* file_path);
void print_graph(graph& g);
void dependences(graph& g, int node);
void dealloc(graph& g);


struct set{
    int* arrayList = nullptr;
    int current_size = 0;
    int buffer_length = 5;
    const float EXPANSION_FACTOR = 2.0;
    const float LOAD = 0.25;
};

void init(set& s);
void insert(set& s, int value);
void remove_element(set& s, int value);
bool contains(set& s, int value);
void expand(set& s);
void shrink(set& s);
bool empty(set& s);
bool full(set &s);
void print_set(set& s);
void dealloc(set& s);





#endif //GRAPHS_GRAPH_H
