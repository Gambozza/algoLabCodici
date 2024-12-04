/*******************************************************************************************************************

Fornire una rappresentazione in C di un grafo orientato pesato rappresentato mediante liste di adiacenza.
Si pu`o assumere che ciascun nodo del grafo sia associato al solo indice che lo individua nel grafo: in
altri termini, non `e richiesto prevedere, nella struttura dati proposta, dello spazio per altre informazioni.
Riportare i costrutti struct (uno o pi`u) necessari alla definizione del grafo, commentando brevemente il
tipo e il ruolo di ciascun membro della struttura.

E' possibile fare riferimento, laddove lo si ritenga opportuno, sia a strutture dati proposte durante il
corso, che alle funzioni che le utilizzano

********************************************************************************************************************/

typedef struct Arco
{
    int destinazione;  // Indice del nodo di destinazione
    int peso;          // Peso dell'arco
    struct Arco *next; // Puntatore al prossimo arco nella lista di adiacenza
} Arco;

typedef struct Nodo
{
    Arco *lista_adiacenza; // Puntatore alla lista di archi uscenti da questo nodo
} Nodo;

typedef struct Grafo
{
    Nodo *nodi;   // Array di nodi del grafo
    int num_nodi; // Numero totale di nodi nel grafo
} Grafo;

/*******************************************************************************************************************

Arco:
    -Ogni istanza di questa struttura rappresenta un arco orientato.
    -Il campo nodo_dest specifica il nodo di destinazione dell’arco.
    -Il campo peso rappresenta il valore associato all’arco (peso).
    -Il campo next è un puntatore al prossimo arco nella lista di adiacenza del nodo di partenza,
    consentendo di creare una lista concatenata per gli archi in uscita.

Grafo:
    -Questa struttura rappresenta l’intero grafo.
    -Il campo num_nodi memorizza il numero totale di nodi nel grafo.
    -Il campo liste_adiacenza è un array di puntatori a strutture Arco,
    con dimensione pari al numero di nodi.
    Ogni elemento dell’array rappresenta la lista di adiacenza del corrispondente nodo.

********************************************************************************************************************/

/*******************************************************************************************************************

Fornire una rappresentazione, in linguaggio C, di un grafo orientato, assumendo che: 1) linserimento/la
cancellazione dei vertici sia un evento frequente; 2) i vertici mediamente abbiano un grado basso; 3) siano
frequenti operazioni di inserimento o di cancellazione di un arco. Ciascun vertice, oltre alle informazioni
per rappresentare la struttura grafo, `e associato a una stringa codice che lo individua univocamente nel
grafo. Riportare:

1. i costrutti struct (uno o pi`u) necessari alla definizione del grafo, commentando tipo e ruolo di ciascun
membro di ciascuna struttura;

2. il prototipo della funzione di cancellazione di un arco, cancella arco, descrivendone in maniera chiara
il prototipo (tipo di output, tipo argomenti di input) e la logica di funzionamento legata a ciascun
argomento. La funzione NON va implementata (la sua implementazione `e facoltativa). Indicare
inoltre, la complessit`a computazionale della stessa.

`E possibile fare riferimento, laddove lo si ritenga opportuno, sia a strutture dati proposte durante il corso,
che alle funzioni che le utilizzano.

********************************************************************************************************************/

typedef struct Arco
{
    struct Vertice *destinazione; // Puntatore al vertice di destinazione
    struct Arco *next;            // Puntatore al prossimo arco nella lista di adiacenza
} Arco;

typedef struct Vertice
{
    char codice[50];       // Stringa univoca identificativa del vertice
    Arco *lista_adiacenza; // Lista degli archi in uscita
    struct Vertice *next;  // Puntatore al prossimo vertice nella lista dei vertici
} Vertice;

typedef struct Grafo
{
    Vertice *lista_vertici; // Lista concatenata dei vertici
    int num_vertici;        // Numero totale di vertici
} Grafo;

int cancella_arco(Grafo *g, const char *codice_sorgente, const char *codice_destinazione);

