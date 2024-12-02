/**********************************************************************************************

Fornire il codice C che definisca una struttura dati pila, i cui elementi
contengano siano degli interi. Descrivere la procedura di push,
indicandone anche al prototipo, e facendo riferimento agli argomenti
in input nel fornirne la spiegazione logica

**********************************************************************************************/

typedef struct stack
{
    int valore;         // Valore intero contenuto nella pila
    struct stack *next; // Puntatore al prossimo elemento
} stack;

stack *push(stack *top, int nuovo_valore);

/*********************************************************************************

La funzione push serve a inserire un nuovo elemento in cima a una pila implementata come una lista concatenata.
La pila è rappresentata da una struttura dati composta da nodi, ognuno dei quali contiene un campo intero valore,
che memorizza il dato effettivo, e un puntatore next, che collega il nodo al successivo nella pila.
La cima della pila è identificata dal puntatore top, che rappresenta il nodo più recentemente inserito.

La funzione riceve due parametri: top, un puntatore al nodo che attualmente rappresenta la cima della pila,
e nuovo_valore, un intero che si desidera aggiungere. Il funzionamento si articola in tre passaggi principali.
Innanzitutto, viene allocata memoria per un nuovo nodo, e il campo valore di questo nodo viene
inizializzato con il valore fornito in input. Successivamente, il campo next del nuovo nodo viene impostato
per puntare al nodo attualmente in cima alla pila, rappresentato da top, garantendo che la struttura concatenata rimanga integra.
Infine, il puntatore top viene aggiornato per riferirsi al nuovo nodo, rendendolo la nuova cima della pila.
La funzione restituisce il nuovo valore di top, consentendo di mantenere il riferimento alla cima aggiornata.

La complessità temporale dell’operazione di inserimento è costante, ovvero O(1),
poiché richiede solo l’allocazione di memoria e pochi aggiornamenti di puntatori.
La complessità spaziale cresce linearmente rispetto al numero di elementi inseriti nella pila,
poiché ogni nuovo nodo richiede memoria aggiuntiva.

********************************************************************************/

/*********************************************************************************

Fornire un’implementazione in C della struttura dati Pila
Definire la struttura principale e indicare come verrebbe realizzata
l’operazione Head
– Analizzarne la complessità

********************************************************************************/

// Nodo della pila
typedef struct Nodo
{
    int valore;        // Valore intero contenuto nel nodo
    struct Nodo *next; // Puntatore al nodo successivo
} Nodo;

// Pila
typedef struct Pila
{
    Nodo *top; // Puntatore al nodo in cima alla pila
} Pila;

int head(Pila *p);

/*********************************************************************************

La funzione head consente di accedere al valore presente in cima alla pila senza rimuoverlo, 
mantenendo intatta la struttura della pila. La funzione riceve come parametro un puntatore alla struttura Pila, c
he contiene un campo top, il quale rappresenta il nodo attualmente in cima alla pila. 
La prima operazione eseguita è una verifica per stabilire se la pila è vuota, controllando se il puntatore top è nullo. 
Se la pila è vuota, la funzione genera un errore o restituisce un valore indicativo per segnalare che non ci sono elementi da restituire. 
Se invece la pila contiene almeno un elemento, la funzione accede direttamente al nodo puntato da top e 
restituisce il valore memorizzato nel campo valore di quel nodo. Questa operazione è molto efficiente, 
poiché richiede un’unica lettura del nodo in cima, senza dover iterare sugli altri elementi. 
La complessità temporale della funzione è O(1), dato che il tempo di esecuzione è indipendente dal numero di elementi nella pila, 
e la complessità spaziale è O(1), poiché non utilizza memoria aggiuntiva significativa.

********************************************************************************/
