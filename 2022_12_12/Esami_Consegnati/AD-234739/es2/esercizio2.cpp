#include <iostream>
#include <string>

using namespace std;

// Add hereafter the declaration of compute_sum
int compute_sum(int n);

void sum(int n, int *m, int *sum);
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
int compute_sum(int n) {

  int s;
  int m = 0;
  sum(n, &m, &s);

  cout << s << endl;

  if (s < 10) return s;

  if ((s%2) == 0)
    return compute_sum(s + 10);
  else 
    return compute_sum(s + 1);
      
}

// questa funzione non fa la somma richiesta, 
// sarebbe dovuta essere essa stessa ricorsiva per scorrere tutte le cifre di "n" e sommarle man mano
// dato che l'esercizion non fa ciò che era richiesto, il punteggio è nullo
void sum(int n, int *m, int *sum) {

  std::cout << n << std::endl;

  if (n != 0) {
    *m=n%10;    
    sum=sum+*m;    
    n=n/10;    
  }
}
// Add here above the definition of compute_sum
