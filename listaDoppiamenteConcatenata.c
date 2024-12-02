/**********************************************************************************************

Fornire un’implementazione in C della struttura dati lista doppiamente
concatenata
Definire la struttura principale e indicare come verrebbe realizzata
l’operazione list_insert
– Analizzarne la complessità

**********************************************************************************************/

// Nodo della lista doppiamente concatenata
typedef struct Nodo
{
    int valore;        // Valore intero del nodo
    struct Nodo *next; // Puntatore al nodo successivo
    struct Nodo *prev; // Puntatore al nodo precedente
} Nodo;

// Lista doppiamente concatenata
typedef struct Lista
{
    Nodo *head; // Puntatore al primo nodo
    Nodo *tail; // Puntatore all'ultimo nodo
} Lista;

/**********************************************************************************************

La lista è rappresentata da una struttura contenente due puntatori:  head, che indica il primo nodo, e tail, che punta all’ultimo nodo.
La funzione riceve due parametri: un puntatore alla lista su cui operare e il valore intero da inserire.

Il primo passo della funzione è creare un nuovo nodo,
allocando dinamicamente la memoria necessaria e inizializzando i suoi campi:
il valore viene assegnato al campo valore, mentre i puntatori next e prev sono inizialmente impostati a NULL.
Successivamente, la funzione verifica se la lista è vuota controllando se head è nullo. In caso affermativo,
il nuovo nodo diventa sia la testa che la coda della lista, dato che è l’unico elemento presente.
Al contrario, se la lista contiene già elementi, il nuovo nodo viene collegato alla fine della lista.
Questo avviene aggiornando il puntatore next dell’attuale ultimo nodo (tail) per riferirsi al nuovo nodo,
e il puntatore prev del nuovo nodo per riferirsi all’attuale ultimo nodo.
Infine, il puntatore tail della lista viene aggiornato per puntare al nuovo nodo, che diventa così l’ultimo elemento della lista.

L’intera operazione avviene in tempo costante, O(1),
poiché non è necessario iterare sui nodi della lista per completare l’inserimento.
Inoltre, la funzione utilizza memoria aggiuntiva solo per il nuovo nodo, rendendola efficiente sia in termini di tempo che di spazio.

**********************************************************************************************/
