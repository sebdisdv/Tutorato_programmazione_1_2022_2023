/*
Creare una funzione che ricevuto un numero restituisce la somma delle cifre del numero 
se questa è minore di 10, il risultato della ri-applicazione della funzione sulla somma 
delle cifre del numero altrimenti.

Esempi: f(15)=1+5=6, 
f(392)=f(14)=f(5)=5 dove 3+9+2=14 e 1+4=5.

*******************************************************************************/
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
    if(somma<10){
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
    int risultato = calcolaRisultato(numero);
    cout << "f("<<numero<<")=" << risultato << endl;
    return 0;
}