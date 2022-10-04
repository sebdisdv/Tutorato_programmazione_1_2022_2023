/* Prodotto matriciale:
 - Input dimensione r1 e c1; input r2 c2.
 - Allocazione dinamica delle due matrici.
 - Inizializzazione con interi random tra -2 e +6.
 - Calcolo prodotto matriciale tra le due (con controllo sulle dimensioni subito dopo l'input).
 - Stampa prodotto.
*/

#include <cstdlib>
#include <iostream>
#include <random>
#include <time.h>

#define MIN -2
#define MAX 6

using namespace std;

int** alloc(const int r, const int c);
void init(int** m, const int r, const int c);
int** prod_matr(int** m1, int** m2, const int r1, const int c1, const int r2, const int c2);
void print_matrix(int** m, const int row, const int col);
void dealloc(int** m, const int r);

int main() {
    srand(time(NULL));

    int** m1, **m2, **prod;
    int r1, r2;
    int c1, c2;

    cout << "Prodotto matriciale" << endl;
    cout << "-------------------" << endl;
    cout << "Inserire dimensione r1 (numero righe prima matrice): ";
    cin >> r1;
    cout << "Inserire dimensione c1 (numero colonne prima matrice): ";
    cin >> c1;
    cout << "Inserire dimensione r2 (numero righe seconda matrice): ";
    cin >> r2;
    cout << "Inserire dimensione c2 (numero colonne seconda matrice): ";
    cin >> c2;

    if (r1 < 1 || c1 < 1 || r2 < 1 || c2 < 1) {
        cout << "Le dimensioni delle matrici devono essere >= 1." << endl;
    } else if (c1 != r2) {
        cout << "Per eseguire il prodotto matriciale il numero di colonne della prima matrice (c1) deve essere uguale al numero di righe della seconda (r2)." << endl; 
    } else {
        m1 = alloc(r1, c1);
        m2 = alloc(r2, c2);

        init(m1, r1, c1);
        init(m2, r2, c2);

        prod = prod_matr(m1, m2, r1, c1, r2, c2);

        cout << "M1" << endl;
        print_matrix(m1, r1, c1);
        cout << endl;

        cout << "M2" << endl;
        print_matrix(m2, r2, c2);
        cout << endl;

        cout << "Prodotto" << endl;
        print_matrix(prod, r1, c2);

        dealloc(m1, r1);
        dealloc(m2, r2);
        dealloc(prod, r1);
    }

    return 0;
}

int** alloc(const int r, const int c) {
    int** m = new int*[r];
    for (int i = 0; i < r; i++) m[i] = new int[c];
    return m;
}

void init(int** m, const int r, const int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            m[i][j] = rand() % (MAX - MIN + 1) + 1;
        }
    }
}

int** prod_matr(int** m1, int** m2, const int r1, const int c1, const int r2, const int c2) {
    int** prod = alloc(r1, c2);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            prod[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                prod[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    return prod;
}

void print_matrix(int** m, const int row, const int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}

void dealloc(int** m, const int r) {
    for (int i = 0; i < r; i++) {
        delete m[i];
    }
    delete m;
}