/**********************************************************************************************

Fornire una rappresentazione, in linguaggio C, di un albero binario di ricerca,
assumendo che la chiave di ricerca sia composta da due stringhe, cognome e
nome. 
L’ordine sulle chiavi è dato prima dall’ordine lessicografico del cognome, e,
a parità di cognome, dall’ordine lessicografico del nome. 
Riportare:

1. i costrutti struct (uno o più) necessari alla definizione dell’albero binario di
ricerca, commentando tipo e ruolo di ciascun membro della struttura;

2. il prototipo della funzione compare_key (tipo di output, tipo argomenti di
input), che prese in input due chiavi, le confronti e restituisca un intero
indicante l’esito del confronto. L’implementazione di tale funzione è
facoltativa, ma ne va descritta la logica di funzionamento in relazione a
ciascun argomento. Valutare, inoltre, la complessità computazionale della
stessa.

È possibile fare riferimento, laddove lo si ritenga opportuno, sia a strutture dati
proposte durante il corso, che alle funzioni che le utilizzano.

**********************************************************************************************/

// Struttura della chiave di ricerca
typedef struct Chiave
{
    char cognome[50]; // Cognome del nodo (massimo 50 caratteri)
    char nome[50];    // Nome del nodo (massimo 50 caratteri)
} Chiave;

// Nodo dell'albero binario di ricerca
typedef struct Nodo
{
    Chiave chiave;      // Chiave di ricerca (cognome e nome)
    struct Nodo *left;  // Puntatore al figlio sinistro
    struct Nodo *right; // Puntatore al figlio destro
} Nodo;

// Albero binario di ricerca
typedef struct Albero
{
    Nodo *root; // Puntatore alla radice dell'albero
} Albero;

int compare_key(Chiave k1, Chiave k2);

/**********************************************************************************************

La funzione int compare_key(Chiave k1, Chiave k2) confronta due chiavi composte da un cognome e un nome, 
entrambe rappresentate come stringhe, e restituisce un intero che indica l’esito del confronto secondo l’ordine lessicografico. 
La funzione restituisce -1 se la chiave k1 è considerata inferiore a k2, 1 se k1 è maggiore di k2, e 0 se le chiavi sono uguali.

Il confronto avviene in due fasi. Prima, la funzione utilizza strcmp per confrontare i cognomi. 
Se i cognomi sono diversi, il risultato di questo confronto determina direttamente l’output: 
un valore negativo se il cognome di k1 precede quello di k2, e positivo se lo segue. 
Se i cognomi sono uguali, la funzione passa al confronto dei nomi, utilizzando nuovamente strcmp. 
Analogamente, il confronto dei nomi restituisce il risultato basato sull’ordine lessicografico. 
Infine, se sia i cognomi che i nomi sono identici, la funzione restituisce 0, indicando che le chiavi sono equivalenti.

La complessità computazionale della funzione è proporzionale alla lunghezza delle stringhe confrontate. 
Nel caso peggiore, dove i cognomi coincidono e occorre confrontare anche i nomi, la complessità è O(m + n), 
dove m e n sono rispettivamente le lunghezze del cognome e del nome. 

**********************************************************************************************/
