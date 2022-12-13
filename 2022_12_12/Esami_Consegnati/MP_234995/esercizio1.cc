#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

bool isValid(char word[]);

int main(int argc, char * argv[]){
    if (argc != 3){
        cout << "Error. The correct input is: ./a.out <inputFile> <outputFile>" << endl;
        exit(1);
    }
    fstream in, out;
    in.open(argv[1], ios::in);
    if(!in){
        cout << "Input file does not exist, or an error occured" << endl;
        exit(1);
    }
    out.open(argv[2], ios::out);
    if(!out){
        cout << "Error while opening/creating output file" << endl;
        exit(1);
    }
    // -------------------------------
    char * unique[100];
    int counters[100];
    int idxUnique = 0;
    char word[100] = "\0";

    // Funziona fino al controllo di validita'
    while(in >> word){
        if(isValid(word)){

            int i = 0;
            cout << strcmp(word, unique[i]) << endl; 
            while (i < idxUnique && strcmp(word, unique[i]) != 0){
                i++;
            }
            
            cout << strcmp(word, unique[i]) << endl; 
            if(strcmp(word, unique[i]) == 0){
                counters[i]++;
            }else{
                unique[i] = new char[100];
                strcpy(unique[idxUnique], word);
                counters[idxUnique] = 1;
                idxUnique++;
            }
        }
    }
    cout << unique[0] << endl;

    // Output scrittura
    for(int i=0;i<idxUnique;i++){
        out << "<" << unique[i] << "> : <" << counters[i] << ">" << endl;
    } 

    //--------------------------------
    in.close();
    out.close();
    return 0;   
}

bool isValid(char word[]){
    for(int i = 0; word[i] != '\0'; i++){
        if(word[i] < 'a' || word[i] > 'z'){
            return false;
        }
    }
    return true;
}