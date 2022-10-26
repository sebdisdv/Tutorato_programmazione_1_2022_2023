#include <iostream>
using namespace std;

#define matrix int**
#define MAX 10
#define MIN 1

void init_vec(int v[], int length){
    for(int i = 0; i < length; i++){
        v[i] = rand() % (MAX - MIN + 1) + MIN;
    }
}

void print_matrix(matrix m, const int row, const int col){
    cout << endl;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

matrix alloc(const int row, const int col){
    matrix m;
    m = new int*[row];
    for(int i = 0; i < row; i++){
        m[i] = new int[col];
    }
    return m;
}

void dealloc(matrix m, const int row){
    for(int i = 0; i < row; i++){
        delete[] m[i];
    }
    delete[] m;
}

matrix transpose(matrix m, const int row, const int col){
    matrix res = alloc(col, row);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            res[j][i] = m[i][j];
        }
    }
    return res;
}

int main(int argc, char* argv[]){
    int row, col;
    
    cout << "Inserire dimensioni matrice(righe e colonne): ";
    cin >> row >> col;
    
    matrix m = alloc(row, col);

    for(int i = 0; i < row; i++){
        init_vec(m[i], col);
    }

    print_matrix(m, row, col);

    matrix m_t = transpose(m, row, col);

    print_matrix(m_t, col, row);

    dealloc(m, row);
    dealloc(m_t, col);

    return 0;

}