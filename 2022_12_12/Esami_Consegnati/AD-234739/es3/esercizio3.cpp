#include <iostream>
#include <cstdlib>
#include <ctime>

typedef struct _list list;
#define MAXCODE 100
#define MAXDIP 10

struct _list {
  int code;
  list * next;
};

list * crea_lista_dipendenti(int num) {
  int * a = new int[num];
  for (int i = 0; i < num; i++) {
    a[i] = rand()%MAXCODE + 1;
    for (int j = 0; j < i; j++) {
      if (a[i] == a[j]) { i--; break;}
    }
  }
  list * res = NULL;
  for (int i = 0; i < num; i++) {
    res = new list{a[i], res};
  }
  delete [] a;
  return res;
}

list * crea_e_u(list * const dipendenti, const int t = 5) {
  list * res = NULL;
  for (int k = t; k >= 0; k--) {
    for (list * d = dipendenti; d != NULL; d = d->next) {
      if (rand()%2 == 0) {
        res = new list{d->code, res};
      }
    }
  }
  return res;
}

void print_list(list * l, const char * prefix) {
  std::cout << prefix;
  for( ; l != NULL; l = l->next)
    std::cout << " " << l->code;
  std::cout << std::endl;
}

// Inserire qui sotto la dichiarazione della funzione estrai
// FILL HERE
list* estrai(list *dipendenti, list *entrate, list *uscite);
// Inserire qui sopra la dichiarazione della funzione estrai

// Inserire qui sotto la dichiarazione della funzione delete_list
// FILL HERE
void delete_list(list *l);
// Inserire qui sopra la dichiarazione della funzione delete_list

int main() {
  srand(unsigned(time(0)));
		//
		// Scommentare la linea seguente per avere comportamento
		// deterministico
		//
		srand(0);

  list * dipendenti = crea_lista_dipendenti(MAXDIP);
  print_list(dipendenti, "Lista dipendenti:");
  list * entrate = crea_e_u(dipendenti);
  print_list(entrate, "Lista entrate:");
  list * uscite = crea_e_u(dipendenti);
  print_list(uscite, "Lista uscite:");
  list * estratti = estrai(dipendenti, entrate, uscite);
  print_list(estratti, "Estratti:");
  delete_list(dipendenti);
  delete_list(entrate);
  delete_list(uscite);
  delete_list(estratti);
}

// Inserire qui sotto la definizione della funzione estrai
// FILL HERE
// Il codice in alcune esecuzioni va in segmentaiton fault
// In tutte le liste in cui iteri, salti sempre l'ultimo elemento
list* estrai(list *dipendenti, list *entrate, list *uscite) {

  list *estratti = new list;
  list *ptr = estratti;

  for (;dipendenti->next != NULL; dipendenti = dipendenti->next) {
    list *estratti = new list; // estratti l'hai già allocata
                               // stai allocando nuova memoria
                               // senza mai usarla e senza deallocarla
    std::cout << dipendenti->code << " ";
    int entrate_count = 0;
    int uscite_count = 0;

    for (list *e = entrate;e->next != NULL; e = e->next) {
      if (e->code == dipendenti->code) entrate_count++;
    }
    for (list *u = uscite; u->next != NULL; u = u->next) {
      if (u->code == dipendenti->code) uscite_count++;
    }

    if (entrate_count == uscite_count) {
      list *new_list = new list;
      ptr->next = new_list;
      ptr = new_list;
      new_list->code = dipendenti->code;
    }

  }
  return estratti->next; // Dovresti ritornare estratti
                         // Comunque non hai inizializzato estratti a NULL
                         // Quindi quando è vuoto si rompe
                         // Prova ad eseguirlo con il seed 1670930643
}
// Inserire qui sopra la definizione della funzione estrai


// Inserire qui sotto la definizione della funzione delete_list
// FILL HERE

void delete_list(list *l) {
  if (l->next != NULL) delete_list(l->next);
  delete l; // se l == NULL lo elimini anche se non serve
}
// Inserire qui sopra la definizione della funzione delete_list

/*
COMMENTO: La funzione estrai non è di per se sbagliata però ci sono alcune cose
che non vanno e in alcuni casi fa segmentation fault. Ho deciso di darti metà punteggio.
Sulla delete ti do il massimo anche se è imprecisa.
*/
