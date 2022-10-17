#include <iostream>

using namespace std;

int main(){
    //srand(time(NULL));
    int g1_tiro1, g1_tiro2;
    int g2_tiro1, g2_tiro2;

    g1_tiro1 = rand() % 6 + 1;
    g1_tiro2 = rand() % 6 + 1;
    g2_tiro1 = rand() % 6 + 1;
    g2_tiro2 = rand() % 6 + 1;

    int max_g1, min_g1;
    int max_g2, min_g2;

    // Ordiniamo i lanci del primo giocatore
    max_g1 = g1_tiro1;
    if (max_g1 < g1_tiro2) {
        max_g1 = g1_tiro2;
    }
    
    min_g1 = g1_tiro1;
    if (min_g1 > g1_tiro2) {
        min_g1 = g1_tiro2;
    }

    // Ordiniamo i lanci del secondo giocatore
    max_g2 = g2_tiro1;
    if (max_g2 < g2_tiro2) {
        max_g2 = g2_tiro2;
    }

    min_g2 = g2_tiro1;
    if (min_g2 > g2_tiro2) {
        min_g2 = g2_tiro2;
    }

 
    cout << "Lanci giocatore 1 (attaccante): " << g1_tiro1 << " " << g1_tiro2  << endl;
    cout << "Lanci giocatore 2 (difensore): " << g2_tiro1 << " " << g2_tiro2  << endl;

    cout << "Lanci ordinati giocatore 1 (attaccante): " << min_g1 << " " << max_g1 << endl;
    cout << "Lanci ordinati giocatore 2 (difensore): " << min_g2 << " " << max_g2 << endl;

    int vittorie_g1=0, vittorie_g2=0;

    if (min_g2 >= min_g1){
        vittorie_g2++;
    } else {
        vittorie_g1++;
    }

    if (max_g2 >= max_g1){
        vittorie_g2++;
    } else {
        vittorie_g1++;
    }

    if (vittorie_g1 > vittorie_g2){
        cout << "Vince il giocatore 1 con " << vittorie_g1 << " vittorie" << endl;
    } else {
        if (vittorie_g1 == vittorie_g2){
            cout << "La partita si è conclusa con un pareggio!" << endl;
        } else {
            cout << "Vince il giocatore 2 con " << vittorie_g2 << " vittorie" << endl;
        }
    }

    return 0;
}
