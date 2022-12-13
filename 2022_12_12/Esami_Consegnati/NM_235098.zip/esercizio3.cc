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

list * estrai(list*, list*, list*);

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

list * estrai(list* dipendenti, list* entrate, list* uscite){
    int ent=0;
    int ext=0;
    int n=0;
    list * estratti=new list;
    estratti->code=0;
    estratti->next=NULL;
    list * temp_dipendenti=dipendenti;
    while (temp_dipendenti!=NULL){
        n=temp_dipendenti->code;
        list * temp_entrate=entrate;
        while (temp_entrate!=NULL){
            if (temp_entrate->code==n){
                ent++;
            }
            temp_entrate=temp_entrate->next;
        }
        list * temp_uscite=uscite;
        while (temp_uscite!=NULL){
            if (temp_uscite->code==n){
                ext++;
                
            }
            temp_uscite=temp_uscite->next;
        }
        if (ent == ext){
            if (estratti->code==0){
                estratti->code=n;
            } else {
                list * temp_estratti=estratti;
                while (temp_estratti->next!=NULL){
                    temp_estratti=temp_estratti->next;
                }
                list * tmp=new list;
                temp_estratti->next=tmp;
                tmp->code=n;
                tmp->next=NULL;
            }
        }
        temp_dipendenti=temp_dipendenti->next;
        ent =0;
        ext =0;
    }
    return estratti;
}

// Inserire qui sopra la definizione della funzione estrai


// Inserire qui sotto la definizione della funzione delete_list
// FILL HERE

void delete_list(list * del){
    list * temp;
    while (del!=NULL){
        temp=del->next;
        delete del;
        del =temp;
    }
}

// Inserire qui sopra la definizione della funzione delete_list