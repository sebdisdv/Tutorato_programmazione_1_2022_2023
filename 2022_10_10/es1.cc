/**
 * @file Es1.cc
 * @author your name (you@domain.com)
 * @brief Esercizio: scrivi una funzione che cambi il prezzo intero in quello scontato data la percentuale di sconto 
 * da fare con passaggio per valore, per riferimento e per puntatore
 * @version 0.1
 * @date 2022-10-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

using namespace std;

float calcolaScontoValore(float prezzo, int sconto){
    prezzo -= (prezzo*sconto)/100;
    return prezzo;
}

void calcolaScontoRiferimento(float &prezzo, int sconto){
    prezzo -= (prezzo*sconto)/100;
}

void calcolaScontoPuntatore(float *prezzo, int sconto){
    *prezzo -= (*prezzo*sconto)/100;
}

int main(){
    float prezzo;
    int sconto;
    cout << "Inserire prezzo: ";
    cin >> prezzo;
    cout << "Inserire sconto: ";
    cin >> sconto;
    prezzo = calcolaScontoValore(prezzo, sconto)
    //calcolaScontoRiferimento(prezzo, sconto);
    //calcolaScontoPuntatore(&prezzo, sconto);
    cout << "Prezzo: " << prezzo;

    return 0;
}