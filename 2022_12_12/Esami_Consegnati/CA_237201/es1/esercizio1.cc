#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Occorrenza{
  int nVolte;
  char stringa[101];
};

int contains(Occorrenza occorrenze[], char * buffer, int cont);
bool controlloInput(char * buffer);

int main(int argc, char const *argv[]) {

  if(argc==3){

    fstream input,output;
    input.open(argv[1],ios::in);
    if(!input.fail()){
      output.open(argv[2],ios::out);
      if(!output.fail()){
        //Elaboro
        char buffer[101];
        Occorrenza occorrenze[100];
        int cont=0;

        while (input>>buffer) {
          //Controllo se è valida la stringa
          if(controlloInput(buffer)){
            int pos=contains(occorrenze,buffer,cont);
            if(pos==-1){
              //Aggiungo all'array
              strcpy(occorrenze[cont].stringa,buffer);
              occorrenze[cont].nVolte=1;
              cont++;
            }else{
              //aumento contatore nVolte
              occorrenze[pos].nVolte++;
            }
          }
        }
        //stampo su file
        for (int i = 0; i < cont; i++) {
          output<<occorrenze[i].stringa<<": "<<occorrenze[i].nVolte<<endl;
        }
        output.close();
        input.close();
      }else{
        cout<<"Errore apertura file output!"<<endl; // usare cerr
        output.close();
      }
    }else{
      cout<<"Errore apertura file input!"<<endl;
      input.close();
    }
  }else{
    cout<<"Errore input terminale!"<<endl;
  }
  return 0;
}

bool controlloInput(char * buffer){
  bool condizione=true;
  for (int i = 0; buffer[i]!='\0'; i++) {
    if(buffer[i]<'a'||buffer[i]>'z')
      condizione=false;
  }
  return condizione;
}

int contains(Occorrenza occorrenze[], char * buffer, int cont){
  int pos=-1;
  for (int i = 0; i < cont; i++) {
    if(strcmp(occorrenze[i].stringa,buffer)==0)
      pos=i;
  }
  return pos;
}
