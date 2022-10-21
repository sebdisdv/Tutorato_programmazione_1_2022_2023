#include <iostream>
using namespace std;

int main(){
    int v[3][4] = {{1, 2, 4, 2},{5, 3, 4, 2},{6, 4, 7, 5}};
    int max_i=0, max_j=0, max = v[0][0];
    for(int i=0; i < 3; i++){
        for(int j=0; j < 4; j++){
            if (v[i][j] > max){
                max_i = i;
                max_j = j;
                max = v[i][j];
            }
        }
    }

    cout << "[" << max_i << "," << max_j << "]" << endl;
    return 0;
}