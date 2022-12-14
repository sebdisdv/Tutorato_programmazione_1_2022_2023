#include <iostream>
#include <string>

using namespace std;

// Add hereafter the declaration of compute_sum

int sum_digits(int n);
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

int sum_digits(int n) {
  int sum = 0;
  
  if (n > 9) {
    sum += sum_digits(n/10);
  }

  return sum + n%10;
}


int compute_sum(int n) {
  int sumdigits = sum_digits(n);

  if (sumdigits < 10) {
    return sumdigits;
  }

  if (sumdigits % 2 == 0) {
    compute_sum(sumdigits + 10);
  } else {
    compute_sum(sumdigits + 1);
  }
  /*
    leggere meglio i warning del compilatore, 
    questa funzione non sempre ritorna un intero, a volte finisce la sua esecuzione senza tornare nulla.
    esecuzione con 129 non corretta ad esempio
  */
}


// Add here above the definition of compute_sum