/*******************************************************************************************************************

La funzione cancella_arco consente di rimuovere un arco orientato da un grafo rappresentato tramite liste di adiacenza.
La funzione riceve in input un puntatore alla struttura del grafo,
la stringa univoca del vertice sorgente e quella del vertice destinazione.
Per prima cosa, attraversa la lista dei vertici del grafo partendo da g->lista_vertici e confronta il codice del vertice
con quello fornito come sorgente tramite una funzione come strcmp. Se il vertice sorgente non viene trovato,
la funzione termina restituendo un valore di errore, ad esempio -1. Una volta individuato il vertice sorgente,
la funzione scorre la lista di adiacenza associata al vertice, cercando l’arco che punta al vertice di destinazione.
Anche in questo caso, il confronto avviene tramite il codice univoco del vertice di destinazione.
Se l’arco viene trovato, il nodo corrispondente è rimosso aggiornando opportunamente i puntatori della lista di adiacenza,
deallocando la memoria associata e restituendo 0 per indicare il successo.
In caso contrario, la funzione restituisce un errore.
La complessità della funzione è O(V+d), dove V è il numero di vertici e dd il grado medio dei vertici.

********************************************************************************************************************/

/*******************************************************************************************************************

Fornire una rappresentazione mediante matrice di adiacenza, in linguaggio C, di un grafo orientato non
pesato. Si pu`o assumere che ciascun nodo del grafo sia associato al solo indice che lo individua nel grafo:
in altri termini, non `e richiesto prevedere, nella struttura dati proposta, dello spazio per altre informazioni
circa i nodi. Riportare:

1. i costrutti struct (uno o pi`u) necessari alla definizione del grafo, commentando tipo e ruolo di ciascun
membro della struttura;

2. il prototipo della funzione inserisci arco, per inserire un arco (orientato) nel grafo, descrivendolo in
maniera chiara (tipo di output, tipo argomenti di input), spiegando la logica di funzionamento della
funzione, ed eventualmente producendo anche la sua definizione in C.

********************************************************************************************************************/

typedef struct Matrice
{
    int **dati;     // Puntatore alla matrice di adiacenza
    int dimensione; // Dimensione della matrice (numero di nodi)
} Matrice;

typedef struct Grafo
{
    Matrice matrice_adiacenza; // Matrice di adiacenza che rappresenta le connessioni del grafo
} Grafo;

void inserisci_arco(Grafo *g, int nodo1, int nodo2);

// void inserisci_arco(Grafo *g, int nodo1, int nodo2)
// {
//     // Verifica validità degli indici
//     if (nodo1 < 0 || nodo1 >= g->matrice_adiacenza.dimensione ||
//         nodo2 < 0 || nodo2 >= g->matrice_adiacenza.dimensione)
//     {
//         printf("Errore: Indici non validi.\n");
//         return;
//     }

//     // Inserisce l'arco nella matrice di adiacenza
//     g->matrice_adiacenza.dati[nodo1][nodo2] = 1;
// }

/*******************************************************************************************************************

La funzione inserisci_arco ha il compito di aggiungere un arco orientato in un grafo
rappresentato tramite una matrice di adiacenza incapsulata nella struttura Matrice.
La funzione riceve come parametri un puntatore al grafo, che contiene la matrice di adiacenza,
e due interi che rappresentano gli indici del nodo sorgente e del nodo di destinazione dell’arco da inserire.
Per prima cosa, la funzione verifica che gli indici forniti siano validi,
cioè compresi nell’intervallo da 0 a g->matrice_adiacenza.dimensione - 1.
Se uno degli indici non è valido, la funzione segnala l'errore e termina senza modificare il grafo.
In caso contrario, aggiorna l’elemento corrispondente nella matrice di adiacenza,
impostando g->matrice_adiacenza.dati[nodo1][nodo2] a 1,
per indicare la presenza di un arco orientato dal nodo sorgente al nodo di destinazione.
Grazie alla struttura Matrice, che incapsula la gestione della matrice, la funzione è chiara e modulare,
mantenendo la separazione tra i dettagli di implementazione della matrice e la logica di gestione del grafo.
Questa organizzazione consente un accesso diretto alla matrice, garantendo una complessità temporale O(1)
per ogni operazione di inserimento, rendendo il processo rapido ed efficiente anche per grafi di grandi dimensioni.

********************************************************************************************************************/

/*******************************************************************************************************************

Fornire in linguaggio C una rappresentazione di un grafo ORIENTATO PESATO, rappresentato mediante
liste di adiacenza. Ciascun nodo del grafo ha associate anche informazioni satellite, tra cui un codice
univoco (stringa). Riportare:
1. i costrutti struct (uno o pi`u) necessari alla definizione del grafo, commentando tipo e ruolo di ciascun
membro di ogni struttura;
2. il prototipo della funzione cancella arco, per cancellare un arco dal grafo, descrivendolo in maniera
chiara (tipo di output, tipo argomenti di input), spiegando la logica di funzionamento della funzione
rispetto ai suoi input. La definizione in C della funzione `e facoltativa.

********************************************************************************************************************/

