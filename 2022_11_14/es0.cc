// Costruire una classe punto (x ,y)
// Implementare le seguenti funzioni
// - inizzializza punto
// - stampa punto
// - calcola retta tra due punti: stampare la retta nel formato y = wx + b dove w e b 
//                                sono valori che devono essere calcolati partendo dai due punti
//                                se i due punti sono uguali ritornare errore
//                                se y1 = y2 stampare nel formato x = w
//                                se x1 = x2 stampare nel formato y = w

#include <iostream>

using namespace std;


struct point {
    float x;
    float y;
};


point init_point(float x, float y);
void compute_line(point p1, point p2);
bool equals(point p1, point p2);
void print_point(point p);


int main() {
    int x, y;
    point p1, p2;

    cout << "Insert x1 and y1: ";
    cin >> x >> y;
    p1 = init_point(x, y);

    cout << "Insert x2 and y2: ";
    cin >> x >> y;
    p2 = init_point(x, y);

    print_point(p1);
    print_point(p2);

    compute_line(p1, p2);

    return 0;
}

point init_point(float x, float y) {
    point p;
    p.x = x;
    p.y = y;

    return p;
}

void compute_line(point p1, point p2) {
    float w, b;

    if (equals(p1, p2)) {
        cout << "The two points must be different to each other:" << endl;
        print_point(p1);
        print_point(p2);
    } else if (p1.x == p2.x){
        cout << "x = " << p1.x << endl;
    }else if (p1.y == p2.y){
        cout << "y = " << p1.y << endl;
    } else {
        w = (p1.y - p2.y) / (p1.x - p2.x);
        b = p1.y - w * p1.x;
        cout << "y = " << w << "x ";
        if (b >= 0) cout << "+ ";
        cout << b << endl;
    }
}

bool equals(point p1, point p2) {
    bool eq = false;
    if (p1.x == p2.x && p1.y == p2.y) eq = true;

    return eq;
}

void print_point(point p) {
    cout << "(" << p.x << ", " << p.y << ")" << endl;
}