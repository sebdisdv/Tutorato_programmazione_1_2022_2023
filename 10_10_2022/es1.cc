#include <iostream>
using namespace std;


float** alloc_matrix(const int row, const int col){
    float** matrix;
    matrix = new float*[row];
    for(int i = 0; i < row; i++){
        matrix[i] = new float[col];
    }
    return matrix;
}

void init_matrix(float** m, const int row, const int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << "M[" << i << "][" << j << "] = ";
            cin >> m[i][j];
        }
    }
}

void print_matrix(float** m, const int row, const int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}

void dealloc_matrix(float** m,const int row){
    for(int i = 0; i < row; i++){
        delete[] m[i];
    }
    delete[] m;
}

void swap_vars(float& n1, float& n2){
    float temp = n1;
    n1 = n2;
    n2 = temp;
}

void swap_row(float** m, const int row, const int col, const int row1, const int row2){
    if (row1 < row && row2 < row){
        for (int i = 0; i < col; i++){
            swap_vars(m[row1][i], m[row2][i]);
        }
    } else {
        cerr << "Row index is wrong" << endl;
    }
}

void multiply_row(float** m, const int row, const int col, const int row_to_multiply, float factor){
    for(int i = 0; i < col; i++){
        m[row_to_multiply][i] *= factor;
    }
}

void subtrack_rows(float** m, const int row, const int col, const int r1, const int r2){
    for(int i = 0; i < col; i++){
        m[r1][i] -= m[r2][i];
    }
}

void print_menu(){
    cout << "'p' -> print matrix" << endl;
    cout << "'q' -> quit" << endl;
    cout << "'s' -> swap rows" << endl;
    cout << "'m' -> multiply row" << endl;
    cout << "'d' -> subtrack rows" << endl;
}



int main(){
    float** m;
    int r=3, c=3;
    m = alloc_matrix(r,c);
    init_matrix(m, r,c);
    

    char in;
    int r1, r2;
    float f;
    do{
        print_menu();
        cin >> in;
        switch (in)
        {
        case 'p':
            print_matrix(m, r, c);
            break;
        case 'q':
            dealloc_matrix(m, r);
            break;
        case 's':
            cout << "Row1= ";
            cin >> r1;
            cout << "\nRow2= ";
            cin >> r2;
            swap_row(m, r, c, r1, r2);
            break;
        case 'm':
            cout << "Row: ";
            cin >> r1;
            cout << "\nfactor: ";
            cin >> f;
            multiply_row(m, r, c, r1, f);
            break;
        case 'd':
            cout << "Row1= ";
            cin >> r1;
            cout << "\nRow2= ";
            cin >> r2;
            subtrack_rows(m, r, c, r1, r2);
            break;
        default:
            cout << "Wrong input !" << endl;
            break;
        }
    } while (in != 'q');


    return 0;
}