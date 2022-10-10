# Tutorato 10_10_2022

## Esercizio 1

Scrivere una funzione ricorsiva `mcd` che prenda in ingresso due variabili di tipo intero e ne restituisca il Massimo Comune Divisore.
 - le due variabili in ingresso sono due numeri interi positivi
 - è possibile usare funzioni ausiliarie a patto che esse non contengano cicli di alcun tipo

## Esercizio 2

Scrivere un programma che dato in ingresso un numero intero positivo `n` stampi a video i primi 
`n` numeri della sequenza di fibonacci (1 1 2 3 5 8 13 21 34 55 ....).
 - la sequenza dovrà essere calcolata in modo ricorsivo

## Esercizio 3 (esercizio per la lode di un appello)

Scrivere un programma che dati in ingresso due numeri interi positivi `n1` `n2` ne calcoli la somma, il prodotto e la potenza (n1 base, n2 esponente).
 - è vietato sommare/moltiplicare direttamente i due numeri!
 - le procedure dovranno essere tutte ricorsive, quindi è vietato l'uso di qualsiasi ciclo

## Esercizio 4
Dato in input un numero n dall'utente, in maniera ricorsiva chiedere all'utente di inserire una lettera per n volte e, sapendo che le lettere in maiuscolo valgono 10 mentre quelle in minuscolo valgono 5, calcolare e stampare a video la somma totale.
 - è possibile usare la funzione `islower(char)` contenuta nella libreria `cctype` per controllare che il carattere in input sia minuscolo

## Esercizio 5
Creare una funzione che ricevuto un numero restituisce la somma delle cifre del numero 
se questa è minore di 10, il risultato della ri-applicazione della funzione sulla somma 
delle cifre del numero altrimenti.

- Esempi: f(15)=1+5=6, f(392)=f(14)=f(5)=5 dove 3+9+2=14 e 1+4=5.