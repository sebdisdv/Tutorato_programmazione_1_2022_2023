#include <iostream>
#include <string>

using namespace std;

// Add hereafter the declaration of compute_sum

int compute_sum(int n);

// Add here above the declaration of compute_sum

int sum(int n);

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] << " int " << endl;
    exit(1);
  }

  int num;
  try
  {
    string ss(argv[1]);
    num = stoi(ss);
  }
  catch (out_of_range)
  {
    cerr << "Unable to convert the given string to an integer" << endl;
    cerr << "String of the given number = " << argv[1] << endl;
    cerr << "Converted integer = " << num << endl;
    exit(1);
  }
  if (0 > num)
  {
    cerr << "Expecting an integer greater or equal to 0" << endl;
    exit(1);
  }

  cout << "The initial integer is: " << num << endl;
  cout << "The value of compute_sum(" << num << ") = " << compute_sum(num) << endl;
}

// Add hereafter the definition of compute_sum

//Corretto
int compute_sum(int n)
{
  // if (n < 0)
  // {
  //   std::cerr << "Solo numeri positivi accettati" << std::endl;
  //   exit(1);
  // }
  n = sum(n);
  if (n < 10)
  {
    return n;
  }
  else if ((n & 1) == 0) {
    return compute_sum(n + 10);
  } else {
    return compute_sum(n + 1);
  }
}
// Add here above the definition of compute_sum

//Corretto
int sum(int n)
{
  if (n < 10) {
    return n;
  }
  else 
  {
    int digit = n % 10;
    n /= 10;
    return digit + sum(n);
  }
}