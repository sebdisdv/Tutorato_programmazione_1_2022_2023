// Implementare una struttura persona(nome[35], età) e lista concatenata
// Implementare le funzioni 
// - init person
// - init list
// - print_person
// - print list
// - inserimento ordinato
#include <iostream>
#include <cstring>

using namespace std;

struct person {
    char name[35];
    int age;
};

struct node {
    person p;
    node* next;
};

person init_person(char name[35], int age);
void print_person(person p);
node* init_node(person p, node* next);
void insert_ordered(node* &l, person p);
void print_list(node* l);

int main() {
    char name[35];
    int age;
    person p;
    node* l;

    cout << "Inserire nome e età: ";
    cin >> name >> age;
    p = init_person(name, age);
    insert_ordered(l, p);

    cout << "Inserire nome e età: ";
    cin >> name >> age;
    p = init_person(name, age);
    insert_ordered(l, p);

    cout << "Inserire nome e età: ";
    cin >> name >> age;
    p = init_person(name, age);
    insert_ordered(l, p);

    print_list(l);

    return 0;
}

person init_person(char name[35], int age) {
    person p;
    strcpy(p.name, name);
    p.age = age;

    return p;
}

void print_person(person p) {
    cout << p.name << " " << p.age << "y.o.";
}

node* init_node(person p, node* next) {
    node* n = new node;
    n->p = p;
    n->next = next;
    return n;
}

void insert_ordered(node* &l, person p) {
    node* s;
    node* tmp;
    if (l==NULL || p.age < l->p.age) {
        tmp = new node;
        tmp->p = p;
        tmp->next = l;
        l = tmp;
    } else {
        tmp = l;
        while(tmp->next != NULL && p.age > tmp->p.age) {
            tmp = tmp->next;
        }
        s = new node;
        s->p = p;
        s->next = tmp->next;
        tmp->next = s;
    }
}

void print_list(node* l) {
    cout << "[";
    for (l; l != NULL; l = l->next) {
        print_person(l->p);
        if (l->next != NULL) cout << ", ";
    }
    cout << "]" << endl;
}