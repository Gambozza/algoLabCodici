/**********************************************************************************************

Fornire una rappresentazione, in linguaggio C, di un grafo pesato non orientato mediante matrice di
adiacenza. Si pu`o assumere che ciascun nodo del grafo sia associato al solo indice che lo individua nel
grafo: in altri termini, non `e richiesto prevedere, nella struttura dati proposta, dello spazio per altre
informazioni (ad esempio per una descrizione dell’entit`a che il nodo rappresenta). Si pu`o assumere che il
grafo sia statico, cio`e che non siano previste operazioni di inserimento e/o cancellazione di nodi.
Riportare:

1. i costrutti struct (uno o pi`u) necessari alla definizione del grafo, commentando tipo e ruolo di ciascun
membro della struttura;

2. il prototipo della funzione di inserimento di un arco, inserisci arco, descrivendone in maniera
chiara il prototipo (tipo di output, tipo argomenti di input) e la logica di funzionamento. La fun-
zione NON va implementata (la sua implementazione `e facoltativa). Indicare inoltre, la complessit`a
computazionale della funzione.

Per entrambi i punti 1 e 2 `e possibile fare riferimento, laddove lo si ritenga opportuno, sia a strutture dati
proposte durante il corso, che alle funzioni che le utilizzano

**********************************************************************************************/

typedef struct MatriceAdiacenza
{
    int **dati;     // Puntatore alla matrice bidimensionale degli archi
    int dimensione; // Numero totale di nodi (dimensione della matrice)
} MatriceAdiacenza;

typedef struct Grafo
{
    MatriceAdiacenza matrice; // Struttura che incapsula la matrice di adiacenza
} Grafo;

void inserisci_arco(Grafo *g, int nodo1, int nodo2, int peso);

/**********************************************************************************************

La funzione inserisci_arco si occupa di aggiungere o aggiornare un arco pesato tra due nodi di un grafo rappresentato tramite
matrice di adiacenza. Per farlo, prende in input un puntatore alla struttura del grafo,
che consente di accedere e modificare direttamente la matrice, gli indici dei due nodi coinvolti nell'arco e
il peso che rappresenta il valore dell'arco. Innanzitutto, la funzione verifica che gli indici dei nodi siano validi,
ovvero che rientrino nell'intervallo compreso tra 0 e g->dimensione - 1, altrimenti gestisce l'errore.
Una volta confermata la validità degli indici, aggiorna l'elemento corrispondente nella matrice di adiacenza,
assegnando il valore del peso a g->matrice_adiacenza[nodo1][nodo2]. Poiché il grafo è non orientato,
la simmetria degli archi è garantita aggiornando anche il valore speculare g->matrice_adiacenza[nodo2][nodo1] con lo stesso peso.
La funzione modifica così lo stato interno della struttura del grafo direttamente, senza restituire un valore.
L'operazione richiede un tempo costante O(1), dato che l'accesso agli elementi di una matrice avviene direttamente tramite indici,
e non comporta ulteriori allocazioni di memoria.

**********************************************************************************************/

/**********************************************************************************************

Fornire una rappresentazione, in linguaggio C, di un grafo non orientato mediante liste di adiacenza. A
ciascun nodo del grafo `e associato il nome di una citt`a, che si pu`o assumere essere univoco. Si pu`o assumere
inoltre che le operazioni di ricerca di una citt`a siano frequenti.
Riportare:

1. i costrutti struct (uno o pi`u se necessari) occorrenti alla definizione del grafo, commentando il ruolo
di ciascun membro di ciascuna struttura;

2. il prototipo della funzione di ricerca di una citt`a, cerca vertice, descrivendone in maniera chiara il
prototipo (tipo di output, tipo argomenti di input) e la logica di funzionamento. La funzione NON va
implementata (la sua implementazione `e facoltativa), ma va descritto invece come essa opera sui suoi
argomenti. Infine, indicare (motivandolo in maniera concisa) la complessit`a computazionale della
funzione.

Per entrambi i punti 1 e 2 `e possibile fare riferimento, laddove lo si ritenga opportuno, sia a strutture dati
proposte durante il corso, che alle funzioni che le utilizzano.

**********************************************************************************************/

typedef struct NodoAdiacente
{
    char *citta;                // Nome della città adiacente
    struct NodoAdiacente *next; // Puntatore al prossimo nodo adiacente
} NodoAdiacente;

