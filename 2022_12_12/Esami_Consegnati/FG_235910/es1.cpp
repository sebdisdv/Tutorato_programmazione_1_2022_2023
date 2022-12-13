#include <iostream>
#include "fstream"
#include "cstring"

using namespace std;
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

int main(int n, char *s[]) {
    if (n != 3) {
        cout << "Input errato" << endl;
        return 1;
    }
    fstream out(s[2], ios::out);
    fstream in(s[1], ios::in);
    if (out.fail() || in.fail()) {
        cout << "Errore con file" << endl;
        return 1;
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
    bool first = true;
    for (int i = 0; i < parole_uniche; i++) {
        if (first) {
            first = false;
        } else {
            out << endl;
        }
        out << all[i].p << ": " << all[i].n;
    }

    return 0;
}
