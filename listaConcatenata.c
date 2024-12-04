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
    int c1, c2;             // Coppia di interi che fungono da chiave di ricerca
};
typedef struct key key;

struct item
{
    key chiave;             // Chiave per la ricerca
    char nome[STRLEN];      // Nome dell'elemento
    char cognome[STRLEN];   // Cognome dell'elemento
};
typedef struct item item;

struct itemlist
{
    item dati;              // Dati dell'elemento
    struct itemlist *next;  // Puntatore al prossimo elemento
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

/*******************************************************************************************************************

SPERO VIVAMENTE CHE NON CHIEDA PIU' ESERCZI DEL GENERE. ESAME DEL 23/06/2020

Si supponga di voler memorizzare gli utenti che hanno eseguito l’accesso a un servizio Internet nel corso
di una giornata. Al termine della stessa, gli utenti vengono analizzati tutti, per calcolare delle statistiche
di utilizzo del servizio. Tutti gli utenti quindi, uno per volta, verranno analizzati. Di ciascun utente
sono disponibili nome (char[20]), cognome (char[20]), citt`a (char[20]) e il tipo di servizio richiesto (int).
Scegliere l’implementazione della struttura dati lista concatenata pi`u appropriata tra quelle viste a lezione,
considerando che:

• si dispone di uno spazio di memoria RAM di 15 GB;

• il numero di utenti giornaliero non supera i 2.108 utenti.

Riportare:

1. i costrutti struct (uno o pi`u) necessari alla definizione della lista, commentando brevemente il tipo e
il ruolo di ciascun membro della struttura;

2. una giustificazione della implementazione scelta, indicando la complessit`a delle operazioni richieste
e lo spazio occupato da tutta la lista (nell’ipotesi si raggiunga il numero massimo di utenti). Le
operazioni da prendere in considerazione sono (i) l’inserimento di un singolo utente, (ii) l’analisi di
tutti gli utenti (assumendo costante il tempo di elaborazione del singolo nodo), (iii) la distruzione
della lista.

Per entrambi i punti 1 e 2 `e possibile fare riferimento, laddove lo si ritenga opportuno, sia a strutture dati
proposte durante l’insegnamento, che alle funzioni che le utilizzano.

********************************************************************************************************************/

typedef struct Utente
{
    char nome[20];    // Nome dell'utente
    char cognome[20]; // Cognome dell'utente
    char citta[20];   // Città dell'utente
    int servizio;     // Tipo di servizio richiesto
} Utente;

typedef struct Nodo
{
    Utente dati;       // Informazioni dell'utente
    struct Nodo *next; // Puntatore al nodo successivo
} Nodo;

typedef struct Lista
{
    Nodo *testa;   // Puntatore al primo nodo della lista
    int lunghezza; // Numero di nodi nella lista
} Lista;

/*******************************************************************************************************************

La scelta di utilizzare una lista concatenata semplice rappresentata da una struttura astratta è ideale per il problema in esame, 
in quanto offre modularità e chiarezza nella gestione dei dati. Separare la logica della lista, 
tramite una struttura dedicata chiamata Lista, dalla rappresentazione dei dati dell'utente attraverso la struttura Utente, 
consente di mantenere il codice ben organizzato e facilmente estendibile. 
La struttura Lista fornisce un livello di astrazione superiore, 
permettendo di gestire informazioni globali come il numero di nodi senza doverle ricalcolare dinamicamente ogni volta.

L’operazione di inserimento di un utente avviene in testa alla lista, 
aggiornando il puntatore testa e incrementando il contatore lunghezza in tempo costante O(1). 
Questa scelta è particolarmente efficiente e consente di aggiungere nuovi utenti senza la necessità di attraversare l’intera lista. 
L’analisi di tutti gli utenti si realizza attraversando la lista a partire dal primo nodo, 
visitando ciascun elemento in sequenza, con una complessità lineare O(n), dove n è il numero totale di nodi. 
Questo approccio è adeguato al problema, dato che tutti gli utenti devono essere analizzati una volta al termine della giornata. 
La distruzione della lista, infine, prevede un attraversamento completo, durante il quale ogni nodo viene deallocato; 
anche questa operazione ha complessità lineare O(n).

Dal punto di vista dello spazio occupato, ogni nodo richiede 72 byte, 
suddivisi tra i campi che rappresentano i dati dell’utente e il puntatore al nodo successivo. 
La struttura Lista richiede ulteriori 12 byte per mantenere il puntatore al primo nodo e il contatore della lunghezza. 
Con un massimo di 2.108 utenti, lo spazio totale occupato dalla lista è di circa 148,3 kB, 
un valore estremamente contenuto rispetto ai 15 GB di memoria RAM disponibili, 
lasciando ampio margine per altre operazioni o eventuali espansioni del sistema.

CALCOLI:
Con la struttura astratta, ogni nodo occupa:
    -Utente: 60 byte (tre array da 20 byte ciascuno) + 4 byte (int servizio) = 64 byte.
    -Nodo: 64 byte (campo dati) + 8 byte (puntatore next) = 72 byte.

Ogni lista mantiene inoltre:
    -Lista: 8 byte per il puntatore testa + 4 byte per l'intero lunghezza = 12 byte.

Con 2.108 utenti:
    -Spazio totale nodi: 72×2108=151.776 byte (≈148,3 kB)72×2108=151.776byte(≈148,3kB).
    -Spazio struttura lista: 12 byte.
    -Totale: Circa 148,3 kB, trascurabile rispetto ai 15 GB disponibili.

********************************************************************************************************************/
