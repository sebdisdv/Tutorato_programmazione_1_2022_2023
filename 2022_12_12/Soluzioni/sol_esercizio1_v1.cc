#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

// Massimo numero di caratteri di una parola
const int MAX_LENGTH = 100;

// Massimi elementi singoli
const int MAX_WORDS = 100;

int main(int argc, char * argv[]) {

  // Controllo se gli argomenti sono corretti
  if (argc != 3) {
    cout << "Usage: esercizio1 <input> <output>" << endl;
    exit(1);
  }

  fstream input, output;
  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);

  // Controllo di essere riuscito ad aprire i file correttamente
  if (input.fail() || output.fail()) {
    cout << "Errore nell'apertura dei file" << endl;
    exit(1);
  }

  // Array che conterrà tutte le parole lette
  char database[MAX_WORDS][MAX_LENGTH];

  // Array che conterrà il conteggio di tutte le parole lette
  int contatore[MAX_WORDS];

  // Buffer di lettura
  char buffer[MAX_LENGTH];

  // Contatore delle parole lette
  int parole_lette = 0;

  // Leggo il file, riga per riga. Ogni parola estratta
  // viene messa nel database
  while(input >> buffer) {

      // Controllo se la parola letta sia valida
      bool valida = true;
      for (unsigned int i=0; i<strlen(buffer) && valida; i++) {
        if (!(buffer[i] >= 'a' && buffer[i] <= 'z')) {
          valida = false;
        }
      }

      // Se la parola è valida, allora continuo con l'esecuzione
      if (valida) {
        // Controllo se la stringa è presente nel database
        // Se non è presente, l'aggiungo, mentre se è presente
        // allora incremento solo il suo conteggio
        bool found = false;
        for (int i=0; i<parole_lette && !found; i++) {
          if (strcmp(buffer, database[i]) == 0) {
            contatore[i] += 1;
            found = true;
          }
        }

        // Se la parola non è stata trovata, allora la salvo nel database
        if (!found) {
          strcpy(database[parole_lette], buffer);
          contatore[parole_lette] = 1;
          parole_lette++;
        }
      }
  }

  // Scrivo nel file di output il totale di ogni parola
  for (int i=0; i<parole_lette; i++) {
    output << database[i] << ": " << contatore[i] << endl;
  }

  input.close();
  output.close();

  return 0;
}