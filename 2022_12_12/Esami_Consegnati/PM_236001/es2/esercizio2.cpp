#include <iostream>
#include <string>

using namespace std;

// Add hereafter the declaration of compute_sum
int compute_sum(int);
int sum(int, int, int, int);
int pow(int, int);
int findEsp(int, int);
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
//Ok
int compute_sum(int num){
  int maxesp = findEsp(num, 0);
  int somma = sum(num, maxesp, 0, 0);
  if(somma < 10){
    return somma;
  }
  if(somma%2 == 0){
    somma = compute_sum(somma+10);
  }
  else{
    somma = compute_sum(somma+1);
  }
  return somma;
}
// Add here above the definition of compute_sum
// non capisco le tue intenzioni, funziona ma per "fortuna"
int sum(int num, int maxesp, int esp, int somma){
  if(esp > maxesp){
    return 0;
  }
  int cifra = (num % pow(10, esp)) - somma;
  if(esp != 1){
    cifra = cifra / pow(10, esp-1);
  }
  //cout << "pow: " << pow(10, esp-1);
  //cout << " cifra: " << cifra << " somma: " << somma << " esp: " << esp<<endl;
  return cifra + sum(num, maxesp, esp+1, somma+cifra);
}

int pow(int b, int e){
  if(e < 0) return 1; // la condizione è sbagliata, andava e==0, non calcola la potenza correttamente
  if(e == 1) return b;
  return b * pow(b, e-1);
}

int findEsp(int num, int esp){
  if(pow(10, esp) > num){
    return 0;
  }
  return 1 + findEsp(num, esp+1);
}