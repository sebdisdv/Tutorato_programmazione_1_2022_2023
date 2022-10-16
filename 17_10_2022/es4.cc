#include <iostream>
#include <cctype>

using namespace std;

int calcolaSomma(int n){
    char c;
    int valore;
    cout << "Inserisci carattere maiuscolo o minuscolo: ";
    cin >> c;
    if(islower(c)){
        valore = 5;
    } else {
        valore = 10;
    }
    if(n > 1){
        valore += calcolaSomma(n-1);
    }
    return valore;

}

int main()
{
    int n;
    cout << "Inserire il numero di lettere: ";
    cin >> n;
    int somma = calcolaSomma(n);
    cout << "La somma vale: " << somma << endl;
    return 0;
}
