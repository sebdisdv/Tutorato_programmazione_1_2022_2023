#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
struct stringa{
    char s[101] = {};
};

int n_of_occurrencies(stringa arr[], int DIM, char e[])
{
    int retval = 0;

    for(int i = 0; i < DIM; i++){
        if(strcmp(e, arr[i].s) == 0)
            retval++;
    }

    return retval;
}

// L'esercizio di per sè è corretto ma assumi che in input ci siano al massino 100 stringhe! quando nella consegna è specificato che sono le stringhe "uniche" ad essere al massimo 100


int main(int argc, char * argv[]){
    if(argc != 3){
        cout << "Usage : ./a.out input.txt output.txt"; // usare cerr
        exit(0);
    }

    fstream input, output;
    input.open(argv[1], ios::in);
    if(input.fail()){
        cout << "File non trovato";
        exit(1);
    }
    output.open(argv[2], ios::out);
    if(output.fail()){
        cout << "File non trovato";
        exit(1);
    }

    stringa str[100] = {};
    stringa unchecked[100] = {};
    char buffer[101] = {};
    bool valid = true;
    int i = 0, u = 0;
    
    while(input >> buffer){
        // controllo minuscole
        for(int j = 0; buffer[j] != '\0'; j++){
            if(buffer[j] < 'a' || buffer[j] > 'z')
                valid = false;
        }

        // controllo già presente
        for(int j = 0; j < 100; j++){ // viene fatto anche per le stringhe non valide!
            if(strcmp(str[j].s, buffer) == 0){
                valid = false;
            }
        }

        if(valid){
            strcpy(str[i].s, buffer);
            i++;
        }
        strcpy(unchecked[u].s, buffer);
        u++;

        valid = true;
    }

    int len = strlen(str[0].s); 
    for(int z = 0;  len != 0; z++){
        output << str[z].s << ": " << n_of_occurrencies(unchecked, 100, str[z].s) << endl;
        len = strlen(str[z+ 1].s);
    }

    for(int z = 0; z < 100; z++){
        cout << unchecked[z].s << endl;
    }    

    input.close();
    output.close();

    return 0;
}