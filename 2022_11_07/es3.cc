#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;



void codifica_rec(char s[], int i, const int len){
    if(i < len){
        if( isupper(s[i]) ){
            s[i] = '*';
        }
        codifica_rec(s, i+1, len);
    }
}

void codifica(char s[]){
    codifica_rec(s, 0, strlen(s));
}

int main(int argc, const char * argv[]){
    fstream in, out;
    char s[32];

    if(argc != 3){
        cerr << "File non passato in input\n";
        exit(1);
    }

    in.open(argv[1], ios::in);
    out.open(argv[2], ios::out);
    
    
    if(in.fail()){
        cerr << "Errore nell'apertura del file " << argv[1] << endl;
        exit(1);
    }

    while(in >> s){
        codifica(s);
        out << s << endl;
    }

    in.close();
    out.close();

    return 0;
}