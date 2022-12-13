#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

bool check(char parola[101]) {
    int l = strlen(parola);

    for (int i = 0; i < l; i++) {
        if (!(parola[i] >= 'a' && parola[i] <= 'z')) {
            return false;
        }
    }

    return true;
}


int main(int argc, char* argv[]) {
    //check
    if (argc != 3) {
        cerr<<"Numero di argomenti non valido"<<endl;
        cerr<<"Uso: <file_input> <file_output>"<<endl;
        return -1; // usare exit()
    }


    //apertura stream
    fstream in;
    in.open(argv[1], ios::in);
    if (in.fail()) {
        cerr<<"Errore nell'apertura della stream di input"<<endl;
        in.close();// non serve
        return -1;
    }

    fstream out;
    out.open(argv[2], ios::out);
    if (out.fail()) {
        cerr<<"Errore nell'apertura della stream di output"<<endl;
        in.close(); // ok
        out.close(); // non serve
        return -1;
    }

    //legge
    char parole[100][101];
    int presenza[100];
    int i = 0;

    while (in>>parole[i]) { // occhio che le stringhe potrebbero essere più di 100! sono quelle uniche a essere massimo 100
        if (check(parole[i])) {
            presenza[i] = 1;
            i++;
        }
    }

    //parsa
    for (int k = 0; k < i; k++) {
        for (int q = 0; q < k; q++) {
            if (!strcmp(parole[k], parole[q]) && strcmp(parole[q], "")) { // strcmp() ritorna 0 se le due stringhe sono uguali e non True attento!
                presenza[q] += presenza[k];
                strcpy(parole[k], "");
            }
        }
    }


    //stampa
    for (int k = 0; k < i; k++) {
        if (strcmp(parole[k], "")) { // qui ad esempio non funziona correttamente
            out<<parole[k]<<": "<<presenza[k]<<endl;
        }
    }

    in.close();
    out.close();

    return 0;
}