#include <iostream>
#include <string>

using namespace std;

// Add hereafter the declaration of compute_sum
int compute_sum(const int num);
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
int compute_sum_aux(const int num) {
  // Base case num < 10
  if (num < 10) return num;
  // We extract the right most number
  int sum = num % 10;
  // We extract the left most numbers but the one extracted above
  int rem = num / 10;
  // We sum the right most numbers with the result of the recursive call
  sum += compute_sum_aux(rem);
  // We return the result
  return sum;
}

int compute_sum(const int num) {
  // We calculate the sum of all the numbers composing the given
  // integer
  int sum = compute_sum_aux(num);
  // If the sum is above 10, depending on the value either we sum 10
  // or 1 to the current sum and we recurse.
  if (sum >= 10) {
    if (sum % 2 == 0) {
      sum = compute_sum(sum + 10);
    } else {
      sum = compute_sum(sum + 1);
    }
  }
  // cout << endl << "compute_sum(" << num << ") = " << sum << endl;
  // At the end we simply return the computed number
  return sum;
}

// Add here above the definition of compute_sum
