#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
using namespace std;

int converti(char * numero);
int calcola(int a, int b, char op);

int main(int argc, char * argv[]) {

  if (argc != 3) {
    cout << "Usage: ./esercizio1 <input> <output>" << endl;
    exit(1);
  }

  fstream input, output;
  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);

  if (input.fail() || output.fail()) {
    cout << "Errore nell'apertura dei file" << endl;
    exit(1);
  }

  char a[11], b[11], op;
  // Leggo direttamente ogni riga. Poichè i valori sono separati
  // da spazi, posso leggerli direttamente con lo stream di input.
  while(input >> a >> op >> b) {

    int numero_a, numero_b;

    // Converto i valori da base-17 a base-10
    numero_a = converti(a);
    numero_b = converti(b);

    // Calcola il risultato dell'operazione
    output << calcola(numero_a, numero_b, op) << endl;
  }

  input.close();
  output.close();

  return 0;
}

int calcola(int a, int b, char op) {
    int risultato = 0;
    switch (op) {
      case '+':
        risultato = a + b;
        break;
      case '*':
        risultato = a * b;
        break;
      case '^':
        risultato = pow(a, b);
        break;
      default:
        cout << "Operazione non riconosciuta!" << endl;
        break;
    }
    return risultato;
}


int converti(char * numero) {

  int base = 1;
  int risultato = 0;

  // Iniziamo dal numero meno significativo (unità) e scorriamo
  // in avanti nell'array.
  for (int i=strlen(numero)-1; i>=0; i--) {

    if (numero[i] >= '0' && numero[i] <= '9') {
      risultato += (numero[i]-'0')*base;

    } else if (numero[i] >= 'A' && numero[i] <= 'G') {

      // Se il valore non è un numero, allora dobbiamo convertire
      // la lettera nel suo corrispondente valore intero.
      int valore = 10 + (numero[i]-'A');
      risultato += valore*base;

    }

    // Ad ogni iterazione, incremento la base. Questo equivale a scrivere
    // b^i nella sommatoria.
    base = base * 17;
  }

  return risultato;

}