typedef struct Vertice
{
    char *citta;                    // Nome della città (univoco)
    NodoAdiacente *lista_adiacenza; // Puntatore alla lista di adiacenza
    struct Vertice *next;           // Puntatore al prossimo vertice (per gestione interna)
} Vertice;

typedef struct Grafo
{
    Vertice *lista_vertici; // Lista concatenata dei vertici del grafo
    int num_vertici;        // Numero totale di vertici
} Grafo;

Vertice *cerca_vertice(Grafo *g, const char *citta);

/**********************************************************************************************

La funzione cerca_vertice ha il compito di individuare il nodo di un grafo associato a una specifica città,
rappresentata come stringa. Riceve in input un puntatore alla struttura del grafo e il nome della città da cercare.
La ricerca si basa sul confronto tra la stringa fornita e i nomi delle città associati ai vertici del grafo.
Se il grafo non utilizza una struttura di supporto per la ricerca, come una tabella hash,
la funzione attraversa la lista concatenata dei vertici del grafo partendo dal primo nodo,
confrontando il nome della città corrente con quello cercato utilizzando una funzione come strcmp.
Quando si trova una corrispondenza, la funzione restituisce un puntatore al vertice corrispondente,
mentre in caso contrario prosegue fino al termine della lista e, se non trova la città, restituisce NULL.
L’attraversamento lineare rende la complessità della ricerca proporzionale al numero di vertici O(V).
Tuttavia, se si integra una tabella hash per mappare direttamente i nomi delle città ai vertici,
la funzione sfrutta questa mappatura per accedere al nodo desiderato in tempo medio O(1).
Questo approccio è più efficiente, soprattutto in grafi con un elevato numero di vertici,
poiché riduce drasticamente il tempo di ricerca rispetto al metodo lineare.

**********************************************************************************************/

/**********************************************************************************************

Fornire una rappresentazione, in linguaggio C, di un grafo pesato non orientato, assumendo che: 1) l’inse-
rimento/la cancellazione dei vertici sia un evento raro; 2) i vertici mediamente abbiano un grado elevato;
3) siano frequenti operazioni di inserimento o di cancellazione di un arco. Si consiglia di individuare la
rappresentazione (lista o matrice di adiacenza) del grafo pi`u adatta al problema, prima di procedere alla
sua realizzazione. Si pu`o assumere che ciascun vertice sia associato al solo indice che lo individua nel grafo:
in altri termini, non `e richiesto prevedere, nella struttura dati proposta, dello spazio per altre informazioni
(ad esempio per una descrizione dellentit`a che il vertice rappresenta). Riportare:

• i costrutti struct (uno o pi`u) necessari alla definizione del grafo, commentando tipo e ruolo di ciascun
membro della struttura;

• il prototipo della funzione di inserimento di un arco, inserisci arco, descrivendone in maniera chiara
il prototipo (tipo di output, tipo argomenti di input) e la logica di funzionamento legata a ciascun
argomento. La funzione NON va implementata (la sua implementazione `e facoltativa). Indicare
inoltre, la complessit`a computazionale della stessa.

`E possibile fare riferimento, laddove lo si ritenga opportuno, sia a strutture dati proposte durante il corso,
che alle funzioni che le utilizzano.

**********************************************************************************************/

typedef struct MatriceAdiacenza
{
    int **dati;     // Puntatore alla matrice di adiacenza
    int dimensione; // Numero di nodi nel grafo (dimensione della matrice)
} MatriceAdiacenza;

typedef struct Grafo
{
    MatriceAdiacenza matrice; // Struttura che incapsula la matrice di adiacenza
} Grafo;

void inserisci_arco(Grafo *g, int vertice1, int vertice2, int peso);

/**********************************************************************************************

La funzione inserisci_arco consente di aggiungere o aggiornare un arco pesato tra due vertici di un grafo non orientato
rappresentato tramite una matrice di adiacenza. La funzione accetta un puntatore alla struttura del grafo,
che contiene la matrice e il numero di vertici, insieme agli indici dei due vertici coinvolti e al peso dell’arco.
Dopo aver verificato che gli indici dei vertici forniti siano validi,
ovvero compresi nell’intervallo tra 0 e g->num_vertici - 1,
la funzione aggiorna i valori corrispondenti nella matrice di adiacenza,
scrivendo il peso fornito sia nell’elemento g->matrice_adiacenza[vertice1][vertice2]
sia nel suo simmetrico g->matrice_adiacenza[vertice2][vertice1], poiché il grafo è non orientato.
Questa struttura consente di modificare rapidamente lo stato dell’arco tra due vertici in tempo costante O(1),
grazie all’accesso diretto agli elementi della matrice.
La funzione non restituisce alcun valore poiché opera direttamente sulla struttura del grafo fornita come argomento,
rendendola efficiente e semplice per l’inserimento o l’aggiornamento di archi in grafi con connessioni dense.

**********************************************************************************************/

