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

int count(const list* const l, int code);

// Inserire qui sotto la dichiarazione della funzione estrai

list* estrai(const list* const dipendenti, const list* const entrate, const list* const uscite);

// Inserire qui sopra la dichiarazione della funzione estrai

// Inserire qui sotto la dichiarazione della funzione delete_list

void delete_list(list* l);

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

int count(const list* const l, int code) {
    if(l == NULL) return 0;

    return (l->code == code) + count(l->next, code);
}

// Inserire qui sotto la definizione della funzione estrai

list* estrai(const list* const dipendenti, const list* const entrate, const list* const uscite) {
    list* estratti = new list{-1, NULL};
    list* ret = estratti;

    bool control = false;

    for(const list* dip = dipendenti; dip != NULL; dip = dip->next) {
        if(count(entrate, dip->code) == count(uscite, dip->code)) {
            control = true;

            estratti->code = dip->code;
            estratti->next = NULL;
            estratti = estratti->next;
        }
    }

    if(!control) {
        delete estratti;
        estratti = NULL;
        ret = NULL;
    }

    return ret;
}

// Inserire qui sopra la definizione della funzione estrai


// Inserire qui sotto la definizione della funzione delete_list

void delete_list(list* l) {
    while(l != NULL) {
        list* temp = l->next;
        delete l;
        l = temp;
    }
}

// Inserire qui sopra la definizione della funzione delete_list