#include <iostream>
#include "fstream"
#include "cstring"

using namespace std;

// per convenzione un nome di tipo che inizia col la lettera maiuscola è riservato per le classi e non per le struct, ma non è un errore 
struct Parola {
    char p[101];
    unsigned int n;
};

bool checkValid(const char *first) {
    while (*first != '\0') {
        if (*first < 'a' || *first > 'z') {
            return false;
        }
        first++;
    }
    return true;
}

void insert(const char parola[101], Parola all[100], unsigned int &parole) {
    for (int i = 0; i < parole; i++) {
        cout << "Comparing " << parola << " " << all[i].p << endl;
        if (strcmp(parola, all[i].p) == 0) {
            all[i].n++;
            return;
        }
    }
    strcpy(all[parole].p, parola);
    all[parole].n = 1;
    parole++;
}

// io qui terrei argc e argv come nomi degli argomenti del main
int main(int n, char *s[]) {
    if (n != 3) {
        cout << "Input errato" << endl; // usare cerr per stampare a video gli errori
        return 1; // usare exit() quando il programma deve terminare per un errore
    }
    fstream out(s[2], ios::out);
    fstream in(s[1], ios::in);
    if (out.fail() || in.fail()) {
        cout << "Errore con file" << endl; // vedi sopra
        return 1; // vedi sopra
    }

    Parola all[100];
    unsigned int parole_uniche = 0;
    char temp[101];
    while (in >> temp) {
        //cout << temp << " " << (checkValid(temp) ? "valida" : "non valida") << endl;
        if (checkValid(temp)) {
            cout << temp << endl;
            insert(temp, all, parole_uniche);
        }
    }
    bool first = true; // non capisco a cosa serva questa variabile
    for (int i = 0; i < parole_uniche; i++) {
        if (first) {
            first = false;
        } else {
            out << endl;
        }
        out << all[i].p << ": " << all[i].n;
    }


    // Ti sei dimenticato di chiudere gli stream di input e output!

    return 0;
}
