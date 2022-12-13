#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

void inserisci(char m[100][100], char * buffer, int * occorrenze, int &dim);
bool controllo(char * buffer);

int main(int argc, char ** argv){
    
    if(argc != 3){
        cout << "Usage: ./esercizio1.out <input> <output>" << endl;
        exit(0);
    }

    fstream input, output;

    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);

    if(input.fail() || output.fail()){
        cout << "file non aperti" << endl;
        exit(2);
    }

    char m[100][100];
    int occorrenze[100]={0};
    char buffer[100];
    int dim = 0;
    
    while(input >> buffer){
        if(controllo(buffer))
            inserisci(m, buffer, occorrenze, dim);
    }

    for(int i=0; i<dim; i++){
        output << m[i] << ": " << occorrenze[i] << endl;
    }
    input.close();
    output.close();
    return 0;
}

void inserisci(char m[100][100], char * buffer, int * occorrenze, int &dim){

    bool presente = false;
    for(int i=0; i<dim; i++){
        if(strcmp(m[i], buffer) == 0){
            occorrenze[i]++;
            presente = true;
        }
    }

    if(presente == false){
        strcpy(m[dim], buffer);
        occorrenze[dim]++;
        dim++;
    }

    return;
}

bool controllo(char * buffer){
    bool valido = true;
    for(int i=0; i<strlen(buffer); i++){
        if(!('a'<=buffer[i] && buffer[i]<='z')){
            valido = false;
        }
    }

    return valido;
}