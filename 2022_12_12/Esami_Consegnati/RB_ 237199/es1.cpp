#include <iostream>
#include <fstream>
#include <cstring>

#define DIM 100
using namespace std;

bool controllo_minuscole(char []);

int main(int argc, char const *argv[])
{
    if(argc != 3){
        cerr << "Error usage: ./a.out <input> <output>" << endl; 
        exit(1);
    }

    fstream in, out; 
    in.open(argv[1], ios::in);
    out.open(argv[2], ios::app); // andava usato ios::out
    if(!in.is_open()){ // andava usato in.fail()
        cerr << "Errore di apertura del file di input" << endl; 
        exit(2);
    }
    if(!out.is_open()){ // andava usato out.fail()
        cerr << "Errore di apertura del file di output" << endl; 
        exit(2);
    }

    char buffer[DIM+1]; 
    char db [DIM][DIM+1] = {};
    int db_values [DIM] = {};
    int righe_db = 0; 

    while (in >> buffer){
        if(buffer[0] == '\0'){ // non serve 
            break;
        }

        if(controllo_minuscole(buffer)){
            int f = 0; // era già memorizzata questa stringa? (0: no, 1: sì)

            for (int k = 0; k <= righe_db; k++){
                if(strcmp(db[k], buffer) == 0){
                    f = 1;
                    db_values[k] += 1;
                }
            }
            if(f == 0){ // quindi la stringa non era ancora memorizzata
                strcpy(db[righe_db], buffer); // la aggiungo alla matrice db e incremento l'indice delle righe
                db_values[righe_db] = 1; 
                righe_db += 1; 
            }
        }
    }
    
    for (int j = 0; j < righe_db; j++){
        out << db[j] << ": " << db_values[j] << endl; 
    }
    

    in.close();
    out.close();
    return 0;
}

bool controllo_minuscole(char a[]){
    bool minuscole = true;
    int i = 0; 
    while (a[i] != '\0' && minuscole){
        if(a[i] < 'a' || a[i] > 'z'){
            minuscole = false; 
        }
        i++; 
    }
    return minuscole; 
}