## Esercizio 

Scrivere in un file `Graph.cpp` le implementazioni delle funzioni definite all'interno del file `Graph.h`.
Lo scopo è quello di trovare dato un grafo di dipendenze, tutte le dipendenze di un nodo. Per farlo sarà necessario implementarsi un set.

Definizioni:

- `Dependency Graph`
   Un grafo orientato, dove un arco (A -> B) rappresenta la dipendenza di A da B, nel caso B avesse altre dipendeze allora A dipenderà anche da loro, ecc.. . Nel nostro caso per semplicità verrà descritto attraverso una matrice di adiacenza.

- `Set`
   Struttura dati che in questo caso è vista come un array allocato dinamicamente la cui dimensione varia in base al numero di elementi contenuti in esso. Gli elementi al suo interno devono sempre rimanere ordinati in ordine crescente, e non è possibile avere due elementi con lo stesso valore.
   La complessità della ricerca di un elemento all'interno del set deve essere pari a __O(log(n))__.
   Quando il set è pieno e si cerca di inserire un nuovo elemento la lunghezza dell'array verrà moltiplicata per l'__expansion factor__.
   Quando la percentuale di carico dell'array diventa inferiore del __LOAD__ allora la dimensione dovrà essere dimezzata.

NOTE:
 - il main del programma può essere modificato per testare il set prima di utilizzarlo nella ricerca delle dipendenze di un nodo all'interno del grafo
 - il file `Graph.h` non può essere modificato
 - per comodità è ammesso l'uso della struttura dati `stack` fornita dalle libreria di sistema (Per avere uno stack di variabili int usare `stack<int> nome;`) [spoiler: servirà nella visita del grafo]
 - i nodi e gli archi del grafo devono essere letti da un  file di testo come quello fornito (`graph1.txt`) dove la prima riga contiene il numero di nodi del grafo, e le righe successive gli archi, ad esempio `0 1` indica un arco `0 -> 1` (Essendo il grafo diretto 0 -> 1 non implica l'esistenza dell'arco 1 -> 0)
 - Esempi di dipendenza (Il grafo di riferimento è quello descritto in `graph1.txt`): 
  - Nodo 0 -> [1, 2, 3, 4, 5]
  - Nodo 1 -> [2, 4, 5]
  - Nodo 2 ->  []
  - Nodo 3 -> [0, 1, 2, 4, 5]
  - Nodo 4 -> [2]
  - Nodo 5 -> [2, 4]

 
