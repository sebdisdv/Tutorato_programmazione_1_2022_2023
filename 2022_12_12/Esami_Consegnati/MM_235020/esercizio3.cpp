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

list* estrai(list* dipendenti, list* entrate, list* uscite);

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

// Inserire qui sotto la definizione della funzione estrai

list* estrai(list* dipendenti, list* entrate, list* uscite){
    list* ris=NULL;
    int n_dip=0;
    list* temp_dip=dipendenti;
    //capisco quanti dipendenti ho
    while(temp_dip!=NULL){
        temp_dip=temp_dip->next;
        n_dip++;
    }
    //alloco di conseguenza
    int* arr_dip_freq = new int[n_dip];
    int* arr_dip_names = new int[n_dip];
    temp_dip=dipendenti;
    int curr=0;
    //riscorro per prendere i vostri nomi
    while(temp_dip!=NULL){
        arr_dip_names[curr]=temp_dip->code;
        temp_dip=temp_dip->next;
        curr++;
    }
    //ora ho i nomi salvati, metto tutto a 0 e poi quando scorro entrate aggiungo 1, quando aggiungo uscite sottraggo
    for(int i=0;i<n_dip;i++){
        arr_dip_freq[i]=0;
    }
    //faccio entrate
    list* temp_entrate = entrate;
    int value_entrata_curr=0;
    while(temp_entrate!=NULL){
        value_entrata_curr=temp_entrate->code;
        for(int i=0;i<n_dip;i++){
            if(value_entrata_curr==arr_dip_names[i]){
                arr_dip_freq[i]++;
            }
        }
        temp_entrate=temp_entrate->next;
    }
    //ora uscite
    int value_uscita_curr=0;
    list* temp_uscite=uscite;
    while(temp_uscite!=NULL){
        value_uscita_curr=temp_uscite->code;
        for(int i=0;i<n_dip;i++){
            if(value_uscita_curr==arr_dip_names[i]){
                arr_dip_freq[i]--;
            }
        }
        temp_uscite=temp_uscite->next;
    }
    //se = 0 you go to ris
    list* position_in_insert;
    list* new_node;
    for(int i=0;i<n_dip;i++){
        if(arr_dip_freq[i]==0){
            //inserisci in lista risultato
            if(ris==NULL){
                ris= new _list;
                ris->code=arr_dip_names[i];
                ris->next=NULL;
                position_in_insert=ris;
            }else{
                new_node = new _list;
                new_node->next=NULL;
                new_node->code=arr_dip_names[i];
                position_in_insert->next=new_node;
                position_in_insert=position_in_insert->next;
            }
        }
    }
    delete [] arr_dip_names;
    delete [] arr_dip_freq;
    return ris;
}

// Inserire qui sopra la definizione della funzione estrai


// Inserire qui sotto la definizione della funzione delete_list

void delete_list(list* l){
    list* temp;
    while(l!=NULL){
        temp=l;
        l=l->next;
        delete temp;
    }
}

// Inserire qui sopra la definizione della funzione delete_list