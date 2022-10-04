#include <iostream>

using namespace std;

int main()
{

    int n;
    int somma=0, max, min;

    do{
        cout << "Quanti valori vuoi inserire?\n";
        cin >> n;
    } while (n <= 0);

    int val;

    for(int i = 0; i < n; i++){
        cout << "Valore numero " << i + 1 <<  " = ";
        cin >> val;
        if (i == 0){
            min = val;
            max = val;
        } else {
            if (val > max){
                max = val;
            } else {
                if (val < min){
                    min = val;
                }
            }
        }
        somma += val;
    } 

    cout << "MAX= " << max << endl;
    cout << "MIN= " << min << endl;
    cout << "MEDIA= " << (float) somma / n << endl;

    return 0;
}