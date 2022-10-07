/**
 * @file es4.cc
 * @author Chiara
 * @brief Dato in input un numero n dall'utente, in maniera ricorsiva chiedere all'utente di inserire una lettera per n volte 
 * e, sapendo che le lettere in maiuscolo valgono 10 mentre quelle in minuscolo valgono 5, calcolare e stampare a video la somma totale.
 * @version 0.1
 * @date 2022-10-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

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
