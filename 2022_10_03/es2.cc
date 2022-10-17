#include <iostream>

using namespace std;

int main(){
    bool A, B;

    cout << "A\tB\t(A->B) or ((B -> !A) and !A)\n";

    A = false;
    B = false;

    cout << A << "\t" << B << "\t" << ((!A || B) || ((!B || !A) && !A)) << endl;

    B = true;

    cout << A << "\t" << B << "\t" << ((!A || B) || ((!B || !A) && !A)) << endl;

    A = true;
    B = false;

    cout << A << "\t" << B << "\t" << ((!A || B) || ((!B || !A) && !A)) << endl;

    A = true;
    B = true;

    cout << A << "\t" << B << "\t" << ((!A || B) || ((!B || !A) && !A)) << endl;

    return 0;
}