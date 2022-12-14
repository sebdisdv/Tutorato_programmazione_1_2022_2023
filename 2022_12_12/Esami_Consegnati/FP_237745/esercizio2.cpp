#include <iostream>
#include <string>

using namespace std;

// Add hereafter the declaration of compute_sum
int compute_sum(int num);

//Ok, volendo con "num<10 -> return num", potevi fare una chiamata in meno
int sommanumero(int num)
{
    if (num == 0)
    return 0;//indenta bene, soprattutto se non metti le parentesi
    return (num % 10 + sommanumero(num / 10));
}
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
int compute_sum(int num){
    num = sommanumero(num);
    if ((num >= 10) && ((num % 2) == 0)){
      num +=10;
      compute_sum(num);
    }
    else if ((num >= 10) && ((num % 2) != 0)){
      num +=1;
      compute_sum(num);
    }
    else{
      return num;
    }
}
// Add here above the definition of compute_sum
