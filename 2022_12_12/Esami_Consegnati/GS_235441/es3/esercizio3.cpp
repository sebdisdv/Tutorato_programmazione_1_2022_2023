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

list * estrai (list *, list *, list *);

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

list * estrai(list * dipendenti, list * entrate, list * uscite) {
	
	// La lista che returniamo
	list * l = NULL;

	// Itero per ogni dipendente
	while(dipendenti != NULL) {
		
		// Conto le volte che è entrato
		int num_entrate = 0;
		list * tmp = entrate;
		while(tmp != NULL) {
			if (tmp->code == dipendenti->code) {
				num_entrate++;
			}
			tmp = tmp->next;
		}

		// Conto le volte che è uscito
		int num_uscite = 0;
		tmp = uscite;
		while(tmp != NULL) {
			if (tmp->code == dipendenti->code) {
				num_uscite++;
			}
			tmp = tmp->next;
		}

		if (num_entrate == num_uscite) {
			
			// Aggiungiamo il valore alla lista
			list *new_list = new list;
			new_list->code = dipendenti->code;
			new_list->next = NULL;

			if (l == NULL) {
				// primo elemento
				l = new_list;
			}
			else {
				// Facendo così ritorni sempre il primo e l'ultimo ma mai
				// quelli in mezzo, prova con seed 1670944643
				// Vedrai che l'output non è corretto
				l->next = new_list;
			}
		}
		
		// Controlla il prossimo dipendente	
		dipendenti = dipendenti->next;
	}
	return l;
}


// Inserire qui sopra la definizione della funzione estrai


// Inserire qui sotto la definizione della funzione delete_list
// FILL HERE

void delete_list(list * l) {
	
	if (l != NULL) {
		delete_list(l->next);
		delete l;
	}
}

// Inserire qui sopra la definizione della funzione delete_list

/*
COMMENTO: Estrai ritorna solo il primo e l'ultimo elemento. La logica c'è
ma la funzione non ritorna quello che dovrebbe. Ti dò la metà dei punti.
Delete ok.
*/