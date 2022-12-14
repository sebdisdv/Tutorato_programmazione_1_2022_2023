#include <iostream>
#include <string>

using namespace std;

// Add hereafter the declaration of compute_sum
/*
int somma_cifre(int n){

    int totale = 0;

    if(n/10 == 0){
        totale = n;
    }
    else{
        totale += n%10 + somma_cifre(n/10);
    }

    if(totale>=10){
        return somma_cifre(totale);
    }

    return totale;
}
*/
int compute_sum(int x);
int sum_digits(int x);
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

int compute_sum(int x){
    if(x<10){ //Il controllo era da fare sulla somma delle cifre, non sul numero in input, per questo i risultati non sono corretti
        return x;//return della somma delle cifre di x non di x stesso
    }
    //Conviene mettere il risultato di "sum_digits" in una variabile per non chiamare tante volte una funzione ricorsiva
    else if(sum_digits(x)%2==0){
        return compute_sum(sum_digits(x)+10);
    }
    return compute_sum(sum_digits(x)+1);
}

//Corretto
int sum_digits(int x){
    if(x/10==0)
        return x;
    return x%10 + sum_digits(x/10);
}
// Add here above the definition of compute_sum
