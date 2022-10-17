#include <iostream>

using namespace std;

int main(){
    int n;
    cout << "dimensione matrice" << endl;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if( i == j || i == n-1-j ){
				cout << "2\t";
			} else if( i>j ){
				cout << "1\t";
			} else {
				cout << "3\t";
			}
		}
        cout << endl;
    }
    
    return 0;
}