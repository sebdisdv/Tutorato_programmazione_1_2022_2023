#include<iostream>

using namespace std;

struct stack{
    int* buffer;
    int head;
    int curr_size;
    int max_size;
};

void init(stack &s, int dim);
bool push(stack &s, int val);
bool first(stack &s, int& ret);
bool last(stack &s, int& ret);
bool pop(stack &s);
bool pop_last(stack &s);
void dealloc(stack &s);

int main() {
    stack s;
    init(s, 3);
    int ret;

    cout << push(s, 1) << endl;

    cout << push(s, 2) << endl;

    int f;
    cout << first(s, f) << " " << f << endl;
    cout << last(s, f) << " " << f << endl;
    cout << pop_last(s) << endl;
    cout << first(s, f) << " " << f << endl;
    cout << last(s, f) << " " << f << endl;

    cout << push(s, 3) << endl;
    cout << first(s, f) << " " << f << endl;
    
    dealloc(s);
    return 0;
}

void init(stack &s, int dim) {
    s.buffer = new int[dim];
    s.head = 0;
    s.curr_size = 0;
    s.max_size = dim;
}

bool push(stack &s, int val) {
    bool result = true;
    if (s.curr_size < s.max_size){
        s.buffer[s.head] = val;
        s.head = (s.head + 1) % s.max_size;
        s.curr_size++;
    } else {
        result = false;
    }
    return result;
}

bool first(stack &s, int &ret) {
    bool result = true;
    if (s.curr_size > 0){
        ret = s.buffer[(s.head - 1 + s.max_size) % s.max_size];
    } else {
        result = false;
    }
    return result;
}

bool last(stack &s, int &ret) {
    bool result = true;
    if (s.curr_size > 0){
        ret = s.buffer[(s.head - s.curr_size + s.max_size) % s.max_size];
    } else {
        result = false;
    }
    return result;
}

bool pop(stack &s) {
    bool result = true;
    if (s.curr_size > 0) {
        s.head = (s.head - 1 + s.max_size) % s.max_size;
        s.curr_size--;
    } else {
        result = false;
    }
    return result;
}

bool pop_last(stack &s) {
    bool result = true;
    if (s.curr_size > 0) {
        s.curr_size--;
    } else {
        result = false;
    }
    return result;
}

void dealloc(stack &s){
    delete s.buffer;
}