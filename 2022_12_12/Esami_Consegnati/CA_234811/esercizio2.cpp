#include <iostream>
#include <string>

using namespace std;

// Add hereafter the declaration of compute_sum
int compute_sum ( int n );
int somma_cifre ( int n, int p );

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
int compute_sum ( int n )
{
    int s = 0;
    s = somma_cifre ( n, s );
    if ( s<10 )
    {
        return s;
    }
    else if ( s%2 == 0 )
    {
        compute_sum ( s+10 );
    }
    else
    {
        compute_sum ( s+1 );
    }
}
int somma_cifre ( int n, int p )
{
    if ( n == 0 )
    {
        return p;
    } 
    else
    {
        p += n%10;
        n /= 10 ;
        somma_cifre ( n, p );
    }
}

// Add here above the definition of compute_sum