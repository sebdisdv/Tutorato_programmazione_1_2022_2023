#include <iostream>

using namespace std;

int mcd_rec(int n1, int n2){
    int retval;
    if (n2 == 0){
        retval = n1;
    } else {
        retval = mcd_rec(n2, n1%n2);
    }
    return retval;
}

int main(){
    int n1, n2;
    cout << "Inserire due numeri interi positivi: ";
    cin >> n1 >> n2;
    cout << "MDC= " << mcd_rec(n1, n2) << endl;
}