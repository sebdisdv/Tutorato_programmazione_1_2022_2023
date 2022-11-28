

Scrivere in un file `PriorityQ.cpp` le implementazioni delle funzioni definite all'interno del file `PriorityQ.h`.
Il file `PriorityQ.h` e il main del programma possono essere trovati nella cartella `es2`.
La struttura dati da implementare è una sorta di coda a priorità dove ad ogni elemento è appunto associata una priorità.

Quando si deve rimuovere un elemento dalla coda, dovrà essere rimosso per primo l'elemento con priorità più bassa.
Per semplificare l'esercizio, la priority Queue è definita come una struttura con un array di code, ciascuna con la propria priorità.

Ciascuna coda deve essere implementata con una lista doppiamente linkata, quindi ogni nodo avrà due puntatori, uno per il successore ed uno per il predecessore

NOTE:

- Quando si cerca di estrarre un elemento da una coda vuota dovrà essere restituito il valore `-1`
- Fare attenzione a come viene deallocata la memoria!