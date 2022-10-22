#include <iostream>
using namespace std;

#define DIM 5
#define MAX 10
#define MIN 0

void prod_matr(int m1[][DIM], int m2[][DIM], int res[][DIM]) {
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            res[i][j] = 0;
            for (int k = 0; k < DIM; k++) {
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

void init(int matrix[][DIM]){
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            matrix[i][j] = rand() % (MAX - MIN + 1) + MIN;
        }
    }
}

void print_matrix(int matrix[][DIM]){
    cout << endl;
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            cout << matrix[i][j] <<"\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int m1[DIM][DIM], m2[DIM][DIM], res[DIM][DIM];
    init(m1);
    init(m2);
    prod_matr(m1, m2, res);
    print_matrix(m1);
    print_matrix(m2);
    print_matrix(res);
}
