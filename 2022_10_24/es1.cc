#include <iostream>
#include <cmath>
#include <algorithm> // for C++14
//#include <numeric> // for C++17

using namespace std;

#define MAX 10
#define MIN 1

const int COL = 3;
const int ROW = 3;


void reduce_fraction(int* v){
    int gcd;
    do{
        gcd = __gcd(v[0], v[1]);
        v[0] /= gcd;
        v[1] /= gcd;
    } while(gcd != 1);
}

void print_fraction(int v[]){
    cout << v[0] << "/" << v[1];
}

void dif_fraction(int* f1, int* f2){
    int mcm = (f1[1] * f2[1]) / __gcd(f1[1], f2[1]);
    f1[0] = (f1[0] * (mcm/f1[1])) - (f2[0] * (mcm/f2[1]));
    f1[1] = mcm;
    reduce_fraction(f1);
}

void swap(int* f1, int* f2){
    int* t = f2;
    f2 = f1;
    f1 = t;
}

void init(int matrix[][COL][2]){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            matrix[i][j][0] = rand() % (MAX - MIN + 1) + MIN;
            matrix[i][j][1] = rand() % (MAX - MIN + 1) + MIN;
            reduce_fraction(matrix[i][j]);
        }
    }
}

void swap_rows(int matrix[][COL][2], int row1, int row2){
    for(int j = 0; j < COL; j++){
        swap(matrix[row1][j], matrix[row2][j]);
    }
}

void print_matrix(int matrix[][COL][2]){
    cout << endl;
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            print_fraction(matrix[i][j]);
            cout << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void dif_rows(int matrix[][COL][2], int row1, int row2){
    for(int i = 0; i < COL; i++){
        dif_fraction(matrix[row1][i], matrix[row2][i]);
    }
}

void mul_row(int matrix[][COL][2], int row, int lambda){
    for(int i = 0; i < COL; i++){
        matrix[row][i][0] *= lambda;
        reduce_fraction(matrix[row][i]);
    }
}

void print_menu(){
    cout << "'p' -> print matrix" << endl;
    cout << "'q' -> quit" << endl;
    cout << "'s' -> swap rows" << endl;
    cout << "'m' -> multiply row" << endl;
    cout << "'d' -> subtrack rows" << endl;
}

ostream& operator << (ostream& os, int* v){
    os << v[0] << "/" << v[1];
    return os;
}

int main(){
    srand(time(NULL));
    int m[ROW][COL][2];
    init(m);
    char in;
    int r1, r2, lambda;
    do{
        print_menu();
        cin >> in;
        switch (in)
        {
        case 'p':
            print_matrix(m);
            break;
        case 's':
            cout << "Row1= ";
            cin >> r1;
            cout << "\nRow2= ";
            cin >> r2;
            if (!(r1 < 0 || r1 >= ROW || r2 < 0 || r2 >= ROW)) {
                swap_rows(m, r1, r2);
            } else {
                cout << "Wrong row index !" << endl;
            }
            break;
        case 'm':
            cout << "Row: ";
            cin >> r1;
            cout << "\nlambda: ";
            cin >> lambda;
            if (!(r1 < 0 || r1 >= ROW)) {
                mul_row(m, r1, lambda);
            } else {
                cout << "Wrong row index !" << endl;
            }
            break;
        case 'd':
            cout << "Row1= ";
            cin >> r1;
            cout << "\nRow2= ";
            cin >> r2;
            if (!(r1 < 0 || r1 >= ROW || r2 < 0 || r2 >= ROW)) {
                dif_rows(m, r1, r2);
            } else {
                cout << "Wrong row index !" << endl;
            }
            break;
        case 'q':
            cout << "Quitting\n";
            break;
        default:
            cout << "Wrong input !" << endl;
            break;
        }
    } while (in != 'q');
    return 0;
}