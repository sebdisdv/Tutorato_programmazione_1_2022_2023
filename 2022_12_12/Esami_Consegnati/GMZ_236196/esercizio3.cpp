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

// DEFINIZIONE estrai
list *estrai(list *dip, list *ent, list *usc);
// DEFINIZIONE delete_list
void delete_list(list *l);

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
list *estrai(list *dip, list *ent, list *usc) {
    int nent[MAXCODE] = {};
    for (list *l = ent; l != NULL; l = l->next) {
        nent[l->code]++;
    }
    for (list *l = usc; l != NULL; l = l->next) {
        nent[l->code]--;
    }

    list *res = NULL;
    for (list *l = dip; l != NULL; l = l->next) {
        if (nent[l->code] == 0) {
            list *nuovo = new list;
            nuovo->code = l->code;
            nuovo->next = res;
            res = nuovo;
        }
    }

    return res;
}
// Inserire qui sopra la definizione della funzione estrai

// Inserire qui sotto la definizione della funzione delete_list
// FILL HERE
void delete_list(list *l) {
    if (l != NULL) {
        delete_list(l->next);
    }
    delete l; // occhio che se l == NULL all'ingresso della funzione 
              // fai un delete anche se l == NULL, non ?? un grosso errore
              // per?? occhio la prossima volta
}
// Inserire qui sopra la definizione della funzione delete_list

/*
COMMENTO: Estrai ok.
Delete occhio al caso l==NULL.
*/