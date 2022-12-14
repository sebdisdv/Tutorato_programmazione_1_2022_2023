#include <iostream>
#include <string>

using namespace std;

// Add hereafter the declaration of compute_sum
int compute_sum(int num);
int compute_sum_aux(int num, int ris);
// Add here above the declaration of compute_sum

int main(int argc, char ** argv) {
  if (argc != 2) {
    cerr << "Usage: " << argv[0] << " int " << endl;
    exit(1);
  }

  int num;
  try {
    string ss(argv[1]);
    num = stoi(ss);
  } catch (out_of_range) {
    cerr << "Unable to convert the given string to an integer" << endl;
    cerr << "String of the given number = " << argv[1] << endl;
    cerr << "Converted integer = " << num << endl;
    exit(1);
  }
  if (0 > num) {
    cerr << "Expecting an integer greater or equal to 0" << endl;
    exit(1);
  }

  cout << "The initial integer is: " << num << endl;
  cout << "The value of compute_sum(" << num << ") = " << compute_sum(num) << endl;
}


// Add hereafter the definition of compute_sum
//Corretto
int compute_sum(int num){
    int ris = 0;
    return compute_sum_aux(num, ris);
}

//Corretto
int compute_sum_aux(int num, int ris){
    int ultima_cifra = num % 10;


    // se ho ragginto l'ultima cifra
    if((num - ultima_cifra) == 0){ //bastava anche "num < 10"
        ris += num; // ris diventa la somma cercata
        if(ris < 10){
            return ris;
        } else{
            if((ris % 2 == 0)){ // se è pari 
                ris += 10;
                return compute_sum(ris);
            } else{ // se è dispari
                ris += 1;
                return compute_sum(ris);
            }
        }
    }
    // se ho raggiunto l'ultima cifra

    ris += ultima_cifra;
    num = num / 10;
    return compute_sum_aux(num, ris);
}
// Add here above the definition of compute_sum