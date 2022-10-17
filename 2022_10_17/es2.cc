#include <iostream>

using namespace std;

int fibonacci(int n){
    int val;
    if (n == 0 || n == 1){
        val = 1;
    } else {
        val = fibonacci(n - 1) + fibonacci(n - 2);
    }
    return val;
}

int main(){
    int limite;
    cout << "Limite: ";
    cin >> limite;
    for(int i = 0; i < limite; i++){
        cout << fibonacci(i) << " ";
        fflush(stdout);
    }
    cout << endl;
    return 0;
}