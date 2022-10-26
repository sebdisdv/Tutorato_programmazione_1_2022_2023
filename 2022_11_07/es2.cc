#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

bool is_palindroma_rec(char str[], int i, int j){
    if (i < j){
        return str[i] == str[j] && is_palindroma_rec(str, i+1, j-1);
    } else {
        return true;
    }
}

bool is_palindroma(char str[]){
    return is_palindroma_rec(str, 0, strlen(str) - 1);
}

int main(int argc, const char* argv[]){
    
    if(argc != 2){
        cerr << "File non passato in input\n";
        exit(1);
    }
    
    ifstream in (argv[1]);
    char str[32];

    if(in.fail()){
        cerr << "Errore nell'apertura del file\n";
        exit(1);
    }

    while(in >> str){
        cout << str << " è palindroma? " << (is_palindroma(str) ? "Yes" : "Nope" ) << endl;
    }

    in.close();

    return 0;
}