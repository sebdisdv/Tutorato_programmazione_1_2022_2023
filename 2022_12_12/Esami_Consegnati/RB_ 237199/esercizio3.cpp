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
list * estrai(list *, list *, list *);
// Inserire qui sopra la dichiarazione della funzione estrai

// Inserire qui sotto la dichiarazione della funzione delete_list
// FILL HERE
void delete_list(list *);
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
list * estrai(list * dipendenti, list *entrate, list *uscite){
  list * estratti = NULL; 
  list * d = dipendenti;
  list * e = entrate;
  list * u = uscite;

  while (d != NULL){ // itero i dipendenti
    int num_entrate = 0;
    int num_uscite = 0;

    while (e != NULL){
      if(e->code == d->code){
        num_entrate += 1;
      }
      e = e->next;
    }
    while (u != NULL){
      if(u->code == d->code){
        num_uscite += 1;
      }
      u = u->next;
    }
    if(num_entrate == num_uscite){
      estratti = new list{d->code, estratti};
    }
    d = d->next;
    e = entrate;
    u = uscite;
  }
  return estratti; 
}
// Inserire qui sopra la definizione della funzione estrai


// Inserire qui sotto la definizione della funzione delete_list
// FILL HERE
void delete_list(list * l){
  if(l == NULL){
    return;
  }
  list * t = l;
  l = l->next;
  delete t;
  delete_list(l);
}

// Inserire qui sopra la definizione della funzione delete_list

/*
COMMENTO: Ok. Potevi usare una funzione per calcolare le entrate e uscite
senza ripetere il codice, ma va bene.
*/