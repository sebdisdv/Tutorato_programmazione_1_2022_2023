#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

bool is_valid(char * str) {
    bool valid = true;
    for (int i = 0; valid && str[i] != '\0'; ++i) {
        if (str[i] < 'a' || str[i] > 'z') valid = false; 
    }
    return valid;
}

int aleardy_found(char mat_str[][100], char * str, int n_strings_found) {
    int idx = -1;
    for (int i = 0; idx == -1 && i < n_strings_found; ++i) {
        if (strcmp(str, mat_str[i]) == 0) idx = i;
    }
    return idx;
}



int main(int argc, char ** argv) {
    const int DIM = 100;
    
    if (argc != 3) {
        cout << "Numero di argomenti non valido" << endl;
        exit(1);
    }
    fstream fi, fo;
    fi.open(argv[1], ios::in);
    fo.open(argv[2], ios::out);
    if (fi.fail() || fo.fail()) {
        cout << "Impossibile aprire un dei files" << endl;
        exit(2);
    } 
    char str[DIM];
    char mat_str[DIM][DIM];
    int freqs[DIM] = {};
    int i = 0;
    while (fi >> str) {
        int str_idx = aleardy_found(mat_str, str, i);
        if (str_idx != -1) freqs[str_idx]++;
        else if (is_valid(str)) {
            strcpy(mat_str[i], str);
            freqs[i]++;
            i++;
        }
    }
    for (int j = 0; j < i; ++j) {
        // cout << mat_str[j] << " " << freqs[j] << endl;
        fo << mat_str[j] << ": " << freqs[j] << endl;
    }

    fi.close();
    fo.close();



    return 0;
}
