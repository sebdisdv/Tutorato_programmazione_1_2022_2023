#include <iostream>
#include <cmath>
using namespace std;


struct arraylist{
    const float expansion_factor = 2;
    const float reduce_factor = 0.25;
    int current_length = 0;
    int current_max_length = 0;
    int* list = nullptr;
};


arraylist* init(const int length){
    arraylist* res = new arraylist;
    res->current_max_length = length;
    res->list = new int[length];
    return res;
}

void expand(arraylist& l){
    int* new_list = new int[(int)((l.current_max_length == 0 ? 1 : l.current_max_length)* l.expansion_factor)];
    for(int i = 0; i < l.current_max_length; i++){
        new_list[i] = l.list[i];
    }
    delete[] l.list;
    l.list = new_list;
    l.current_max_length = ((int)((l.current_max_length == 0 ? 1 : l.current_max_length)* l.expansion_factor));
    cout << "List expanded!\n";
}

void reduce(arraylist& l){
    int* new_list = new int[(int) (l.current_max_length * l.reduce_factor)];
    for(int i = 0; i < l.current_length; i++){
        new_list[i] = l.list[i];
    }
    delete[] l.list;
    l.list = new_list;
    l.current_max_length = ceil(l.current_max_length / 4);
    cout << "List reduced!\n";
}

void add(arraylist& l, const int value){
    if (l.current_length == l.current_max_length){
        expand(l);
    }
    l.list[l.current_length++] = value;
}


void remove_last(arraylist& l){
    if(l.current_length > 0){
        l.current_length--;
        if (l.current_length <= l.current_max_length / 4){
            reduce(l);
        }
    } else {
        cout << "Empty!\n";
    }
}

void print(arraylist& l){
    for(int i = 0; i < l.current_length; i++){
        cout << l.list[i] << " ";
    }
    cout << endl;
    cout << "current_len " << l.current_length << endl;
    cout << "current_max_len " << l.current_max_length << endl;
}


int main(){
    int v;
    char in = 'q';
    int len;
    cout << "Len? ";
    cin >> len;
    arraylist* l = init(len);
    do{
        cout << "'a' add\n'r' remove\n'p' print\n'q' quit\n";
        cin >> in;
        switch (in)
        {
        case 'a':
            cout << "Value: ";
            cin >> v;
            add(*l, v);
            break;
        case 'r':
            remove_last(*l);
            break;
        case 'p':
            print(*l);
            break;
        default:
            break;
        }
    } while (in != 'q');

    delete[] l->list;
    delete l;

    return 0;
}