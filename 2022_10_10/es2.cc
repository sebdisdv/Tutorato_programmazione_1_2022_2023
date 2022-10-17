#include <iostream>

using namespace std;

float calcolaMediaValore(int voto, int crediti, float media, int creditiTot){
    return ((media * creditiTot) + (voto * crediti)) / (creditiTot + crediti);
}

void calcolaMediaRiferimento(int voto, int crediti, float &media, int &creditiTot){
    media = ((media * creditiTot) + (voto * crediti)) / (creditiTot + crediti);
    creditiTot += crediti;
}

void calcolaMediaPuntatore(int voto, int crediti, float *media, int *creditiTot){
    *media = (((*media) * (*creditiTot)) + (voto * crediti)) / ((*creditiTot) + crediti);
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
    
    cout << "Nuova media: " << media << endl;

    return 0;
}