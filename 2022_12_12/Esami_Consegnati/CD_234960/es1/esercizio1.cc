#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct sequenza
{
    char s[101];
    int occ = 0;
};

bool lowercase(char s[101]);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cerr << "File avviato in maniera errata: ./esercizio1.out input.txt output.txt" << endl;
        exit(1);
    }

    ifstream input;
    ofstream output;
    char s[101] = {};
    sequenza sequenze[100] = {};
    int n_seq = 0;
    bool added;

    input.open(argv[1]);
    if (input.fail())
    {
        cerr << "Errore apertura file input" << endl;
        exit(2);
    }

    output.open(argv[2]);
    if (output.fail())
    {
        cerr << "Errore apertura file output" << endl;
        input.close();
        exit(3);
    }

    while (input >> s)
    {
        if (lowercase(s))
        {
            added = false;
            for (int i = 0; i < n_seq && !added; ++i)
            {
                if (strcmp(s, sequenze[i].s) == 0) // Sequenza già esistente
                {
                    added = true;
                    sequenze[i].occ++;
                }
            }

            if (!added) // Nuova sequenza
            {
                strcpy(sequenze[n_seq].s, s);
                sequenze[n_seq].occ = 1;
                n_seq++;
            }
        }
    }

    for (int i = 0; i < n_seq; ++i)
    {
        output << sequenze[i].s << ": " << sequenze[i].occ << endl;
    }

    input.close();
    output.close();
    return 0;
}

bool lowercase(char s[101])
{
    int len = strlen(s);
    bool result = true;

    for (int i = 0; i < len && result; ++i)
    {
        if (!(s[i] >= 'a' && s[i] <= 'z'))
        {
            result = false;
        }
    }

    return result;
}
