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
list * estrai(list * dipendenti, list * entrate, list * uscite);
// Inserire qui sopra la dichiarazione della funzione estrai

// Inserire qui sotto la dichiarazione della funzione delete_list
// FILL HERE
void delete_list(list * l);
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

// Con alcuni seed va in segmentation fault,
// Prova con il seed 1670943862
list * estrai(list * dipendenti, list * entrate, list * uscite){
    list * estratti;
    list * start;
    bool first = true;

    while(dipendenti != NULL){
      int esaminato = dipendenti->code;

      int n_entrate = 0;
      list * q = entrate;
      while(q != NULL){
        if(q->code == esaminato) 
          n_entrate++;

        q = q->next;
      }

      int n_uscite = 0;
      q = uscite;
      while(q != NULL){
        if(q->code == esaminato) 
          n_uscite++;

        q = q->next;
      }

      if(n_entrate == n_uscite){
        estratti = new list{esaminato, NULL};
        if(first){
          start = estratti;
          first = false;
        }
        estratti = estratti->next; // qua sbagli, facendo così
                                   // ritorni sempre e solo il primo
                                   // elemento, se c'è, altrimenti
                                   // ti va in segmentatino fault
                                   // perché non hai inizializzato start.
      }
      dipendenti = dipendenti->next;
    }


    return start;  
}
// Inserire qui sopra la definizione della funzione estrai


// Inserire qui sotto la definizione della funzione delete_list
// FILL HERE
void delete_list(list * l){
  list * q;
  while(l != NULL){
    q = l;
    l = l->next;
    delete q;
  }
}
// Inserire qui sopra la definizione della funzione delete_list

/*
COMMENTO: La logica di estrai c'è però non hai gestito bene l'inizializzazione
e di conseguenza in alcuni casi va in segmentation fault. Ti dò metà punteggio 
per questa.
Delete ok.
*/