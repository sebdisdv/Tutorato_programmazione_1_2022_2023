# Tutorato 07_11_2022 

# I/O e Ricorsione

## Esercizio 1

Scrivere un programma che stampi a video il numero di occorrenze di ciascun carattere presente in un file di testo chiamato `input.txt`

### Hint
- Quanti elementi ha la tabella ASCII?
- una variabile di tipo `char` può essere castata a `...` 
### Note
- È possibile leggere il file di testo una sola volta!
- Controllare che il file esista e terminare il programma con un messaggio d'errore in caso (usare `exit()` e `cerr`)

## Esercizio 2
Scrivere un programma che prenda in ingresso un file di testo passatoli da terminale contenente una lista di parole e stampi a video la parola e se quest'ultima è palindroma o meno. La funzione di controllo deve essere ricorsiva.

### Note
 - è possibile usare la funzione `strlen`, inclusa in `<cstring>`,  per ottenere la lunghezza delle stringhe in input
 - Fare tutti i controlli del caso
 - - Numero di argomenti in input 
 - - Esistenza del file di testo

## Esercizio 3
Scrivere un programma che prenda in ingresso due file di testo (input e output). Il file di output dovrà contenere le stesse parole del file di input, ma dovranno essere censurate, sostituendo tutte le lettere in maiuscolo con '`*`'. La procedura di censura di una stringa dovrà essere ricorsiva(tanto per cambiare).

### Note
 - è possibile usare la funzione `strlen` e `isupper`, incluse in `<cstring>`
 - Fare tutti i controlli del caso
 - - Numero di argomenti in input 
 - - Esistenza del file di testo

# Allocazione dinamica e ricorsione

## Esercizio 4

Dato in ingresso un array di interi dall'utente (dovrà essere allocato dinamicamente, chiedendo la lunghezza all'utente), scrivere una funzione `filter`, ovviamente ricorsiva, la quale ritorna un array contenente solo gli elementi pari contenuti nell'array in input.

### Firma delle funzioni da scrivere 
- `int* filter(int*, int, int&)`
- `int* filter_rec(int*, int, int, int&)`

## Esercizio 5
Dato in ingresso le dimensioni di una matrice di interi, scrivere una funzione che restituisca la matrice trasposta.

### Note
- Ricordarsi di deallocare!
- La matrice deve essere inizializzata con valori random tra `[0,10]`
- La funzione che calcola la trasposta non deve essere ricorsiva