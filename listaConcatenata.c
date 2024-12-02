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

La funzione list_insert, che prende in ingresso il puntatore alla testa della lista, ha il compito di creare un nuovo elemento e integrarlo correttamente.
Per fare questo, la funzione inizia allocando memoria per il nuovo nodo e inizializzandolo con i dati forniti.
Questi dati comprendono una chiave composta, il nome e il cognome, che vengono assegnati ai campi del nuovo nodo.

Se l'inserimento deve avvenire all'inizio della lista, il nuovo nodo viene collegato al resto della struttura impostando il suo
puntatore al nodo che attualmente rappresenta la testa della lista. A questo punto, il nuovo nodo diventa la nuova testa e il suo puntatore
viene restituito dalla funzione per riflettere il cambiamento.

L’inserimento di un nuovo nodo in una lista concatenata è un’operazione che aggiunge un elemento alla struttura mantenendo l’integrità dei collegamenti
tra i nodi. La funzione list_insert accetta un puntatore al primo nodo della lista, chiamato testa, e si occupa di creare un nuovo nodo con i dati forniti.
Questi dati includono la chiave composta da due interi, il nome e il cognome.
Il primo passo è allocare memoria per il nuovo nodo, assicurandosi che sia pronto per essere inserito.

Una volta creato il nodo, il suo contenuto viene inizializzato con i dati forniti. Se il nuovo nodo deve essere aggiunto all’inizio della lista,
il puntatore del nuovo nodo viene impostato in modo da collegarlo all’attuale testa della lista,
e la funzione aggiorna la testa per farla puntare al nuovo nodo. In questo caso, il nuovo nodo diventa il primo elemento della lista.

********************************************************************************************************************/
