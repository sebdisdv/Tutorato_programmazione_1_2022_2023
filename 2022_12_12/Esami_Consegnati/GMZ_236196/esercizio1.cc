#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
    const int MAX_DIM = 100;
    const int MAX_DIM1 = 100;

    if (argc < 3) {
        cerr << "Sono necessari 3 argomenti" << endl;
        return 1; // usare exit()
    }

    fstream in, out;
    in.open(argv[1], ios::in);
    if (in.fail()) {
        cerr << "Apertura di " << argv[1] << " fallita" << endl;
        return 1;
    }

    char stringhe[MAX_DIM1][MAX_DIM];
    int times[MAX_DIM1];

    char buffer[MAX_DIM];
    int i = 0;
    while (in >> buffer) {
        bool valida = true;

        int j = 0;
        while (buffer[j] != '\0') {
            if (buffer[j] >= 'a' && buffer[j] <= 'z') {
            }
            else {
                valida = false;
            }
            j++;
        }

        if (valida) {
            bool aggiunto = false;
            for (int k = 0; k < MAX_DIM1; k++) {
                if (strcmp(buffer, stringhe[k]) == 0) {
                    times[k]++;
                    aggiunto = true;
                }
            }

            if (!aggiunto) {
                strcpy(stringhe[i], buffer);
                times[i]++;
                i++;
            }
        }
    }

    out.open(argv[2], ios::out);
    if (out.fail()) {
        cerr << "Apertura di " << argv[2] << " fallita" << endl;
        return 1;
    }

    for (int j = 0; j < i; j++) {
        out << stringhe[j] << ": " << times[j] << endl;
    }

    in.close();
    out.close();

    return 0;
}
