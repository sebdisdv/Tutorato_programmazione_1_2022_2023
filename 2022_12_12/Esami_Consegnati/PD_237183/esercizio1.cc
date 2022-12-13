# include <iostream>
# include <fstream>
# include <cstring>

# define MAX_LEN 100

using namespace std;

bool isValid(char*);
int getIndexOf(char*[], int, char*);

int main(int argc, char* argv[]){
    if (argc != 3){
        cout << "Usage: ./a.out <inputFile> <outputFile>" << endl;
        exit(1);   
    }

    fstream input, output;

    input.open(argv[1], ios::in);
    if (input.fail()){
        cout << "Error while opening file " << argv[1] << endl;
        exit(1);
    }

    output.open(argv[2], ios::out);
    if (output.fail()){
        cout << "Error while opening file " << argv[2] << endl;

        input.fail();
        exit(1);
    }

    char buffer[MAX_LEN] = {};
    char* worldsList[MAX_LEN] = {};
    int worldsCount[MAX_LEN] = {};
    int worldsDim = 0;

    while(worldsDim <= 100 && input >> buffer){
        if (isValid(buffer)){
            int index = getIndexOf(worldsList, worldsDim, buffer);
           
            if (index == -1){
                worldsList[worldsDim] = new char[MAX_LEN];

                strcpy(worldsList[worldsDim], buffer);
                worldsCount[worldsDim] = 1;
                worldsDim++;
            }else{
                worldsCount[index]++;
            }
        }
    }

    for(int i = 0; i < worldsDim; i++){
        output << worldsList[i] << ": " << worldsCount[i] << endl;
        delete worldsList[i];
    }

    input.close();
    output.close();
    return 0;
}

int getIndexOf(char* array[], int dim, char* elem){
    int index = -1;

    for(int i = 0; i < dim; i++){
        if (strcmp(array[i], elem) == 0){
            index = i;
        }
    }

    return index;
}

bool isValid(char* elem){
    bool valid = true;

    int i;
    for(i = 0; valid && elem[i] != '\0'; i++){
        if (elem[i] < 'a' || elem[i] > 'z') valid = false;
    }

    return valid && i <= 100;
}