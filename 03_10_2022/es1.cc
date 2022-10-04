#include <iostream>

using namespace std;

int main(){
    int n1, n2;
    
    cout << "Inserire due numeri interi:\n";
    cin >> n1 >> n2;

    if (n1 % 2 == 0 && n2 % 2 == 0){
        cout << "Entrambi sono pari " << n1 + n2 << endl;
    } else {
        if ((n1 % 2 == 0 && n2 % 2 != 0) || (n1 % 2 != 0 && n2 % 2 == 0)){
            cout << "Uno è pari l'altro è dispari " << n1 * n2 << endl;
        } else {
            cout << "Entrambi sono dispari " << (float) (n1 - n2) / (n1 * n2) << endl;
        }
    }
    return 0;
}