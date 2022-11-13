/*
Implementare una lista doppiamente concatenata costituita da un solo valore
Implementare le seguenti funzioni:
- inserimento ordinato
- rimozione nodo per valore
- stampa lista (valore corrente, precedente e prossimo)
Permettere all'utente di scegliere se aggiungere/ eliminare un nodo oppure stampare la lista
tramite un apposito menù di scelta nel main.
Ricordarsi di deallocare tutti gli elementi della lista al termine del programma.
*/
#include <iostream>

using namespace std;

struct node {
    int val;
    node* next;
    node* prev;
};

void inserisci_in_testa(node*& lista, int val);
void init_lista(node*& lista, int val);
void inserisci_ordinato(node*& lista, int val);
void rimuovi_nodo(node*& lista, int val);
void stampa(node* lista);
void dealloca_lista(node*& lista);

int main(){
    node* lista = NULL;
    char in = 'q';
    int val;
    do{
        cout << "'a' Inserisci numero\n'r' Rimuovi numero\n'p' Stampa\n'q' Esci\n";
        cin >> in;
        switch (in)
        {
        case 'a':
            cout << "Valore da inserire: ";
            cin >> val;
            inserisci_ordinato(lista, val);
            break;
        case 'r':
            cout << "Valore da rimuovere: ";
            cin >> val;
            rimuovi_nodo(lista, val);
            break;
        case 'p':
            stampa(lista);
            break;
        default:
            break;
        }
    } while (in != 'q');

    dealloca_lista(lista);

    return 0;
}

void inserisci_in_testa(node*& lista, int val){
    node * n = new node;
    n->val = val;
    n->next = lista;
    n->prev = lista->prev;
    lista->prev = n;
    lista = n;
}

void init_lista(node*& lista, int val){
    lista = new node;
    lista->next = NULL;
    lista->prev = NULL;
    lista->val = val;
}

void inserisci_ordinato(node*& lista, int val){
    if (lista==NULL) {
        init_lista(lista, val);
    }
    else if(lista->val >= val) {
        inserisci_in_testa(lista, val);
    }
    else {
        node* q=lista;
        while ((q->next != NULL) && (q->next->val <= val)) {
            q=q->next;
        }
        node* r = new node;
        r->val = val;
        r->next = q->next;
        if(q->next != NULL){
            q->next->prev = r;
        }
        r->prev = q;
        q->next = r;
    }
}

void rimuovi_nodo(node*& lista, int val){
    if (lista != NULL) {
        node* temp = lista;
        if (lista->val == val) {
            if(lista->next != NULL){
                lista->next->prev = NULL;
            }
            lista = lista->next;
            delete temp;
        }
        while(temp->next!=NULL){
            if(temp->next->val==val){
                node *r = temp->next;
                temp->next = temp->next->next;
                if(temp->next != NULL){
                    temp->next->prev = temp;
                }
                delete r;
                return;
            }
            temp=temp->next;
        }
        cout << "Elemento non trovato" << endl;
    } else {
        cout << "La lista è vuota" << endl;
    }
}


void stampa(node* lista){
    if(lista == NULL){
        cout << "Lista vuota" << endl;
        return;
    }
    while(lista != NULL) {
        cout << "Valore: " << lista->val << "\t";
        cout << "Valore prossimo: ";
        if (lista->next != NULL){
            cout << lista->next->val;
        } else {
            cout << "NULL";
        }
        cout << "\tValore precedente: ";
        if (lista->prev != NULL){
            cout << lista->prev->val;
        } else {
            cout << "NULL";
        }
        cout << "\t" << endl;
        
        lista = lista->next;
    }
}

void dealloca_lista(node*& lista){
    while(lista != NULL) {
        node * temp = lista;
        lista = lista->next;
        delete temp;
    }
    cout << "Lista deallocata" << endl;
}

