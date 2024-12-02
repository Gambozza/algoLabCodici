/***************************************************************************

Fornire il codice C che definisca una struttura lista concatenata, i cui
elementi contengano tre informazioni: valore intero valint, una
stringa codice che fa anche da chiave di ricerca, un codice ID di
tipo long unsigned int. Se ne descriva la procedura di ricerca
di una chiave, indicandone il prototipo e facendo riferimento ai
membri delle strutture ricevute in input (senza implementazione)

***************************************************************************/

#define STRLEN 16
struct key
{
    char codice[STRLEN]; // Chiave di ricerca
} key;
typedef struct key key;

struct item
{
    key chiave;           // Chiave per la ricerca
    int valint;           // Valore intero
    unsigned long int ID; // Codice ID
} item;
typedef struct item item;

struct nodo
{
    item dati;         // Dati satellite
    struct nodo *next; // Puntatore al prossimo nodo
} nodo;
typedef struct itemlist itemlist;

item list_search(itemlist *head, key k);
/************************************************************************************************************************************************************************************

GPT

La funzione list_search consente di individuare un elemento in una lista concatenata utilizzando come criterio 
di confronto una chiave di ricerca. Ogni nodo della lista contiene un campo dati strutturato con tre informazioni: 
un valore intero valint, una stringa codice che funge da chiave di ricerca e un codice ID di tipo unsigned long int. 
La funzione riceve come parametri un puntatore alla testa della lista, head, e una chiave k contenente la stringa da cercare.

La ricerca procede scorrendo la lista a partire da head. 
Ad ogni nodo, il campo codice del nodo corrente, accessibile come current->dati.chiave.codice, 
viene confrontato con il valore della chiave k.codice utilizzando una funzione standard come strcmp. 
Se si trova una corrispondenza, la funzione restituisce il campo dati del nodo corrente, 
altrimenti continua fino alla fine della lista. Se nessun nodo soddisfa il criterio, 
la funzione restituisce un valore indicativo di assenza.

La complessità temporale della funzione è O(n), dove n è il numero di nodi nella lista, 
poiché nel caso peggiore è necessario visitare tutti i nodi. La complessità spaziale è O(1), 
poiché la memoria utilizzata è costante. list_search è quindi un metodo semplice ed efficace 
per effettuare ricerche lineari in una lista concatenata.

************************************************************************************************************************************************************************************/

/**********************************************************************************************************

Fornire il codice C che definisca una struttura lista concatenata, i cui
elementi contengano tre informazioni:
una stringa nome,
una stringa cognome,
una coppia di interi c1 e c2 fungono anche da chiave di ricerca
(composta).
Se ne descriva la procedura di inserimento di una chiave (nodo),
indicandone solo il prototipo e facendo riferimento ai membri delle
strutture ricevute in input (senza implementazione).

**********************************************************************************************************/

#define STRLEN 16
struct key
{
    int c1, c2;
};
typedef struct key key;

struct item
{
    key chiave;
    char nome[STRLEN];
    char cognome[STRLEN];
};
typedef struct item item;

struct itemlist
{
    item dati;
    struct itemlist *next;
};
typedef struct itemlist itemlist;

itemlist *list_insert(itemlist *head);

/*******************************************************************************************************************

La funzione list_insert è progettata per aggiungere un nuovo nodo a una lista concatenata. 
Ogni nodo della lista contiene tre informazioni principali: una stringa nome, una stringa cognome e una chiave 
composta da due interi c1 e c2. Il parametro head rappresenta la testa della lista concatenata e 
viene utilizzato come punto di partenza per l'inserimento del nuovo nodo.

La logica della funzione prevede la creazione di un nuovo nodo, inizializzando i suoi campi con i valori specificati per nome, 
cognome e la chiave chiave. Il nodo creato viene quindi inserito in testa alla lista concatenata 
o in una posizione determinata da un criterio specifico.

Se si sceglie di inserire il nodo in testa, il nuovo nodo diventa la testa della lista: 
il suo campo next viene impostato per puntare al nodo che era precedentemente la testa. 
La funzione restituisce quindi il nuovo nodo come nuova testa della lista.

La complessità temporale dell'inserimento in testa è O(1), poiché richiede solo l'aggiornamento di un puntatore. 
Tuttavia, se l'inserimento deve rispettare un criterio di ordinamento, la complessità potrebbe aumentare a O(n), 
dove n è il numero di nodi nella lista, poiché sarà necessario individuare la posizione corretta scorrendo la lista.

********************************************************************************************************************/
