#include <iostream>
using namespace std;

void reverse_print(int v[], int i){
    if (i > 0){
        cout << v[i - 1] << " ";
        reverse_print(v, i - 1);
    } 
}

int main(){
    int v[] = {1, 2, 3, 4, 5};
    reverse_print(v, 5);
    return 0;
}