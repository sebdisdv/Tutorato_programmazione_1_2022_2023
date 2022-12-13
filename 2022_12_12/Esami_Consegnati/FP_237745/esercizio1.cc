#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char * argv[]){
    
    if (argc != 3){
        cout << "Usage: ./a.out <input.txt> <output.txt>" << endl;
        exit(1);
    }
    
    fstream input, output;

    input.open(argv[1], ios::in);
    if (input.fail()){
        cout << "Errore nell'apertura del file " << argv[1] << endl;
        exit(2);
    }

    output.open(argv[2], ios::out);
     if (output.fail()){
        cout << "Errore nell'apertura del file " << argv[2] << endl;
        exit(3);
    }

    char stringa[101];
    char tmp[101];
    int lenght = 0; 
    int conta = 0;
    int compari = 0;
    bool a;

    while(input >> stringa){
    
    lenght = strlen(stringa);

    for(int i=0; i<lenght; i++){
       if(stringa[i] >= 'a' && stringa[i] <= 'z'){
            a = true;
        }
          else{
            a = false;
          }
          if (a == true){
          strcpy(tmp, stringa);
            if(strcmp(stringa, tmp) == 0){
               for(int i=0; i<lenght; i++){
                  if (stringa[i] == tmp[i]){
                    conta += 1;
                    }
                }
            if (conta == lenght) {
                compari += 1;
                }
            }
        }
          
    }
    output << tmp << ": " << compari << endl;
    }

    input.close();
    output.close();

    return 0;
}