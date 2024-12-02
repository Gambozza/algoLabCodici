/**********************************************************************************************

Fornire il codice C che definisca una struttura dati pila, i cui elementi
contengano siano degli interi. Descrivere la procedura di push,
indicandone anche al prototipo, e facendo riferimento agli argomenti
in input nel fornirne la spiegazione logica

**********************************************************************************************/

typedef struct StackNode
{
    int value;              // Valore intero contenuto nel nodo
    struct StackNode *next; // Puntatore al nodo successivo
} StackNode;

typedef struct Stack
{
    StackNode *top; // Nodo in cima alla pila
} Stack;

int push(Stack* stack, int value);

/*********************************************************************************
La funzione push è progettata per inserire un nuovo elemento in cima alla pila, 
modificando direttamente la struttura della pila attraverso un puntatore a essa. 
La funzione riceve come argomenti un puntatore alla pila (Stack* stack) e un valore intero (int value) da aggiungere. 
Inizialmente, viene allocata dinamicamente memoria per un nuovo nodo della pila, rappresentato dalla struttura StackNode. 
Una volta creato il nuovo nodo, il valore passato in input viene assegnato al campo value del nodo stesso, 
mentre il campo next viene impostato per puntare all'elemento attualmente in cima alla pila, 
il quale è indicato dal campo top della struttura Stack. 
Dopo questa operazione, il campo top della pila viene aggiornato per puntare al nuovo nodo, 
rendendolo effettivamente il nuovo elemento in cima alla pila.
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
