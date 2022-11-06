#include <iostream>
#include <fstream>
using namespace std;

int main(){
    
    ifstream in ("input.txt");
    
    int count[256] = {};
    char c;

    if(in.fail()){
        cerr << "Errore nell'apertura del file" << endl;
        exit(-1);
    }

    while(in >> c){
        count[c] += 1;
    }

    for(int i = 0; i < 256; i++){
        if(count[i] > 0){
            cout << "["<< (char) i << "] -> " << count[i] << endl;
        }
    }

    in.close();
    
    return 0;
}