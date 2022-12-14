#include <iostream>
#include <string>

using namespace std;

// Add hereafter the declaration of compute_sum
int compute_sum(int);
int somma_cifre(int);
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
int compute_sum(int num)
{
  int s_cifre = somma_cifre(num);
  int res = 0;

  if (s_cifre < 10)
  {
    res = s_cifre;
  }
  else if (s_cifre % 2 == 0)
  {
    res = compute_sum(s_cifre + 10);
  }
  else
  {
    res = compute_sum(s_cifre + 1);
  }

  return res;
}

//Corretto
int somma_cifre(int num)
{
  int res = 0;

  if (num > 10)
  {
    res = num % 10 + somma_cifre(num / 10);
  }
  else
  {
    res = num % 10;
  }
  
  return res;
}
// Add here above the definition of compute_sum
