#include <iostream>
using namespace std;


int count_couple(int n){
    if (n < 10){
        return 0;
    } else {
        int c1 = n%10;
        int n1 = n/10;
        int c2 = n1%10;
        if (c1 == c2){
            return 1 + count_couple(n1);
        } else {
            return count_couple(n1);
        }
    }
}


int main(){
    int n;
    cout << "Inserire un numero: ";
    cin >> n;
    cout << "Numero di coppie di cifre uguali: " << count_couple(n) << endl;
}