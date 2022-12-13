#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

bool verificaChar(const char *);

int main(int argc, char *argv[]){
    if(argc!=3){
        cerr<<"Usage: ./a.out input output"  << endl;
        exit(1);
    }

    fstream input, output;
    input.open(argv[1], ios::in);
    if(input.fail()){
        cerr << "Errore apertura file input" << endl;
        exit(1);
    }

    output.open(argv[2],ios::out);
    if(output.fail()){
        cerr << "Errore apertura file output" << endl;
        input.close();
        exit(1);
    }

    char buffer[101];
    char out[100][101];
    char unicit[100][101];
    int i=0;
    do{
        input>>buffer;
        if(verificaChar(buffer)){
            strcpy(out[i],buffer);
            ++i;
            cout<<buffer<<endl;
        }
    }while(!input.eof());

    int ind=0;
    for(int j=0; j<i; j++){
        int cont=0;
        bool unicita=true;
        for(int k=0; k<i; k++){
            if(!strcmp(out[j],out[k])){
                for(int n=0; n<ind;n++){
                    if(!strcmp(unicit[n],out[k])){
                        unicita=false;
                    }
                }
                if(unicita && cont==0){
                    strcpy(unicit[ind],out[j]);
                    ind++;
                    cont++;
                }
                else if(unicita){
                    cont++;    
                }                
            }
        }
        if(unicita){
            output << out[j] << ": "<<cont<<endl;
        }
    }

    input.close();
    output.close();
    return 0;
}

bool verificaChar(const char * str){
    for(int i=0; str[i]!='\0'; i++){
        if(str[i]>='A' && str[i]<='Z'){
            return false;
        }     
    }
    return true;
}



