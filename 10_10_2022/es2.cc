#include <iostream>

using namespace std;

int fibonacci(int n){
    if (n == 0 || n == 1){
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main(){
    int limite;
    cout << "Limite: ";
    cin >> limite;
    for(int i = 0; i < limite; i++){
        cout << fibonacci(i) << endl;
    }

    return 0;
}