#include <iostream>
#include <fstream>
#include <cstring>
//author Velia B.

using namespace std;

int main(int argc, char * argv[]){
    //controllo se il numero degli argomenti in input sono definiti
    if(argc!=3){
        cerr << "Usage : not as <a.out> <input.txt> <output.txt>";
        exit(1);
    }

    //apertura file di input da cmd
    fstream input, output;
    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);

    //controllo se i file non sono stati aperti
    if(input.fail() || output.fail()){
        cerr << "File <input.txt> and/or <output.txt> didn't open";
        exit(2);
    }

    const int max_length = 100;
    const int max_words = 100;

    char buffer[max_length];
    char vocabolario[max_words][max_length];
    int contatore[max_words];
    int parole_lette = 0;

    while(input >> buffer){
        bool check = true;
        for(unsigned i=0; (i<strlen(buffer) && check); i++){
            if(buffer[i]>='A' && buffer[i]<='Z'){
                check = false;
            }
        }

        if(check){
            bool found = false;
            for(int i=0; i<parole_lette && !found; i++){
                if(strcmp(buffer, vocabolario[i]) == 0){
                    contatore[i]+= 1;
                    found = true;
                }
            }

            if(!found){
                strcpy(vocabolario[parole_lette], buffer);
                contatore[parole_lette] = 1;
                parole_lette++;
            }
        }
    }

    for(int i=0; i<parole_lette; i++){
        output << vocabolario[i] << " : " << contatore[i] << endl;
    }

    //chiusura file aperti
    input.close();    
    output.close();    
    cout << endl;
    return 0;
}