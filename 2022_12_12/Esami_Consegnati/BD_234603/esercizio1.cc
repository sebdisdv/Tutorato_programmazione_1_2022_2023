#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void clearString(char stringa[], int dim);
bool stringValid(char stringa[]);
bool inMatrix(char matrice[100][101], char stringa[101]);
int indMatrix(char matrice[100][101], char stringa[101]);

int main(int argc, char * argv[])
{
    if (argc != 3) //OK
    {
        cout << "Usage: ./a.out [file_input] [file_output]" << endl; //meglio usare cerr
        exit(1);
    }

    fstream read;
    read.open(argv[1], ios::in);
    if (read.fail()) //OK
    {
        cout << "Impossibile aprire il file " << argv[1] << endl; // meglio usare cerr
        exit(2);
    }

    fstream write;
    write.open(argv[2], ios::out);
    if (write.fail()) //OK
    {
        cout << "impossibile scrivere nel file " << argv[2] << endl; //meglio usare cerr
        exit(2);
    }

    char buffer[101] = ""; //non era necessario inizializzarlo
    char stringhe[100][101];
    int contStringhe[100];

    for (int i = 0; i < 100; i++)
    {
        contStringhe[i] = 0;
    }

    int i = 0;
    while (read >> buffer)
    {
        if (stringValid(buffer))
        {
            int indCont;
            if (!inMatrix(stringhe, buffer))
            {
                strcpy(stringhe[i], buffer);
                indCont = i;
                i++;
            }
            else
            {
                indCont = indMatrix(stringhe, buffer);
            }
            contStringhe[indCont]++;
        }

        clearString(buffer, 101);
    }
    read.close(); //OK

    //La condizione del for ti crea problemi, il "not" 
    //viene eseguito solo sull'elemento di sinistra rispetto al confronto "=="
    for (int i = 0; !(strcmp(stringhe[i], "")) == 0; i++) 
    {
        strcpy(buffer, stringhe[i]); //potevi scrivere direttamente "stringhe[i]" dentro a write
        // il file di output contiene valori non stampabili con conteggio a 0, per questo l'esercizio non verrà valutato sufficiente
        write << buffer << ": " << contStringhe[i] << endl;
        clearString(buffer, 101);
    }
    write.close(); //OK

    return 0;
}

void clearString(char stringa[], int dim) //inutile
{
    stringa[0] = '\0';
    for (int i = 1; i < dim; i++)
    {
        stringa[i] = 0;
    }
}

bool stringValid(char stringa[]) //OK
{
    for (int i = 0; stringa[i] != '\0'; i++) //ti era concesso usare strlen, ma va bene anche così
    {
        if (!('a' <= stringa[i] && stringa[i] <= 'z'))
        {
            return false;
        }
    }
    return true;
}

bool inMatrix(char matrice[100][101], char stringa[101])
{
    for (int i = 0; i < 100; i++)
    {
        if (strcmp(matrice[i], stringa) == 0)
        {
            return true;
        }
    }
    return false;
}

int indMatrix(char matrice[100][101], char stringa[101])
{
    for (int i = 0; i < 100; i++)
    {
        if (strcmp(matrice[i], stringa) == 0)
        {
            return i;
        }
    }
    return 0;
}