#include <iostream>
#include <cstdlib>
#include <ctime>

typedef struct _list list;
#define MAXCODE 100
#define MAXDIP 10

struct _list
{
  int code;
  list *next;
};

list *crea_lista_dipendenti(int num)
{
  int *a = new int[num];
  for (int i = 0; i < num; i++)
  {
    a[i] = rand() % MAXCODE + 1;
    for (int j = 0; j < i; j++)
    {
      if (a[i] == a[j])
      {
        i--;
        break;
      }
    }
  }
  list *res = NULL;
  for (int i = 0; i < num; i++)
  {
    res = new list{a[i], res};
  }
  delete[] a;
  return res;
}

list *crea_e_u(list *const dipendenti, const int t = 5)
{
  list *res = NULL;
  for (int k = t; k >= 0; k--)
  {
    for (list *d = dipendenti; d != NULL; d = d->next)
    {
      if (rand() % 2 == 0)
      {
        res = new list{d->code, res};
      }
    }
  }
  return res;
}

void print_list(list *l, const char *prefix)
{
  std::cout << prefix;
  for (; l != NULL; l = l->next)
    std::cout << " " << l->code;
  std::cout << std::endl;
}

// Inserire qui sotto la dichiarazione della funzione estrai
// FILL HERE

list *estrai(list *const dip, list *const in, list *const out);

// Inserire qui sopra la dichiarazione della funzione estrai

// Inserire qui sotto la dichiarazione della funzione delete_list
// FILL HERE

void delete_list(list *&l);

// Inserire qui sopra la dichiarazione della funzione delete_list

int main()
{
  srand(unsigned(time(0)));
  //
  // Scommentare la linea seguente per avere comportamento
  // deterministico
  //
  srand(0);

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

list *estrai(list *const dip, list *const in, list *const out)
{
  if (NULL == dip)
  {
    return NULL;
  }

  list *res = NULL;
  list *res_aux = NULL;

  list *in_aux = in;
  list *out_aux = out;
  list *dip_aux = dip;
  while (dip_aux != NULL)
  {
    int in_count = 0;
    while (in_aux != NULL)
    {
      if (in_aux->code == dip_aux->code)
      {
        in_count++;
      }
      in_aux = in_aux->next;
    }
    in_aux = in;

    int out_count = 0;
    while (out_aux != NULL)
    {
      if (out_aux->code == dip_aux->code)
      {
        out_count++;
      }
      out_aux = out_aux->next;
    }
    out_aux = out;

    if (in_count == out_count)
    {
      res_aux = new list;
      res_aux->code = dip_aux->code;
      res_aux->next = NULL;
      
      // Aggiungi solo un elemento a res e basta,
      // infatti ti ritorna solo il primo elemento della lista dipendenti
      // prova con il seed 1670944643, vedrai che l'output è sbagliato
      if (NULL == res)
      {
        res = res_aux;
      }
      res_aux = res_aux->next;
      
    }

    dip_aux = dip_aux->next;
  }

  return res;
}

// Inserire qui sopra la definizione della funzione estrai

// Inserire qui sotto la definizione della funzione delete_list
// FILL HERE

void delete_list(list *&l)
{
  if (NULL == l)
  {
    return;
  }
  list *tmp = l;
  l = l->next;
  delete tmp;
  delete_list(l);
}

// Inserire qui sopra la definizione della funzione delete_list

/*
COMMENTO: La logica di estrai è corretta ma la lista in output non sempre.
Per questo ti dò la metà dei punti.
Delete ok.
*/