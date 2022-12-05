//
// Created by sebmc on 03/12/2021.
//

#include "Graph.h"


void init(graph &g, int number_of_nodes) {
    g.number_of_nodes = number_of_nodes;
    // Alloco una matrice number_of_nodes x number_of_nodes
    g.adjMatrix = new int *[number_of_nodes];
    for (int i = 0; i < number_of_nodes; i++) {
        g.adjMatrix[i] = new int[number_of_nodes];
        // Setto ogni entry a 0
        // questo perché se una entry è 0 allora l'arco i->j non esiste.
        for (int j = 0; j < number_of_nodes; j++) {
            g.adjMatrix[i][j] = 0;
        }
    }
}

void fill_graph(graph &g, const char *file_path) {
    fstream in;
    in.open(file_path, ios::in);
    if (in.fail()) {
        cerr << "File does not exists" << endl;
        exit(1);
    }
    int number_nodes;
    in >> number_nodes;

    // Creo un grafo vuoto di dimensione number_of_nodes x number_of_nodes
    init(g, number_nodes);

    int node1, node2;
    // setto a 1 la entry corrispondente all'arco node1->node2
    // così facendo faccio si che si crei il suddetto arco
    while (in >> node1 >> node2) {
        g.adjMatrix[node1][node2] = 1;
    }
    in.close();
}

void print_graph(graph &g) {
    for (int i = 0; i < g.number_of_nodes; i++) {
        cout << i << " -> [";
        for (int j = 0; j < g.number_of_nodes; j++) {
            if (g.adjMatrix[i][j]) {
                cout << j << ", ";
            }
        }
        cout << "]" << endl;
    }
}

void dealloc(graph& g){
    for (int i = 0; i < g.number_of_nodes; i++){
        delete [] g.adjMatrix[i];
    }
    delete [] g.adjMatrix;
}

void init(set &s) {
    s.arrayList = new int[s.buffer_length];
}

void dealloc(set& s){
    delete [] s.arrayList;
}

bool empty(set &s) {
    return s.current_size == 0;
}

bool full(set &s) {
    return s.current_size == s.buffer_length;
}

int find_index(set &s, const int value) {
    int index = 0;
    while (s.arrayList[index] < value && index < s.current_size){
        index++;
    }
    return index;
}

void expand(set &s) {
    cout << "\nExpanding set" << endl;
    // Alloco un nuovo array dell'attuale dimesione del set * il fattore di espansione
    int *new_array_list = new int[(int) (s.buffer_length * s.EXPANSION_FACTOR)];
    // Copio il vecchio array in quello nuovo
    for (int i = 0; i < s.current_size; i++) {
        new_array_list[i] = s.arrayList[i];
    }
    delete[] s.arrayList;
    s.arrayList = new_array_list;
    // Aggiorno la dimensione massima del set
    s.buffer_length = (int) (s.buffer_length * s.EXPANSION_FACTOR);
};

void shrink(set &s){
    // Analogo all'expansion ma dimezzando la lunghezza massima
    cout << "\nShrinking set" << endl;
    int *new_array_list = new int[(int) (s.buffer_length / 2)];
    for (int i = 0; i < s.current_size; i++) {
        new_array_list[i] = s.arrayList[i];
    }
    delete[] s.arrayList;
    s.arrayList = new_array_list;
    s.buffer_length = (int) (s.buffer_length / 2);
}

void insert(set &s, int value) {
    if (empty(s)){
        // Se vuoto inserisco l'elemento e
        // incremento il numero di elementi al suo interno 
        s.arrayList[0] = value;
        s.current_size++;
    } else {
        // Per definizione, se un elemento è già presente nel set
        // questo non viene reinserito
        if (!contains(s, value)) {
            // Se il set è pieno lo espando
            if (full(s)) {
                expand(s);
            }
            // Trovo l'indice in cui inserire l'elemento
            int index = find_index(s, value);
            s.current_size++;
            // Faccio scorrere tutti gli elementi dopo l'indice trovato
            // a destra
            for (int i = s.current_size; i > index; i--) {
                s.arrayList[i] = s.arrayList[i-1];
            }
            // Inserirsco l'elemento
            s.arrayList[index] = value;
        }
    }
}

void remove_element(set &s, int value){
    // Se l'elemento è presente
    if (contains(s, value)){
        // Trovo la sua posizione
        int index = find_index(s, value);
        s.current_size--;
        // Faccio scorrere, gli elementi dall'indice trovato in poi, a sinistra
        for(int i = index; i < s.current_size ; i++){
            s.arrayList[i] = s.arrayList[i + 1];
        }
        // Se la dimensione è sotto la soglia di LOAD, dimezzo la dimansione
        if ((float) s.current_size / s.buffer_length < s.LOAD){
            shrink(s);
        }
    }
}

bool binary_search(set &s, const int value, int sx, int dx) {
    bool retval = false;
    if (sx > dx) {
        retval = false;
    } else {
        int mid = (sx + dx) / 2;
        if (s.arrayList[mid] == value) {
            retval = true;
        } else {
            if (value > s.arrayList[mid]) {
                retval = binary_search(s, value, mid + 1, dx);
            } else {
                retval = binary_search(s, value, sx, mid - 1);
            }
        }
    }
    return retval;
}

bool contains(set &s, int value) {
    bool retval = false;
    if (!empty(s)) {
        retval = binary_search(s, value, 0, s.current_size);
    }
    return retval;
}

void print_set(set &s) {
    cout << "\nMax length: " << s.buffer_length << endl;
    cout << "Current length: " << s.current_size << endl;
    cout << "Values: [";
    for (int i = 0; i < s.current_size; i++) {
        cout << s.arrayList[i] << ", ";
    }
    cout << "]" << endl;
}

void dependences(graph &g, int node) {
    set s;
    init(s);
    stack<int> st;
    st.push(node);
    while(!st.empty()){
        int curr_node = st.top(); //(primo elemento dello stack)
        st.pop(); // Rimuovo il primo elemento dallo stack
        if (!contains(s, curr_node)) {
            for (int i = 0; i < g.number_of_nodes; i++) {
                if (g.adjMatrix[curr_node][i] && !contains(s, i)) {
                    st.push(i);
                }
            }
        }
        insert(s, curr_node);
    }
    remove_element(s, node);
    cout << "Dependencies set:";
    print_set(s);
}