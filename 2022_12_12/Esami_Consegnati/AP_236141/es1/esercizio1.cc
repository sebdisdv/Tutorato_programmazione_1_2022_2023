#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


struct parola{
    char parola[100];
    bool stampato;
};

bool isValid(char string[]){
    bool valid = true;
    for(int i=0; string[i] != '\0'; i++){
        if(!(string[i] >= 'a' && string[i] <= 'z')){
            valid = false;
        }
    }
    return valid;
}

int cont(char string[] , parola array[], int i){
    int cont = 0;
    for(int j=0; j<=i; j++){
        if(strcmp(array[j].parola, string)==0){
            array[j].stampato = true;
            cont++;
        }
    }
    return cont;

}
int main(int argc, char* argv[]){
    if(argc != 3){
        cout << "Usage: ./a.out <file_input> <file_output>"; // usare cerr
        exit(1);
    }
    fstream in, in2, out; // perchè due stream di input?
    in.open(argv[1], ios::in);
    if(in.fail()){
        cout << "Errore apertura file " << argv[1] << endl;
        exit(2);
    }
    in2.open(argv[1], ios::in); // hai già aperto in e poi in2 non lo controlli, non va bene
    out.open(argv[2], ios::out);
    if(out.fail()){
        cout << "Errore apertura file " << argv[2] << endl;
        in.close();
        exit(3);
    }

    parola array[100]; // qui assumi che nel file di testo ci siano al massimo 100 stringhe, quando sono le stringhe uniche ad essere al massimo 100!
    char buffer[101] = {};
    int i = 0;
    while(in2 >> buffer){
        if(isValid(buffer)){
            strcpy(array[i].parola, buffer);
            array[i].stampato = false;
            i++;
        }
    }
    int j=0;
    while(in >> buffer){
        if(isValid(buffer)){
            if(array[j].stampato == false)
                cout << buffer << ": "<<  cont(buffer, array, i) << endl; // non stampi nel file di output
            j++;
        }
    }


    in.close();
    in2.close();
    out.close();
    return 0;
}