typedef struct Arco
{
    struct Vertice *destinazione; // Puntatore al vertice di destinazione
    int peso;                     // Peso dell'arco
    struct Arco *next;            // Puntatore al prossimo arco nella lista
} Arco;

typedef struct Vertice
{
    char codice[50];       // Codice univoco del vertice
    Arco *lista_adiacenza; // Puntatore alla lista di adiacenza (archi in uscita)
    struct Vertice *next;  // Puntatore al prossimo vertice nella lista dei vertici
} Vertice;

typedef struct Grafo
{
    Vertice *lista_vertici; // Lista concatenata dei vertici del grafo
    int num_vertici;        // Numero totale di vertici
} Grafo;

int cancella_arco(Grafo *g, const char *codice_sorgente, const char *codice_destinazione);

/*******************************************************************************************************************

La funzione cancella_arco ha il compito di rimuovere un arco orientato pesato da un grafo rappresentato tramite liste di adiacenza.
La funzione riceve in input un puntatore alla struttura del grafo, i codici univoci del vertice sorgente e del vertice di destinazione.
Per iniziare, la funzione attraversa la lista concatenata dei vertici del grafo,
confrontando il codice di ciascun vertice con il codice sorgente fornito. Se il vertice sorgente non viene trovato,
la funzione termina restituendo un errore (-1). Una volta individuato il vertice sorgente,
la funzione scorre la lista di adiacenza associata a quel vertice,
cercando un arco che punti al vertice con il codice di destinazione specificato.
Se non trova l’arco, restituisce un altro errore (-2). In caso contrario,
l’arco viene rimosso dalla lista aggiornando opportunamente i puntatori: se l’arco è il primo elemento della lista,
il puntatore alla testa viene aggiornato; altrimenti, il puntatore del nodo precedente viene fatto puntare al nodo successivo.
Infine, il nodo dell’arco viene deallocato e la funzione restituisce 0 per indicare il successo.
La complessità della funzione è O(V+d), dove V è il numero di vertici e dd il grado medio dei vertici,
poiché combina la ricerca del vertice nella lista principale e dell’arco nella lista di adiacenza.

********************************************************************************************************************/

/*******************************************************************************************************************

Fornire una rappresentazione, in linguaggio C, di un grafo pesato orientato. Si assuma che:

• I vertici abbiano mediamente un grado basso;

• Ogni vertice contenga una stringa descrizione e una stringa codice di 12 caratteri;

• Sia molto frequente la ricerca di un vertice dall’esterno mediante la stringa codice.
Si richiede di riportare:

1. i costrutti struct (uno o pi`u) necessari alla definizione del grafo, commentando tipo e ruolo di ciascun
membro della struttura;

2. il prototipo della funzione di cancellazione di un arco, cancella arco, descrivendone in maniera
chiara il prototipo (tipo di output, tipo argomenti di input) e la logica di funzionamento. La fun-
zione NON va implementata (la sua implementazione `e facoltativa). Indicare inoltre, la complessit`a
computazionale della funzione.

Per entrambi i punti 1 e 2 `e possibile fare riferimento, laddove lo si ritenga opportuno, sia a strutture dati
proposte durante il corso, che alle funzioni che le utilizzano.

********************************************************************************************************************/

typedef struct Arco
{
    struct Vertice *destinazione; // Puntatore al vertice di destinazione
    int peso;                     // Peso dell'arco
    struct Arco *next;            // Puntatore al prossimo arco nella lista
} Arco;

typedef struct Vertice
{
    char codice[13];       // Codice univoco del vertice (12 caratteri + terminatore)
    char descrizione[100]; // Descrizione del vertice
    Arco *lista_adiacenza; // Puntatore alla lista di archi in uscita
    struct Vertice *next;  // Puntatore al prossimo vertice nella lista
} Vertice;

typedef struct TabellaHash
{
    Vertice **buckets; // Array di puntatori ai vertici
    int num_buckets;   // Numero di bucket nella tabella hash
} TabellaHash;

typedef struct Grafo
{
    TabellaHash *tabella;   // Tabella hash per la ricerca rapida dei vertici
    Vertice *lista_vertici; // Lista concatenata di tutti i vertici del grafo
    int num_vertici;        // Numero totale di vertici
} Grafo;

int cancella_arco(Grafo *g, const char *codice_sorgente, const char *codice_destinazione);

