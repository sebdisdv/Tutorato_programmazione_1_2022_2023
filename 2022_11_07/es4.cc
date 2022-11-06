#include <iostream>
using namespace std;

int* filter_rec(int* v, int i, int count, int& res_len){
    int* res = nullptr;
    if(i <= 0){
        res = new int[count];
    } else {
        if(v[i - 1] % 2 == 0){
            res = filter_rec(v, i - 1, count + 1, res_len);
            res_len++;
            res[res_len - 1] = v[i - 1];
        } else {
            res = filter_rec(v, i - 1, count, res_len);
        }
    }
    return res;
}

int* filter(int* v, int v_len, int& res_len){
    res_len = 0;
    int* res;
    res= filter_rec(v, v_len, 0, res_len);
    return res;
}

void print_array(int* v, int len){
    cout << "Length: " << len << endl;
    for(int i = 0; i < len; i++){
        cout << v[i] << " ";
    }
    if(len == 0){
        cout << "Empty!";
    }
    cout << endl;
}

int main(){
    int* v;
    int v_len = 0;
    
    do{
        cout << "Numero di elementi da inserire: ";
        cin >> v_len;
    } while  (v_len <= 0);

    v = new int[v_len];
    
    for(int i = 0; i < v_len; i++){
        cout << "v[" << i << "] = ";
        cin >> v[i]; 
    }
    
    int res_len;
    int* res = filter(v, v_len, res_len);
    
    print_array(res, res_len);

    delete[] res, v;
    return 0;
}