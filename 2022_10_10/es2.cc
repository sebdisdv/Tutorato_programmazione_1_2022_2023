/**
 * @file es2.cc
 * @author your name (you@domain.com)
 * @brief Esercizio: data una media iniziale e un numero di cfu iniziali, 
 * calcolare la nuova media dato in input il voto e i cfu del nuovo esame (sempre per puntatore, riferimento e valore)
 * @version 0.1
 * @date 2022-10-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

using namespace std;

float calcolaMediaValore(int voto, int crediti, float media, int creditiTot){
    media = ((media * creditiTot) + (voto * crediti)) / (creditiTot + crediti);
    return media;
}

void calcolaMediaRiferimento(int voto, int crediti, float &media, int &creditiTot){
    media = ((media * creditiTot) + (voto * crediti)) / (creditiTot + crediti);
    creditiTot += crediti;
}

void calcolaMediaPuntatore(int voto, int crediti, float *media, int *creditiTot){
    *media = ((*media * *creditiTot) + (voto * crediti)) / (*creditiTot + crediti);
    *creditiTot += crediti;
}

int main(){
    float media;
    int creditiTot, crediti, voto;
    cout << "Inserire media iniziale: ";
    cin >> media;
    cout << "Inserire totale crediti iniziale: ";
    cin >> creditiTot;
    cout << "Inserire voto: ";
    cin >> voto;
    cout << "Inserire crediti esame: ";
    cin >> crediti;
    media = calcolaMediaValore(voto, crediti, media, creditiTot);
    //calcolaMediaRiferimento(voto, crediti, media, creditiTot);
    //calcolaMediaPuntatore(voto, crediti, &media, &creditiTot);
    
    cout << "Nuova media: " << media;

    return 0;
}