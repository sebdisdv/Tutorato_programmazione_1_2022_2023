#include <iostream>
#include <string>

using namespace std;

// Add hereafter the declaration of compute_sum

int pow(int base, int powerRaised);
int compute_sum(int num);

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

int pow(int base, int powerRaised)
{
    if (powerRaised != 0)
        return (base*pow(base, powerRaised-1));
    else
        return 1;
}

int compute_sum(int num)
{
  int cifra;
  int numero_cifre = 0;
  int somma_cifre = 0;

  int multiplo_10 = 1;
  int x = 0;      // x è l'esponente di 10 alla x
  // non era concesso utilizzare cicli, porre maggiore attenzione nella lettura della consegna
  // l'esercizio viene quindi considerato nullo
  while (multiplo_10 <= num)   // calcolo del numero totale di cifre
  {
      numero_cifre++;
      x++;
      multiplo_10 = pow(10, x);
  }
  
  int n = num;     // nel for si userà la variabile n per preservare il contenuto di 'numero'
  for (x = (numero_cifre - 1); x >= 0; x--)
  {
      multiplo_10 = pow(10, x);
      cifra = n / multiplo_10;
      n -= cifra * multiplo_10;
      somma_cifre += cifra;
  }

  if (somma_cifre < 10)
  {
    return somma_cifre;
  }
  else if (somma_cifre % 2 == 0)
  {
    return compute_sum(somma_cifre + 10);
  }
  else
  {
    return compute_sum(somma_cifre + 1);
  }
}

// Add here above the definition of compute_sum
