#include <iostream>
#include <string>

using namespace std;

// Add hereafter the declaration of compute_sum
int compute_sum(int);
int calcolaSomma(int);
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
int calcolaSomma(int n){
    int valore;
    valore = n%10;
    n = n/10;
    if(n > 0){
        valore += calcolaSomma(n);
    }
    return valore;
}

int compute_sum(int n){
    int somma = calcolaSomma(n);
    if(somma < 10){
        return somma;
    } else if(somma % 2 == 0){
        return compute_sum(somma+10);
    } else{
        return compute_sum(somma+1);
    }
}
// Add here above the definition of compute_sum