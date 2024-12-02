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

item list_search(itemlist * head, key k);
/************************************************************************************************************************************************************************************

La procedura di ricerca in una lista concatenata è un processo iterativo che esplora
sequenzialmente ogni nodo della lista a partire dalla sua testa, cioè il primo elemento.
La funzione di ricerca riceve in input un puntatore al primo nodo della lista (head)
e una chiave (k), che rappresenta il valore da trovare.
L’obiettivo è individuare il nodo il cui campo chiave corrisponda esattamente al valore fornito.

La logica consiste nell'utilizzare un ciclo per attraversare la lista, partendo dal nodo iniziale e
procedendo attraverso i collegamenti definiti dal puntatore al nodo successivo.
Per ciascun nodo visitato, si estrae il valore della chiave associata e lo si confronta con la chiave di ricerca.
Questo confronto viene effettuato utilizzando una funzione specifica, progettata per determinare se due chiavi siano uguali.
Se il confronto restituisce un risultato positivo, significa che il nodo corrente contiene i dati cercati,
e il puntatore al nodo viene restituito come risultato della funzione.

Nel caso in cui il nodo corrente non corrisponda alla chiave di ricerca,
il processo prosegue passando al nodo successivo.
Questo ciclo continua fino a quando non si trova un nodo corrispondente oppure si raggiunge la fine della lista,
ovvero un nodo il cui puntatore successivo è nullo. Se la lista viene completamente attraversata senza trovare una corrispondenza,
la funzione restituisce un valore nullo per indicare che la chiave non è presente nella lista.

************************************************************************************************************************************************************************************/