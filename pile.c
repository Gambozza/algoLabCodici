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

int push(Stack *stack, int value);

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

/*********************************************************************************

Fornire un’implementazione, in linguaggio C, della stuttura dati pila, i cui elementi siano associati ai
seguenti campi: codice (stringa), nome (stringa) e cognome (stringa). Riportare:

1. come si vuole realizzare la struttura dati, da un punto di vista astratto, logico (in breve), facendo
riferimento brevemente a come si realizzarebbero le operazioni ad essa essociate;

2. i costrutti struct (uno o pi`u) necessari alla definizione della pila, commentando tipo e ruolo di ciascun
membro della struttura;

3. il prototipo della funzione pop, che rimuove dalla pila l’elemento in cima, descrivendone il tipo
dell’output, il tipo degli argomenti di input e la logica di funzionamento. Occorre fare specifico
riferimento agli input e ai loro membri per la realizzazione dell’operazione. La funzione NON va
implementata. Indicare, inoltre, la complessit`a computazionale della stessa.

Per tutti i punti `e possibile fare riferimento, laddove lo si ritenga opportuno, sia a strutture dati proposte
durante il corso, che alle funzioni che le utilizzano.

********************************************************************************/

typedef struct Elemento
{
    char codice[50];  // Codice identificativo dell'elemento
    char nome[50];    // Nome associato all'elemento
    char cognome[50]; // Cognome associato all'elemento
} Elemento;

typedef struct Nodo
{
    Elemento dati;     // Dati associati all'elemento della pila
    struct Nodo *next; // Puntatore al prossimo nodo nella pila
} Nodo;

typedef struct Pila
{
    Nodo *cima;     // Puntatore al nodo in cima alla pila
    int dimensione; // Numero di elementi nella pila
} Pila;

Elemento pop(Pila* p);

/*********************************************************************************

La funzione pop è progettata per rimuovere l’elemento in cima a una pila implementata come lista concatenata e restituirne i dati. 
La funzione riceve come parametro un puntatore alla struttura Pila, 
che rappresenta la pila e contiene un puntatore al nodo in cima e il numero totale di elementi. 
Per prima cosa, la funzione verifica se la pila è vuota controllando il puntatore cima o il valore del campo dimensione. 
Se la pila è vuota, restituisce un valore speciale o segnala un errore, evitando operazioni su una struttura vuota. 
Se la pila contiene elementi, la funzione accede al nodo in cima e copia i dati memorizzati nella struttura Elemento. 
Successivamente, aggiorna il puntatore cima della pila per riferirsi al nodo successivo, utilizzando il campo next del nodo corrente. 
La memoria occupata dal nodo rimosso viene deallocata per evitare perdite di memoria. 
Infine, il campo dimensione della struttura Pila viene decrementato per riflettere la rimozione dell’elemento. 
La funzione restituisce la struttura Elemento che contiene i dati associati all’elemento rimosso. 
L’intera operazione avviene in tempo costante O(1), poiché il nodo in cima è sempre accessibile direttamente tramite il puntatore cima

********************************************************************************/

