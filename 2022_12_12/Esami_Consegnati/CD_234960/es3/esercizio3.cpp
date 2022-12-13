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
list * estrai(list * dipendenti, list * entrate, list * uscite)
{
  // Bastava la variabile head e check però ok.
  list * head = NULL;
  list * last;
  list * tmp_dipendenti = dipendenti;
  list * tmp_entrate;
  list * tmp_uscite;
  int check;

  while(tmp_dipendenti != NULL)
  {
    check = 0;
    tmp_entrate = entrate;
    tmp_uscite = uscite;

    // Consiglio: potevi fare una funzione conta così evitavi di scrivere
    // il codice 2 volte. Comunque va bene.
    while (tmp_entrate != NULL) // "Conta" entrate
    {
      if(tmp_entrate->code == tmp_dipendenti->code)
      {
        check++;
      }
      tmp_entrate = tmp_entrate->next;
    }
    while (tmp_uscite != NULL) // "Conta" uscite
    {
      if(tmp_uscite->code == tmp_dipendenti->code)
      {
        check--;
      }
      tmp_uscite = tmp_uscite->next;
    }

    if(check == 0) // Se entrate == uscite
    {
      if (head == NULL) // Se primo elemento
      {
        head = new list{tmp_dipendenti->code};
        last = head;
      }
      else // Se non primo elemento
      {
        last->next = new list{tmp_dipendenti->code};
        last = last->next;
      }
    }
    tmp_dipendenti = tmp_dipendenti->next;
  }

  return head;
}
// Inserire qui sopra la definizione della funzione estrai


// Inserire qui sotto la definizione della funzione delete_list
// FILL HERE
void delete_list(list * l)
{
  if (l != NULL)
  {
    delete_list(l->next);
  }
  delete l; // Occhio che se l è null all'ingresso della funzione
            // fai la delete di un qualcosa null.
}
// Inserire qui sopra la definizione della funzione delete_list

/*
COMMENTO: Estrai ok, cerca di evitare di utilizzare variabili che non servono.
Delete ok.
*/