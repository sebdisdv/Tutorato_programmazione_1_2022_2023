#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// L'esercizio chiedeva di contare quante volta una stringa compare nel file di inpit, cosa che tu non fai
// La logica è completamente sbagliata, solo i controlli sugli stream sono corretti

int main(int argc, char *argv[])
{

    if (argc != 3)
    {
        cout << "Usage: ./a.out <input.txt> <output.txt>" << endl; // usare cerr
        exit(1);
    }

    fstream input, output;

    input.open(argv[1], ios::in);
    if (input.fail())
    {
        cout << "Errore nell'apertura del file " << argv[1] << endl; // usare cerr
        exit(2);
    }

    output.open(argv[2], ios::out);
    if (output.fail())
    {
        cout << "Errore nell'apertura del file " << argv[2] << endl; // usare cerr
        exit(3);
    }

    char stringa[101];
    char tmp[101];
    int lenght = 0;
    int conta = 0;
    int compari = 0;
    bool a; // dare nomi significativi alle variabili

    while (input >> stringa)
    {

        lenght = strlen(stringa);

        for (int i = 0; i < lenght; i++) 
        {
            if (stringa[i] >= 'a' && stringa[i] <= 'z')
            {
                a = true;
            }
            else
            {
                a = false;
            }
            if (a == true) // a è un bool quindi basta scrivere if(a)
            {
                strcpy(tmp, stringa);
                if (strcmp(stringa, tmp) == 0) // questa condizione sarà sempre vera! perchè hai appena copiato in tmp, stringa, quindi per forza di cose saranno sempre uguali!
                {
                    for (int i = 0; i < lenght; i++)
                    {
                        if (stringa[i] == tmp[i]) 
                        {
                            conta += 1;
                        }
                    }
                    if (conta == lenght)
                    {
                        compari += 1;
                    }
                }
            }
        } 
        output << tmp << ": " << compari << endl;
    }

    input.close();
    output.close();

    return 0;
}