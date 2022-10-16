#include <iostream>
using namespace std;

int calcolaSomma(int n){
    int valore;
    valore = n%10;
    n = n/10;
    if(n > 0){
        valore += calcolaSomma(n);
    }
    return valore;
}

int calcolaRisultato(int n)
{
    int somma = calcolaSomma(n);
    if(somma < 10){
        return somma;
    }
    else{
        return calcolaRisultato(somma);
    }
}

int main()
{
    int numero;
    cout << "Inserisci un numero intero positivo: ";
    cin >> numero;
    cout << "f(" << numero << ")=" << calcolaRisultato(numero) << endl;
    return 0;
}