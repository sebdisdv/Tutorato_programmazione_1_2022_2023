#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_SEQ = 100;
const int MAX_LEN = 101;

bool lowercase(char*string);

int main(int argc, char*argv[]){

    if(argc!=3){
        cerr<<"Wrong number of arguments: ./a.out input.txt output.txt"<<endl;
        exit(1);
    }

    fstream in,ou;

    in.open(argv[1],ios::in);
    if(in.fail()){
        cerr<<"Input file issue (it might not exist)"<<endl;
        exit(2);
    }
    ou.open(argv[2],ios::out);
    if(ou.fail()){
        cerr<<"Output file issue"<<endl;
        exit(3);
    }

    char words[MAX_SEQ][MAX_LEN];
    int occur[100];
    int elements = 0;
    char stringa[MAX_LEN];
    bool stored;

    while(in>>stringa){
        if(lowercase(stringa)){
            stored = false;
            int i;
            for(i=0; i<MAX_SEQ && i<elements && !stored; i++){
                if(strcmp(stringa,words[i])==0){
                    stored = true;
                }
            }
            if(!stored){
                strcpy(words[elements],stringa);
                occur[elements]++;
                elements++;
            }
            else{
                occur[i-1]++;
            }
        }
    }

    for(int i=0; i<elements; i++){
        ou<< words[i] <<": "<<" "<< occur[i] <<endl;
    }


    in.close();
    ou.close();
    return 0;
}
bool lowercase(char*string){
    bool lowercase = true;
    for(int i=0; string[i]!='\0' && lowercase; i++){
        if(!('a'<=string[i] && string[i]<='z')){
            lowercase = false;
        }
    }
    return lowercase;
}