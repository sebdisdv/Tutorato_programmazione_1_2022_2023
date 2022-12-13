#include <iostream>
#include <fstream>
#include <cstring>

bool isValid(const char* str);

// Perfetto!

int main(int argc, char* argv[])
{
    if(argc != 3) {
        std::cerr << "Numero di parametri non valido!" << std::endl;
        return -1; // usare exit
    }

    std::fstream ifs;
    ifs.open(argv[1], std::ios::in);

    if(ifs.fail()) {
        std::cerr << "File di input non leggibile!" << std::endl;
        return -1;
    }

    std::fstream ofs;
    ofs.open(argv[2], std::ios::out);

    if(ofs.fail()) {
        std::cerr << "File di output non scrivibile!" << std::endl;
        ifs.close(); // non necessario
        return -1;
    }

    char word[101];
    char wordsList[100][101];

    int n = 0;
    int counter[100] = { 0 };

    while(ifs >> word) {
        bool control = false;
        
        if(isValid(word)) {
            int i = 0;
            for(; i < n && !control; ++i) {
                if(std::strcmp(word, wordsList[i]) == 0) {
                    control = true;
                    --i;
                }
            }

            if(!control) {
                std::strcpy(wordsList[n], word);
                ++counter[n];
                ++n;
            } else {
                ++counter[i];
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        ofs << wordsList[i] << ": " << counter[i] << std::endl;
    }

    ifs.close();
    ofs.close();

    return 0;
}

bool isValid(const char* str) {
    bool ret = true;

    for(int i = 0; str[i] != '\0'; ++i) { // potevi anche ciclare da i = 0 a i = strlen(str), visto che era permesso l'uso della funzione
        if(str[i] < 'a' || str[i] > 'z') {
            ret = false;
        }
    }

    return ret;
}