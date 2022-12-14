#include <iostream>
#include <string>

using namespace std;

// Add hereafter the declaration of compute_sum
int compute_sum(int n);
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
int sommacifre(int n, int res){
  if(n/10 == 0){
    return res+n;
  }else{
    return sommacifre(n/10, res+(n%10));
  }
}

int compute_sum_help(int n){
  if (n/10 == 0){
    return n;
  }else if(n%2 == 0){
    int s = sommacifre(n+10, 0);
    return compute_sum_help(s);
  }else{
    int s = sommacifre(n+1, 0);
    /*
    qui dovevi fare return di compute_sum_help(s), immagino sia una svista
    con il numero 99999992 ritorna 12, ma dovrebbe ritornare 4:
    -> 9+9+9+9+9+9+9+2 = 65 maggiore di 10 e dispari quindi sommo 1 
    -> 6+6 = 12 maggiore di 10 e pari quindi sommo 10 
    -> 2+2 = 4 minore di 10 quindi ritorno 4
    */
    return s;
  }
}

//Corretto
int compute_sum(int n){
  int s = sommacifre(n, 0);
  if (s/10 == 0){
    return s;
  }else{
    return compute_sum_help(s);
  }
}
// Add here above the definition of compute_sum