/**********************************************************************************************

Fornire una rappresentazione in linguaggio C di un grafo non orientato pesato, utilizzando la rappresenta-
zione basata su liste di adiacenza. Assumere che ciascun vertice non abbia altre informazioni oltre quelle
per rappresentare il grafo. Riportare:

1. i costrutti struct (uno o pi`u) necessari alla definizione del grafo, commentando tipo e ruolo di ciascun
membro di ciascuna struttura;

2. il prototipo della funzione di inserimento di un arco, inserisci arco, descrivendone in maniera puntuale
il prototipo (tipo di output, tipo argomenti di input) e la logica di funzionamento legata a ciascun
argomento. La funzione NON va implementata (la sua implementazione `e facoltativa). Indicare
inoltre, la complessit`a computazionale della stessa.

`E possibile fare riferimento, laddove lo si ritenga opportuno, sia a strutture dati proposte durante il corso,
che alle funzioni che le utilizzano.

**********************************************************************************************/

typedef struct Arco
{
    int vertice;       // Indice del vertice adiacente
    int peso;          // Peso dell'arco
    struct Arco *next; // Puntatore al prossimo arco nella lista
} Arco;

typedef struct ListaAdiacenza
{
    Arco *testa; // Puntatore alla testa della lista degli archi
} ListaAdiacenza;

typedef struct Grafo
{
    int num_vertici;           // Numero totale di vertici
    ListaAdiacenza *adiacenze; // Array di liste di adiacenza
} Grafo;

void inserisci_arco(Grafo *g, int vertice1, int vertice2, int peso);

/**********************************************************************************************

La funzione riceve in input un puntatore alla struttura del grafo,
che contiene il numero di vertici e un array di liste di adiacenza,
insieme agli indici dei due vertici connessi dall’arco e il peso associato. Per prima cosa,
la funzione verifica che gli indici dei vertici siano validi, cioè compresi tra 0 e il numero totale di vertici meno uno.
Successivamente, crea un nuovo nodo Arco per ciascuna delle due liste di adiacenza coinvolte:
un nodo rappresenta l'arco nella lista di vertice1, puntando a vertice2, e l'altro fa lo stesso nella lista di vertice2,
puntando a vertice1, dato che il grafo è non orientato.
Ogni nodo viene inserito in testa alla lista di adiacenza del vertice corrispondente,
garantendo un’inserzione in tempo costante O(1) per ogni operazione.

**********************************************************************************************/

/**********************************************************************************************

Fornire una rappresentazione, in linguaggio C, di un grafo non orientato mediante matrice delle adiacenze.
Ciascun vertice del grafo `e associato oltre a un indice univoco che lo individua nel grafo, anche a una
stringa codice che lo identifica invece all’esterno (sempre in maniera univoca). Si pu`o assumere che il
grafo sia statico (nessun inserimento o cancellazione di vertici). Riportare:

1. una motivazione delle scelte fatte;

2. i costrutti struct (uno o pi`u) necessari alla definizione del grafo, commentando tipo e ruolo di
ciascun membro della struttura;

3. il prototipo della funzione di ricerca di un vertice, cerca vertice, descrivendone in maniera chiara
il prototipo (tipo di output, tipo argomenti di input) e la logica di funzionamento (con specifico
riferimento ai suoi input e relativi membri). La funzione NON va implementata (la sua implementa-
zione `e facoltativa). Indicarne inoltre, la complessit`a`a computazionale.

Per entrambi i punti 1 e 2 `e possibile fare riferimento, laddove lo si ritenga opportuno, sia a strutture
dati proposte durante il corso, che alle funzioni che le utilizzano.

**********************************************************************************************/

typedef struct Vertice
{
    int indice;      // Indice univoco interno del vertice
    char codice[50]; // Codice identificativo univoco esterno del vertice
} Vertice;

typedef struct MatriceAdiacenza
{
    int **dati;     // Matrice di adiacenza
    int dimensione; // Dimensione della matrice (numero di vertici)
} MatriceAdiacenza;

