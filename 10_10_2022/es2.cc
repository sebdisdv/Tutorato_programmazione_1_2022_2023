/*
 - Input dimensione da tastiera
 - Allocazione dinamica di array di quella dimensione con controllo lunghezza > 0 e inizializzazione tramite interi random tra 1 e 10 (da gestire entrambe con due funzioni ad-hoc).
 - Calcolo della somma di tutti i numeri contenuti nell'array con funzione ricorsiva.
 - Stampa della lista e del prodotto calcolato con una funzione.
 - Deallocazione del vettore con funzione
*/

#include <cstdlib>
#include <iostream>
#include <random>
#include <time.h>

#define MAX 10

using namespace std;

int* alloc(const int dim);
void init(int* v, const int dim);
int sum(const int* l, int dim);
void print(const int* l, const int dim, const int sum_numb);
void dealloc(int* l);


int main() {
    srand(time(NULL));

    int* l;
    int dim, sum_numb;

    cout << "Inserire dimensione vettore: ";
    cin >> dim;

    if (dim <= 0) cout << "Errore, la dimensione del vettore deve essere > 0" << endl;
    else {
        l = alloc(dim);

        init(l, dim);

        sum_numb = sum(l, dim);
        
        print(l, dim, sum_numb);
        
        dealloc(l);
    }

    return 0;
}

int* alloc(const int dim) {
    int* l = new int[dim];

    return l;
}

void init(int* l, const int dim) {
    for (int i = 0; i < dim; i++) {
        l[i] = rand() % MAX + 1;
    }
}

int sum(const int* l, int dim) {
    int r;
    if (dim <= 0) {
        // Caso base: se dim == 0 non prosegue con la ricorsione
        r = 0;
    } else {
        // Ci sono ancora elementi nella lista, prendo il corrente.
        // Sommo quindi il risultato di sum togliend l'elemento corrente.
        r = l[dim - 1] + sum(l, dim - 1);
    }
    return r;
}

void print(const int* l, const int dim, const int sum_numb) {
    cout << "List: [";
    for (int i = 0; i < dim; i++) {
        cout << l[i];
        if (i < dim - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "Sum: " << sum_numb << endl;
}

void dealloc(int* l) {
    delete l;
}