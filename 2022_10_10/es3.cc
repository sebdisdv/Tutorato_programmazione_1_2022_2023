#include <iostream>

using namespace std;

void swap(int& n1, int& n2){
    int temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}

void riordina(int& n1, int& n2, int& n3){
    if (n3 <= n2) swap(n2, n3);
    if (n3 <= n1) swap(n1, n3);
    if (n2 <= n1) swap(n1, n2);

}

int main(){
    int n1, n2, n3;
    cout << "Inserire tre valori: ";
    cin >> n1 >> n2 >> n3;
    cout << n1 << " " << n2 << " " << n3 << endl;
    riordina(n1, n2, n3);
    cout << n1 << " " << n2 << " " << n3 << endl;

    return 0;
}