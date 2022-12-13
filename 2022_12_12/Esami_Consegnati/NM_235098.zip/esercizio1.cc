#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// Peccato per l'assunzione sul numero di stringhe nel file di testo in input, perchè la logica era corretta

bool is_upper(char * s){
    bool res =true;
    for (int i=0; s[i]!='\0'; i++){
        if (s[i]<'a'||s[i]>'z'){
            res=false;
        }
    }
    return res;
}

void remove(char * s){
    strcpy(s, "0000"); 
}

int search(char m[][101], char *s, int i){
    int n=0;
    for (int j=0; j<i; j++){
        if (strcmp(m[j], s)==0){
            n++;
            if (n>1)
            remove(m[j]);
        }
    }
    return n;
}

int main(int argc, char ** argv){
    if (argc!=3){
        cerr<<"Errore numero di argomenti\n";
        exit(-1);
    }

    fstream in, out;

    in.open (argv[1], ios::in);
    if (in.fail()){
        cerr<<"Errore apertura file input\n";
        exit(-1);
    }
    out.open (argv[2], ios::out);
    if (out.fail()){
        cerr<<"Errore apertura file output\n";
        exit(-1);
    }

    char support[101][101];
    char buffer[101];

    int i=0;

    while ( in>>buffer){
        if (is_upper(buffer)){
            strcpy(support[i], buffer); // occhio che le stringhe uniche potevano essere massimo 100, non il numero delle loro occorrenze, per questo l'esercizio perde 3 punti
            i++;
        }
    }

    for (int j=0; j<i; j++){
        if (strcmp(support[j], "0000")!=0){
            out<<support[j]<<": "<<search(support, support[j], i)<<"\n";
        }
    }

    in.close();
    out.close();
    return 0;
}