#include <iostream>

using namespace std;

int main()
{
    int a, b;
    int mcd, mcm;
    int test_mcd, min;

    cout << "Inserisci due numeri: ";
    cin >> a >> b;

    mcm = a * b;
    

    if (a < b){
        min = a;
    }
    else{
        min = b;
    }

    test_mcd = 1;

    while (test_mcd <= min){
        if (a % test_mcd == 0 && b % test_mcd == 0)
        {
            mcd = test_mcd;
        }
        test_mcd++;
    }

    mcm = (a * b) / mcd;

    cout << "MCD = " << mcd << endl
         << "mcm = " << mcm << endl;
}