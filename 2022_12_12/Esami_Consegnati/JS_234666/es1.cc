#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct dato{
    char stringa[100];
    int occ;
};

bool isValida(char * stringa){
    int dim = strlen(stringa);
    bool valida = true;
    for(int i=0; i<dim && valida; i++){
        if((stringa[i]<'a') || (stringa[i]>'z')){
            valida = false;
        }
    }
    return valida;
}

int main(int argc, char * argv[]){

    if(argc != 3){
        cout << "Errore: numero parametri sbagliato" << endl;
        exit(1);
    }

    fstream in, out;

    in.open(argv[1], ios::in);
    out.open(argv[2], ios::out);

    if(in.fail() || out.fail()){
        cout << "Errore: impossibile aprire file" << endl;
        exit(1);
    }

    char stringa[100];
    dato *stringhe = new dato[100]; 

    int i = 0;
    bool trovato;
    
    while(in >> stringa){
        //cout << stringa << endl;
        if(isValida(stringa)){
            if(i == 0){
                strcpy(stringhe[i].stringa, stringa);
                stringhe[i].occ = 1;
                i++;
            }else {
                trovato = false;
                for(int j=0; j<i && (trovato==false); j++){
                    if(strcmp(stringhe[j].stringa, stringa)==0){
                        stringhe[j].occ++;
                        trovato = true;
                    }
                }
                if(!trovato){
                    strcpy(stringhe[i].stringa, stringa);
                    stringhe[i].occ = 1;
                    i++;
                }
            }
        }
    }

    for(int j=0; j<i; j++){
        out << stringhe[j].stringa << ": " << stringhe[j].occ << endl;
    }

    delete[] stringhe;

    in.close();
    out.close();


}