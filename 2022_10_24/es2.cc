#include <iostream>

using namespace std;

const int N = 10;
const int M = 10;

void riempiMatrice(int matrix[][M]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            matrix[i][j] = rand() % 100 + 1;
        }
    }
}

void bubbleSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

float calcolaMedia(int arr[], int n){
    int somma = 0;
    for (int i = 0; i < n; i++){
        somma += arr[i];
    }
    return (float) somma / n;
}

void bubbleSortByAvg(int arr[][M], int n, int m){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (calcolaMedia(arr[j], m) > calcolaMedia(arr[j + 1], m)){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


void stampaArray(int arr[][M]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cout << arr[i][j] << "\t";
        }
        cout << "Media: " << calcolaMedia(arr[i], M) << endl;
    }
    cout << endl;
}

int main(){
    srand(time(NULL));

    int matrix[N][M];
    riempiMatrice(matrix);
    cout << "Matrice appena generata" << endl;
    stampaArray(matrix);

    for (int i = 0; i < N; i++){
        bubbleSort(matrix[i], M);
    }
    cout << "Bubble sort su ogni riga" << endl;
    stampaArray(matrix);

    bubbleSortByAvg(matrix, N, M);
    cout << "Matrice ordinata" << endl;
    stampaArray(matrix);

    return 0;
}