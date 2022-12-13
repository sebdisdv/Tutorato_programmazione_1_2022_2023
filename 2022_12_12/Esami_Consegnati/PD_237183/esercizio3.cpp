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
list* estrai(list*, list*, list*);
// Inserire qui sopra la dichiarazione della funzione estrai

// Inserire qui sotto la dichiarazione della funzione delete_list
// FILL HERE
void delete_list(list*);
// Inserire qui sopra la dichiarazione della funzione delete_list

int countValues(list*, int);
list* initNode(const int, list*);
void insertHead(list*&, int);
void insertTail(list*& head, int value);

int main() {
  srand(unsigned(time(0)));
  //
  // Scommentare la linea seguente per avere comportamento
  // deterministico
  //
  //srand(0);

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
list* estrai(list* dipendenti, list* entrate, list* uscite){
  list* estratti = NULL;

  while(dipendenti != NULL){
    int code = dipendenti -> code;

    int entrateCount = countValues(entrate, code);
    int usciteCount = countValues(uscite, code);

    if (entrateCount == usciteCount) insertTail(estratti, code);

    dipendenti = dipendenti -> next;
  }

  return estratti;
}

// Inserire qui sopra la definizione della funzione est
// Inserire qui sotto la definizione della funzione delete_list
// FILL HERE
void delete_list(list* node){
  while(node != NULL){
    list* tmp = node;
    node = node -> next;

    delete tmp;
  }
}
// Inserire qui sopra la definizione della funzione delete_list

int countValues(list* head, int value){
  int count = 0;

  while(head != NULL){
    if (head -> code == value) count++;

    head = head -> next;
  }

  return count;
}

/**
 * Function that initialize a new node with the 
 * value and the nextNode passed as parameter.
 *
 * nextNode default as NULL
 *
 * @param value The value of the new node.
 * @param nextNode The next of the new Node, default as NULL.
*/
list* initNode(const int value, list* nextNode){
	list* newNode = new list;

	newNode -> code = value;
	newNode -> next = nextNode;

	return newNode;
}

/**
 * Function that insert a element int the head of a list.
 *
 * @param head The reference to the head of the list.
 * @param value The value of the new head.
*/
void insertHead(list* &head, int value){
	if (head == NULL){
		head = initNode(value, NULL);
	}else{
		list* newHead = initNode(value, head);

		head = newHead;
	}
}

/**
 * Function that insert a element in the tail of a list.
 *
 * @param head The reference to the head of the list.
 * @param value The value of the new tail.
*/
void insertTail(list*& head, int value){
	if (head == NULL){
		insertHead(head, value);
	}else{
		list* newNode = initNode(value, NULL);

		list* tail = head; // Senza questo side-effects sulla lista

		// il next non deve essere null, sennò sotto assegno al null -> next il newNode
		while(tail -> next != NULL){  
			tail = tail -> next;
		}

		tail -> next = newNode;
	}
}