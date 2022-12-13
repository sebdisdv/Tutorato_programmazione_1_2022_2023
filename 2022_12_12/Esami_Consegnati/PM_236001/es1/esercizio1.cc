#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

bool checkLower(char*);
int isPresent(char[][100], char*, int);

int main(int argc, char* argv[]){
    if(argc != 3){
        cout << "Errore numero parametri" << endl; // usare cerr
        exit(-1);
    }
    fstream in;
    in.open(argv[1], ios::in);
    if(in.fail()){
        cout << "Errore apertura file input" << endl;
        in.close();
        exit(-1);
    }
    fstream out;
    out.open(argv[2], ios::out);
    if(out.fail()){
        cout << "Errore apertura file output" << endl;
        out.close();
        exit(-1);
    }

    char buff[100];
    char valid[100][100];
    int countV = 0;
    int count[100] = {};
    /*
    while(in >> buff){
        int index = isPresent(valid, buff, countV);
        if(index != -1){
            count[index]++;
        }
        else{
            if(checkLower(buff)){
                strcpy(valid[countV], buff);
                count[countV]++;
                countV++;
            }
        }
    }

    for(int i = 0; i < countV; i++){
        out << valid[i] << ": " << count[i] << endl;
    }*/
    
    while(in >> buff){
        int index = isPresent(valid, buff, countV);
        if(index != -1){
            count[index]++;
        }
        else{
            if(checkLower(buff)){
            strcpy(valid[countV], buff);
            count[countV]++;
            countV++;
        }
        }
    }

    for(int i = 0; i < countV; i++){
        out << valid[i] << ": " << count[i] << endl;
    }
    
    in.close();
    out.close();
    return 0;
}

int isPresent(char valid[][100], char* str, int validLen){
    for(int i = 0; i < validLen; i++){
        if(strcmp(valid[i], str) == 0){
            return i;
        }
    }
    return -1;
}

bool checkLower(char* str){
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] < 'a' || str[i] > 'z'){
            return false;
        }
    }
    return true;
}