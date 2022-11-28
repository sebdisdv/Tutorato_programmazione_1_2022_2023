#include <iostream>
#include "PriorityQ.h"

using namespace std;

int main() {
    priorityQueue* pq;
    int dim = 0;
    while (dim <= 0){
        cout << "Number of priorities: ";
        cin >> dim;
        cout << endl;
    }
    pq = init(dim);

    char ans;
    int value;
    int priority;
    do{
        cout << "'e' to insert a value\n";
        cout << "'d' to remove a value from the queue\n";
        cout << "'p' to print all the queue\n";
        cout << "'q' to quit\n";
        cin >> ans;
        switch (ans) {
            case 'e':{
                cout << "Value: ";
                cin >> value;
                cout << "Priority: ";
                cin >> priority;
                cout << endl;
                enqueue(*pq, value, priority);
                break;
            }
            case 'd':{
                int res = dequeue(*pq);
                if (res == -1){
                    cout << "Queue is empty\n";
                } else {
                    cout << "Value removed => " << res << endl;
                }
                break;
            }
            case 'p': {
                print(*pq);
                break;
            }
        }
    }while (ans != 'q');


    dealloc(*pq);
    return 0;
}
