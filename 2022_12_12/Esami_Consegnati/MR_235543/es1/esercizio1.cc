#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX_LENGHT = 100; // non era permesso l'uso di variabili globali, ma visto che è una constante si può sorvolare

// La soluzione che hai proposto va bene, anche se leggere per ogni parola l'intero file di testo è un po' uno spreco di tempo
// si poteva risolvere leggendolo solo una volta, ma non lo conto come errore

bool is_valid(const char *string);
bool contains(char **strings, const char *string);
int how_many(const char *filename, const char *string);

int main(int argc, char *argv[]){
    if(argc != 3){
        cerr << "Numero di elementi non corretto!\n";
        exit(-1);
    }

    char **strings = new char*[MAX_LENGHT];
    int index = 0;
    char buffer[MAX_LENGHT];
    fstream input, output;

    for(int i = 0; i < MAX_LENGHT; i++)
        strings[i] = new char[MAX_LENGHT];

    //read
    input.open(argv[1], ios::in);

    if(!input.fail()){
        while(input >> buffer){
            //se una stringa e' valida e non e' gia' stata letta la inserisco nell'array
            if(is_valid(buffer) && !contains(strings, buffer)){
                strcpy(strings[index], buffer);
                index++;
            }
        }
    }else{
        cerr << "Errore aprendo file input!\n";
        exit(-1);
    }
    input.close();

    //write
    output.open(argv[2], ios::out);

    if(!output.fail()){
        //per ogni stringa nell'array conto le occorrenze nel file di input e stampo l'output nel rispettivo file
        for(int i = 0; i < MAX_LENGHT && strlen(strings[i]) != 0; i++){
            output << strings[i] << ": " << how_many(argv[1], strings[i]) << endl;
        }
    }else{
        cerr << "Errore aprendo file output!\n";
        exit(-1);
    }

    output.close();
    // manca la deallocazione di strings!
    return 0;
}

//dice se una parola è valida o meno
bool is_valid(const char *string){
    for(int i = 0; i < MAX_LENGHT && string[i] != '\0'; i++){
        if(string[i] < 'a' || string[i] > 'z')
            return false;
    }

    return true;
}

//ritorna true se una parola è già stata letta, altrimenti false
bool contains(char **strings, const char *string){
    for(int i = 0; i < MAX_LENGHT; i++)
        if(strcmp(strings[i], string) == 0)
            return true;
    
    return false;
}

//conta le ripetizioni di una parola nel file di input
int how_many(const char *filename, const char *string){
    fstream input;
    input.open(filename, ios::in);
    char buffer[MAX_LENGHT];
    int counter = 0;

    if(!input.fail()){
        while(input >> buffer){
            if(strcmp(buffer, string) == 0)
                counter++;
        }
    }else{
        cerr << "Errore contando le occorrenze di una parola!\n";
        exit(-1);
    }
    input.close();

    return counter;
}