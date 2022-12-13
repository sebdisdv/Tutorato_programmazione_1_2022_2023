#include <iostream>
#include <fstream>
#include <cstring>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 100

using namespace std;

typedef struct {
    int count;
    char str[MAX_WORD_LENGTH];
} word;

// rinominato "count" con "pippo" perchè al compilatore non piaceva dato che è il nome di una funzione di una libreria di sistema
int pippo = 0; // non era permesso l'utilizzo di variabili di tipo globale, per questo l'esercizio viene annullato
// la logica era giusta, peccato per le variabili globali, fai più attenzione a leggere la consegna
word words[MAX_WORDS];

bool check_str(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] < 'a' || str[i] > 'z')
            return false;
    }
    return true;
}

void add_to_list(char *str) {

    // Check if string already exists into the list
    for (int i = 0; i < pippo; i++) {
        if (strcmp(str, words[i].str) == 0) {
            words[i].count++;
            return;
        }
    }

    // Str not found into the list
    words[pippo].count = 1;
    strcpy(words[pippo].str, str);

    pippo++;
}

int main(int argc, char **argv) {


    if (argc != 3) { //OK
        cerr << "Numero di argomenti errato!" << endl;
        return 1;
    }

    fstream input;
    ofstream output;

    // Opening input
    input.open(argv[1], ios::in);
    if (!input.is_open()) { // devi usare input.fail()
        cerr << "Impossibile aprire il file di input!" << endl;
        return 1; 
    }

    output.open(argv[2]);
    if (!input.is_open()) { // occhio al copia e incolla, qui ci va output, non input. Devi usare output.fail()
        cerr << "Impossibile aprire il file di output!" << endl;
        return 1;
    }

    char str[100];

    while (input >> str) {
        if (check_str(str)) add_to_list(str);
    }

    for (int i = 0; i < pippo; i++) {
        output << words[i].str << ": " << words[i].count << endl;
    }

    return 0;
}