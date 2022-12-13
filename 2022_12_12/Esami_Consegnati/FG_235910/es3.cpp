#include <iostream>
#include <cstdlib>
#include <ctime>

typedef struct _list list;
#define MAXCODE 100
#define MAXDIP 10

struct _list {
    int code;
    list *next;
};

list *crea_lista_dipendenti(int num) {
    int *a = new int[num];
    for (int i = 0; i < num; i++) {
        a[i] = rand() % MAXCODE + 1;
        for (int j = 0; j < i; j++) {
            if (a[i] == a[j]) {
                i--;
                break;
            }
        }
    }
    list *res = NULL;
    for (int i = 0; i < num; i++) {
        res = new list{a[i], res};
    }
    delete[] a;
    return res;
}

list *crea_e_u(list *const dipendenti, const int t = 5) {
    list *res = NULL;
    for (int k = t; k >= 0; k--) {
        for (list *d = dipendenti; d != NULL; d = d->next) {
            if (rand() % 2 == 0) {
                res = new list{d->code, res};
            }
        }
    }
    return res;
}

void print_list(list *l, const char *prefix) {
    std::cout << prefix;
    for (; l != NULL; l = l->next)
        std::cout << " " << l->code;
    std::cout << std::endl;
}

// Inserire qui sotto la dichiarazione della funzione estrai
// FILL HERE


struct dipendent {
    int matricola;
    int stato;
};

void search_and_add(dipendent **tutti, int n, int matricola, int to_add) {
    for (int i = 0; i < n; i++) {
        if (tutti[i]->matricola == matricola) {
            tutti[i]->stato += to_add;
            return;
        }
    }
}

list *estrai(list *dipendenti, list *entrate, list *uscite) {
    list *temp = dipendenti;
    int n = 0;
    while (temp != nullptr) {
        n++;
        temp = temp->next;
    }

    dipendent **tutti = new dipendent *[n];

    temp = dipendenti;
    for (int i = 0; i < n; i++) {
        tutti[i] = new dipendent;
        tutti[i]->matricola = temp->code;
        tutti[i]->stato = 0;
        temp = temp->next;
    }

    while (entrate != nullptr) {
        search_and_add(tutti, n, entrate->code, 1);
        entrate = entrate->next;
    }
    while (uscite != nullptr) {
        search_and_add(tutti, n, uscite->code, -1);
        uscite = uscite->next;
    }

    list *out = nullptr;
    for (int i = 0; i < n; i++) {
        if (tutti[i]->stato == 0) {
            //std::cout << tutti[i]->matricola << std::endl;
            if (out) {
                //std::cout << "oraaaa" << std::endl;

                out->next = new list;
                out = out->next;
                out->next = nullptr;
                out->code = tutti[i]->matricola;

            } else {
                //std::cout << "ora" << std::endl;
                out = new list;
                out->next = nullptr;
                out->code = tutti[i]->matricola;

            }
        }
    }

    for (int i = 0; i < n; i++) {
        delete tutti[i];
    }
    delete[] tutti;
    return out;
}

// Inserire qui sopra la dichiarazione della funzione estrai

// Inserire qui sotto la dichiarazione della funzione delete_list
// FILL HERE

void delete_list(list *&head) {
    while (head != nullptr) {
        list *temp = head;
        head = head->next;
        delete temp;
    }
}

// Inserire qui sopra la dichiarazione della funzione delete_list

int main() {
    srand(unsigned(time(0)));
    //
    // Scommentare la linea seguente per avere comportamento
    // deterministico
    //
    //srand(0);

    list *dipendenti = crea_lista_dipendenti(MAXDIP);
    print_list(dipendenti, "Lista dipendenti:");
    list *entrate = crea_e_u(dipendenti);
    print_list(entrate, "Lista entrate:");
    list *uscite = crea_e_u(dipendenti);
    print_list(uscite, "Lista uscite:");
    list *estratti = estrai(dipendenti, entrate, uscite);
    print_list(estratti, "Estratti:");
    delete_list(dipendenti);
    delete_list(entrate);
    delete_list(uscite);
    delete_list(estratti);
}

// Inserire qui sotto la definizione della funzione estrai
// FILL HERE

// Inserire qui sopra la definizione della funzione estrai


// Inserire qui sotto la definizione della funzione delete_list
// FILL HERE

// Inserire qui sopra la definizione della funzione delete_list
