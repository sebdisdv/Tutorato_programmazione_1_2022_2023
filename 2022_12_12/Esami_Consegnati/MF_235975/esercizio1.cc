#include<iostream>
#include<fstream>
#include <cstring>

using namespace std;

bool isValid(const char* buff){
    for(int i=0; i<strlen(buff); i++){
        if(buff[i]<'a' || buff[i]>'z'){
            return false;
        }
    }
    return true;
}

int alreadyFound(char valid[100][100], int validFound, const char* toFind){
    for(int i = 0; i<validFound; i++){
        if(strcmp(valid[i], toFind) == 0){
            return i;
        }
    }
    return -1;
}

int main(int argc, char * argv []) {


  if (argc != 3) {
    cout << "Numero errato di parametri" << endl;
    exit(1);
  }
  
  fstream input, output;
  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);
  
  if (input.fail() || output.fail()) {
    cout << "Errore nell'apertura degli stream!" << endl; // usare cerr
    // manca exit()
  }
  
    char buff[100] = {};
    char valid[100][100] = {};
    int validNumber[100];
    int validFound = 0;

    while(input>>buff){
        if(isValid(buff)){
            int found = alreadyFound(valid, validFound, buff);
            if(found == -1){
                strcpy(valid[validFound], buff);
                validNumber[validFound]++;
                validFound++;
            }
            else{
                validNumber[found]++;
            }
        }
    }

    for(int i=0; i<validFound; i++){
        cout<<valid[i]<<": "<<validNumber[i]<<endl; // non li stai scrivendo nel file di output
    }


  input.close();
  output.close();
  return 0;  
}