typedef struct Grafo
{
    MatriceAdiacenza matrice; // Struttura che rappresenta la matrice di adiacenza
    Vertice *vertici;         // Array di strutture Vertice
    int num_vertici;          // Numero totale di vertici
} Grafo;

int cercaVertice(Grafo *g, const char *codice);

/**********************************************************************************************

La funzione cerca_vertice è progettata per individuare un vertice in un grafo rappresentato tramite una matrice di adiacenza
e un array di vertici, basandosi sul codice identificativo univoco del vertice.
La funzione riceve come parametri un puntatore alla struttura del grafo e una stringa contenente il codice del vertice da cercare.
Inizia attraversando l’array dei vertici, accessibile tramite il campo vertici della struttura Grafo.
Per ogni elemento dell’array, confronta il campo codice del vertice con la stringa fornita, utilizzando una funzione come strcmp.
Se trova una corrispondenza, restituisce l’indice del vertice,
che può essere utilizzato per accedere alla matrice di adiacenza o ad altre operazioni sul grafo.
Se nessuna corrispondenza viene trovata al termine dell’attraversamento, la funzione restituisce -1,
indicando che il vertice non è presente nel grafo. La complessità temporale della funzione è O(V),
dove V è il numero totale di vertici, poiché richiede un’iterazione lineare sull’array dei vertici.

**********************************************************************************************/

/**********************************************************************************************

Fornire un’implementazione, in linguaggio C, di un grafo non pesato non orientato rappresentato con
matrice di adiacenza. Si pu`o assumere che ciascun nodo del grafo sia associato al solo indice che lo
individua nel grafo: in altri termini, non `e richiesto prevedere, nella struttura dati proposta, dello spazio
per informazioni satellite (ad esempio per una descrizione dell’entit`a che il nodo rappresenta). Riportare:

1. come si vuole realizzare la struttura dati, da un punto di vista astratto, logico (in breve);

2. i costrutti struct (uno o pi`u) necessari alla definizione del grafo, commentando tipo e ruolo di ciascun
membro della struttura;

3. il prototipo della funzione che calcola il grado di un nodo, getDegree, descrivendone in maniera chiara
il prototipo (tipo di output, tipo argomenti di input) e la logica di funzionamento, con specifico
riferimento agli input e ai loro membri per la realizzazione dell’operazione. La funzione NON va
implementata (l’implementazione `e facoltativa). Indicare inoltre, la complessit`a computazionale
della funzione.

Per tutti i punti `e possibile fare riferimento, laddove lo si ritenga opportuno, sia a strutture dati proposte
durante il corso, che alle funzioni che le utilizzano

**********************************************************************************************/

// Il grafo non pesato e non orientato sarà rappresentato tramite una matrice di adiacenza.
// Questa scelta è particolarmente adatta per grafi di dimensioni moderate e per i quali è frequente l’operazione di
// verifica di adiacenza tra due nodi.

typedef struct MatriceAdiacenza
{
    int **dati;     // Puntatore alla matrice bidimensionale di interi
    int dimensione; // Numero di nodi (dimensione della matrice)
} MatriceAdiacenza;

typedef struct Grafo
{
    MatriceAdiacenza matrice; // Struttura che incapsula la matrice di adiacenza
} Grafo;

int getDegree(Grafo *g, int nodo);

/**********************************************************************************************

La funzione getDegree calcola il grado di un nodo in un grafo non orientato rappresentato tramite una matrice di adiacenza.
Riceve come input un puntatore alla struttura Grafo, che incapsula la matrice di adiacenza,
e un intero che rappresenta l’indice del nodo di cui si desidera calcolare il grado.
La funzione accede alla matrice di adiacenza attraverso il campo dati della struttura MatriceAdiacenza contenuta nella struttura Grafo.
Scorre la riga della matrice corrispondente al nodo specificato, sommando i valori di ciascun elemento:
un valore di 1 indica la presenza di un arco tra il nodo specificato e un altro nodo, contribuendo al grado del nodo.
Poiché il grafo è non orientato, la somma dei valori nella riga rappresenta il numero totale di connessioni del nodo,
ossia il suo grado. Infine, la funzione restituisce il risultato della somma. La complessità temporale della funzione è O(n),
dove n è il numero totale di nodi nel grafo, poiché è necessario scorrere l’intera riga della matrice per calcolare il grado.

**********************************************************************************************/
