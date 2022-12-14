#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;


int main(int argc, char ** argv) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <input_file> <output_file> " << endl;
        exit(1);
    }

    fstream input, output;
    input.open( argv[1] , ios::in ) ;
    if (input.fail()) {
        cerr << "Errore nell'apertura del file di input" << endl;
        exit(2);
    }
    output.open( argv[2] , ios::out ) ;
    if (output.fail()) {
        cerr << "Errore nell'apertura del file di output" << endl;
        input.close() ;
        exit(3);        
    }
    
    char parole[100][101] ;
    char buffer[101] ;
    int occorrenze[100] = { } , j;
    bool valida , presente;
    for (int i = 0; input >> buffer && i < 100 ; i++ ) {
        valida = true;
        for ( int k = 0; k < 101 && valida && buffer[k]!='\0'; k++) {
            //cout << " buffer: " << buffer[k] ;
            if (!(buffer[k] >= 'a' && buffer[k] <= 'z')) {
                valida = false;
                //cout << "non valida" << buffer[k] << endl;
            }
        }
        if (valida) {
            presente = false;
            for (j=0; j<=i && !presente ; j++) {
                if (strcmp(buffer, parole[j])) {
                    presente = false;
                } else {
                    presente = true;
                }
            }
            if (presente) {
                occorrenze[j-1] ++ ;
            } else {
                strcpy( parole[i] , buffer) ;
                occorrenze[i] ++ ;
            }
        }
    }

    for (int i = 0; i < 100; i++) {
        if (occorrenze[i] != 0 ) {
            //cout << parole[i] << " : " << occorrenze[i] << endl;
            output << parole[i] << " : " << occorrenze[i] << endl;
        }
    }

    input.close();
    output.close();
    return 0;
}