/*******************************************************************************************************************

La funzione cancella_arco è progettata per rimuovere un arco orientato in un grafo pesato rappresentato tramite liste di adiacenza,
ottimizzando la ricerca dei vertici tramite una tabella hash.
La funzione riceve in input un puntatore alla struttura del grafo, il codice del vertice sorgente e quello del vertice di destinazione.
Utilizzando la tabella hash, la funzione calcola l’indice del bucket associato al codice del vertice sorgente e
attraversa la lista concatenata nel bucket per individuare il vertice corrispondente.
Questa operazione ha una complessità media O(1).
Una volta trovato il vertice sorgente, la funzione accede alla sua lista di adiacenza,
dove cerca l’arco che punta al vertice di destinazione.
Durante l’attraversamento, confronta il codice del vertice di destinazione di ogni arco con il codice fornito.
Se l’arco viene trovato, la funzione aggiorna i puntatori della lista di adiacenza per rimuovere il nodo corrispondente,
dealloca la memoria associata all’arco e restituisce 0 per indicare il successo.
Se il vertice sorgente non viene trovato nella tabella hash, la funzione restituisce -1,
mentre se l’arco non è presente nella lista di adiacenza, restituisce -2. La complessità della funzione è O(1+d),
dove d è il grado uscente del vertice sorgente.

********************************************************************************************************************/

/*******************************************************************************************************************

Fornire un’implementazione, in linguaggio C, di un grafo pesato orientato rappresentato mediante liste
di adiacenza. Ciascun nodo del grafo `e associato ad un codice univoco cod, una stringa. Riportare:

1. come si vuole realizzare la struttura dati, da un punto di vista astratto, logico (in breve);

2. i costrutti struct (uno o pi`u) necessari alla definizione del grafo, commentando tipo e ruolo di ciascun
membro della struttura;

3. il prototipo della funzione che inserisce un arco nel grafo, addEdge, che prende in input, in ordine,
i codici dei due nodi per cui si vuole inserire l’arco. Si descriva in maniera chiara il prototipo
della funzione (tipo di output, tipo argomenti di input) e la logica di funzionamento, con specifico
riferimento agli input e ai loro membri. La funzione NON va implementata (la sua implementazione
`e facoltativa). Indicare inoltre, la complessit`a computazionale della stessa.

Per tutti i punti `e possibile fare riferimento, laddove lo si ritenga opportuno, sia a strutture dati proposte
durante il corso, che alle funzioni che le utilizzano

********************************************************************************************************************/

typedef struct Arco
{
    char destinazione[50]; // Codice univoco del nodo destinazione
    int peso;              // Peso dell'arco
    struct Arco *next;     // Puntatore al prossimo arco nella lista di adiacenza
} Arco;

typedef struct Nodo
{
    char codice[50];       // Codice univoco del nodo
    Arco *lista_adiacenza; // Puntatore alla lista degli archi in uscita
    struct Nodo *next;     // Puntatore al prossimo nodo nella lista del grafo
} Nodo;

typedef struct Grafo
{
    Nodo *lista_nodi; // Lista concatenata di nodi del grafo
} Grafo;

int addEdge(Grafo *g, const char *codice_sorgente, const char *codice_destinazione, int peso);

/*******************************************************************************************************************

La funzione addEdge serve a inserire un arco orientato e pesato in un grafo rappresentato mediante liste di adiacenza.
Riceve come parametri un puntatore alla struttura del grafo, i codici univoci dei nodi sorgente e destinazione, e il peso dell’arco.
La funzione inizia scorrendo la lista concatenata dei nodi del grafo per trovare il nodo sorgente corrispondente al codice fornito.
Una volta individuato, crea un nuovo nodo di tipo Arco, inizializzando il campo destinazione con il codice del nodo di destinazione e
il campo peso con il valore fornito in input. Questo nuovo nodo viene poi inserito in testa alla lista di adiacenza del nodo sorgente,
rendendo l’inserimento particolarmente efficiente. Successivamente, la funzione verifica che il nodo destinazione esista nel grafo,
scorrendo la lista dei nodi; se non lo trova, restituisce un errore, segnalando che l’operazione non può essere completata.
L’intera operazione ha una complessità O(V), dove V è il numero di nodi del grafo, poiché la ricerca dei nodi sorgente e destinazione
domina il costo computazionale, mentre l’inserimento di un arco nella lista di adiacenza ha complessità O(1).

********************************************************************************************************************/