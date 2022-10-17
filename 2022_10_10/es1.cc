#include <iostream>

using namespace std;

float calcolaScontoValore(float prezzo, int sconto){
    return prezzo - (prezzo * sconto) / 100;
}

void calcolaScontoRiferimento(float &prezzo, int sconto){
    prezzo -= (prezzo * sconto) / 100;
}

void calcolaScontoPuntatore(float *prezzo, int sconto){
    *prezzo -= ((*prezzo) * sconto) / 100;
}

int main(){
    float prezzo;
    int sconto;
    cout << "Inserire prezzo: ";
    cin >> prezzo;
    cout << "Inserire sconto: ";
    cin >> sconto;
    prezzo = calcolaScontoValore(prezzo, sconto);
    //calcolaScontoRiferimento(prezzo, sconto);
    //calcolaScontoPuntatore(&prezzo, sconto);
    cout << "Prezzo: " << prezzo << endl;

    return 0;
}