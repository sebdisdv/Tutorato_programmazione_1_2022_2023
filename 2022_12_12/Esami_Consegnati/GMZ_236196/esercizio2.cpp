#include <iostream>
#include <string>

using namespace std;

int compute_sum_aux(int, int);
int compute_sum(int);

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
int compute_sum(int num) {
    return compute_sum_aux(num, 0);
}

//Corretto
int compute_sum_aux(int num, int res) {
    if (num < 10) {
        res += num;
        if (res < 10) {
            return res;
        }
        else if (res % 2 == 0) {
            return compute_sum_aux(res + 10, 0);
        }
        else {
            return compute_sum_aux(res + 1, 0);
        }
    }

    res += num % 10;
    num /= 10;
    return compute_sum_aux(num, res);
}

// Add here above the definition of compute_sum
