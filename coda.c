/**********************************************************************************************

Fornire un’implementazione in C della struttura dati Coda FIFO
Definire la struttura principale e indicare come verrebbe realizzata
l’operazione enqueue
– Analizzarne la complessità

**********************************************************************************************/

typedef struct Elemento
{
    int valore; // Dato dell'elemento della coda
} Elemento;

typedef struct Nodo
{
    Elemento elemento; // Dati dell'elemento incapsulati nella struttura Elemento
    struct Nodo *next; // Puntatore al prossimo nodo nella coda
} Nodo;

typedef struct Coda
{
    Nodo *testa;    // Puntatore al primo nodo della coda (da cui avviene la rimozione)
    Nodo *coda;     // Puntatore all’ultimo nodo della coda (dove avviene l’inserimento)
    int dimensione; // Numero totale di elementi nella coda
} Coda;

void enqueue(Coda *q, Elemento elemento);

/**********************************************************************************************

La funzione enqueue ha il compito di inserire un nuovo elemento in una coda FIFO implementata come lista concatenata. 
La funzione riceve come parametri un puntatore alla struttura della coda e una struttura Elemento che incapsula i dati 
dell’elemento da aggiungere. In primo luogo, viene creato un nuovo nodo Nodo, allocando dinamicamente memoria e inizializzandone 
i campi: il campo elemento viene popolato con i dati forniti e il campo next viene impostato a NULL, 
poiché il nuovo nodo sarà posizionato alla fine della coda. La funzione controlla quindi lo stato della coda. 
Se la coda è vuota, ossia se il puntatore testa è nullo, il nuovo nodo viene impostato come sia la testa che la coda della coda. 
Altrimenti, il nuovo nodo viene collegato al nodo attualmente in coda tramite il puntatore next del nodo precedente, 
e il puntatore coda della struttura della coda viene aggiornato per riferirsi al nuovo nodo. 
Infine, il campo dimensione della struttura Coda viene incrementato per riflettere l’aggiunta del nuovo elemento. 
La complessità temporale di questa operazione è O(n), poiché l’inserimento nel caso peggiore deve scorrere tutta la coda.

**********************************************************************************************/

/**********************************************************************************************

Fornire in linguaggio C un’implementazione della struttura dati coda di priorità
minima. Si assuma che gli elementi della coda siano generici tipi, contenenti tra
le varie informazioni anche una priorità. Per chiarezza, l’aggettivo “minima”
indica che ad ogni estrazione di un elemento della coda viene sempre estratto
quello che ha il campo priorita minimo, tra tutti gli elementi presenti al momento
nella coda. Riportare:

1. come si vuole realizzare la struttura dati, cioè servendosi di quali altre
strutture dati e come (in breve);

2. i costrutti struct (uno o più) necessari alla definizione in C della coda,
commentando tipo e ruolo di ciascun membro della struttura;

3. il prototipo in C della funzione insert(Q, e), che inserisca nella coda di
priorità minima Q l’elemento e. Descrivere concettualmente i passi della
funzione, le operazioni fatte su Q ed e oppure sui loro membri per la
realizzazione dell’operazione, e anche le eventuali modifiche apportate agli
stessi. Tale funzione non va implementata in C.

Accennare alla complessità della funzione stessa asumendo che nella coda al
momento della chiamata ci siano n elementi.

**********************************************************************************************/

// La coda di priorità minima sarà implementata utilizzando un heap binario minimo, 
// rappresentato come un array dinamico.

// Struttura per rappresentare un elemento generico della coda
typedef struct Elemento
{
    void *dato;   // Puntatore a un dato generico
    int priorita; // Valore della priorità associata all'elemento
} Elemento;

// Struttura per rappresentare la coda di priorità
typedef struct CodaPriorita
{
    Elemento *heap; // Array di elementi (heap binaria)
    int capacita;   // Capacità massima della coda
    int dimensione; // Numero attuale di elementi nella coda
} CodaPriorita;

void insert(CodaPriorita *Q, Elemento e);

/**********************************************************************************************

La funzione insert permette di aggiungere un nuovo elemento a una coda di priorità minima rappresentata come una heap binaria,
mantenendo intatta la proprietà di priorità minima. La coda è implementata tramite un array,
in cui ogni nodo rappresenta un elemento con un campo generico dato e un campo intero priorita.
La funzione riceve due parametri: un puntatore alla struttura CodaPriorita, che rappresenta la coda, e l’elemento e da inserire.

L’operazione inizia verificando se c’è spazio nella coda confrontando la dimensione attuale con la capacità massima.
Se la coda è piena, è necessario espandere la capacità dell’array o gestire l’errore.
Successivamente, l’elemento viene aggiunto in fondo alla heap, in corrispondenza dell’indice pari alla dimensione corrente.
Dopo l’inserimento, la dimensione della coda viene incrementata per riflettere l’aggiunta.

Per mantenere la proprietà della heap binaria minima, l’elemento appena inserito viene confrontato con il suo genitore (DecreaseKey).
Se la priorità dell’elemento è inferiore a quella del genitore, i due nodi vengono scambiati.
Questo confronto e scambio prosegue iterativamente finché l’elemento non raggiunge una posizione in cui
la sua priorità è maggiore o uguale a quella del genitore, oppure finché non diventa la radice della heap.

La complessità temporale della funzione è O(log n),
poiché il numero di confronti e scambi necessari è proporzionale all’altezza della heap,
che cresce logaritmicamente rispetto al numero di elementi nella coda.
La funzione utilizza una quantità costante di memoria aggiuntiva, rendendola efficiente in termini di spazio.

**********************************************************************************************/

/**********************************************************************************************

Fornire in linguaggio C l’implementazione della struttura dati coda. Si ricorda che la coda realizza una
politica First In, First Out (FIFO).
Riportare:

1. i costrutti struct (uno o pi`u) necessari alla definizione del coda, commentando tipo e ruolo di ciascun
membro della struttura;

2. il prototipo in C della funzione enqueue(Q, elem), che inserisca nella coda Q l’elemento elem. Si
pu`o assumere per comodit`a che la coda contenga interi. Descrivere concettualmente i passi della
funzione, le operazioni fatte su Q e sui suoi membri per la realizzazione dell’operazione, e le eventuali
modifiche apportate agli stessi. La definizione in C della funzione `e FACOLTATIVA.

Accennare alla complessit`a della funzione stessa assumendo che nella coda al momento della chiamata ci
siano n elementi.

**********************************************************************************************/

typedef struct Nodo
{
    int valore;        // Valore dell'elemento nella coda
    struct Nodo *next; // Puntatore al prossimo nodo nella coda
} Nodo;

typedef struct Coda
{
    Nodo *testa;   // Puntatore al primo elemento della coda
    Nodo *coda;    // Puntatore all'ultimo elemento della coda
    int lunghezza; // Numero totale di elementi nella coda
} Coda;

void enqueue(Coda *Q, int elem);

/**********************************************************************************************

La funzione enqueue serve per aggiungere un elemento alla coda, rispettando la politica FIFO (First In, First Out).
La funzione riceve in input un puntatore alla struttura della coda e l’elemento da inserire.
Inizia allocando dinamicamente un nuovo nodo e inizializzando i suoi campi:
il valore del nodo viene impostato all’elemento fornito in input, mentre il puntatore next viene impostato a NULL,
poiché il nuovo nodo sarà l’ultimo elemento della coda. Se la coda è vuota, cioè se il puntatore testa è NULL,
il nuovo nodo diventa sia la testa che la coda della coda, aggiornando entrambi i puntatori nella struttura.
Se invece la coda contiene già elementi, la funzione collega il nuovo nodo alla fine della coda aggiornando il puntatore
next dell’attuale ultimo nodo e sposta il puntatore coda per riferirsi al nuovo nodo.
Alla fine, la funzione incrementa il campo lunghezza per riflettere l’aumento del numero di elementi nella coda.
L’operazione è altamente efficiente, con una complessità temporale di O(1),
poiché l’inserimento viene eseguito direttamente utilizzando il puntatore alla coda senza dover attraversare la struttura.

**********************************************************************************************/

/**********************************************************************************************

GIA USCITO

Fornire in linguaggio C un’implementazione della struttura dati coda di priorit`a minima. Si assuma che
gli elementi della coda siano generici tipi elem, immaginandoli come strutture con, tra l’altro, un membro
priorita. Per chiarezza, laggettivo “minima” indica che ad ogni estrazione di un elemento della coda viene
sempre estratto quello che ha il campo priorita minimo, tra tutti gli elementi presenti al momento nella
coda.
Riportare:

1. come si vuole realizzare la struttura dati, cio`e servendosi di quali altre strutture dati e come (in
breve);
2. i costrutti struct (uno o pi`u) necessari alla definizione in C della coda, commentando tipo e ruolo di
ciascun membro della struttura;

3. il prototipo in C della funzione insert(Q, e), che inserisca nella coda di priorit`a minima Q lelemento
e. Descrivere concettualmente i passi della funzione, le operazioni fatte su Q ed e o sui loro membri
per la realizzazione dell’operazione, e le eventuali modifiche apportate agli stessi. Tale funzione non
va implementata in C.

Accennare alla complessit della funzione stessa asumendo che nella coda al momento della chiamata ci
siano n elementi.

**********************************************************************************************/

typedef struct
{
    int priorita; // Valore della priorità (elemento determinante nell'ordinamento)
    // Altri membri dell'elemento possono essere aggiunti qui
} Elem;

typedef struct
{
    Elem *elementi; // Array dinamico per memorizzare gli elementi
    int capacita;   // Capacità massima dell'array
    int dimensione; // Numero attuale di elementi nella coda
} PriorityQueue;

void insert(PriorityQueue *Q, Elem e);

/**********************************************************************************************

La funzione insert ha il compito di aggiungere un elemento alla coda di priorità minima, mantenendo la proprietà dell’heap binario.
La funzione inizia verificando se l’array che rappresenta la coda ha spazio sufficiente per accogliere il nuovo elemento;
se la capacità massima è stata raggiunta, la funzione alloca dinamicamente più memoria per espandere l’array.
Successivamente, l’elemento viene inserito in fondo all’array, incrementando il numero di elementi attualmente presenti nella coda.
Questo inserimento temporaneo potrebbe violare la proprietà dell’heap, quindi la funzione esegue un’operazione di "heapify-up",
risalendo l’albero binario rappresentato dall’array.
Durante questa operazione, il nuovo elemento viene confrontato con il suo genitore (determinato dalla formula (i−1)/2, d
ove ii è l’indice corrente) e, se ha una priorità inferiore, viene scambiato con il genitore.
Questo processo si ripete fino a quando il nuovo elemento si trova in una posizione che rispetta la proprietà dell’heap,
ovvero dove il genitore ha una priorità minore o uguale alla sua.
La complessità dell’intera operazione è O(log⁡n), dove n è il numero di elementi nella coda,
poiché la risalita nell’heap è proporzionale all’altezza dell’albero.

**********************************************************************************************/

/**********************************************************************************************

Fornire una rappresentazione, in linguaggio C, di un coda FIFO. Ciascun elemento della coda `e associato ad un intero
indice e ad una stringa alfanumerica info. Riportare:

1. come si intende implementare la coda;

2. i costrutti struct (uno o pi`u) necessari alla definizione della stessa, commentando tipo e ruolo di ciascun
membro della struttura;

3. il prototipo della funzione enqueue per l’inserimento di un elemento in coda, descrivendone in maniera chiara il
prototipo (tipo di output, tipo argomenti di input) e la logica di funzionamento (con specifico riferimento ai suoi input
e relativi membri). La funzione NON va implementata (la sua implementazione `e facoltativa). Indicarne
inoltre, la complessit`a computazionale.

Per tutti i punti `e possibile fare riferimento, laddove lo si ritenga opportuno, sia a strutture dati proposte durante
il corso, che alle funzioni che le utilizzano.

**********************************************************************************************/

typedef struct Nodo
{
    int indice;        // Indice associato all'elemento
    char info[100];    // Stringa alfanumerica associata all'elemento
    struct Nodo *next; // Puntatore al prossimo nodo nella coda
} Nodo;

typedef struct Coda
{
    Nodo *testa;   // Puntatore al primo elemento della coda
    Nodo *coda;    // Puntatore all'ultimo elemento della coda
    int lunghezza; // Numero totale di elementi nella coda
} Coda;

void enqueue(Coda *c, int indice, const char *info);

/**********************************************************************************************

La funzione enqueue è progettata per inserire un nuovo elemento in una coda FIFO rappresentata tramite una lista concatenata.
Riceve come parametri un puntatore alla struttura della coda, un intero che rappresenta l’indice del nuovo elemento,
e una stringa alfanumerica associata a tale elemento.
La funzione inizia allocando dinamicamente un nuovo nodo Nodo, inizializzando i campi del nodo con i valori forniti in input:
il campo indice viene impostato al valore dell’intero passato,
la stringa info viene copiata nel campo corrispondente,
e il puntatore next viene impostato a NULL, poiché il nuovo nodo sarà l’ultimo elemento della coda.
Successivamente, la funzione verifica se la coda è vuota controllando il puntatore testa:
se la coda è vuota, il nuovo nodo diventa sia la testa che la coda della coda.
Altrimenti, il nuovo nodo viene aggiunto in fondo alla lista concatenata,
aggiornando il puntatore next dell’ultimo nodo attuale (indicato da coda) e spostando il puntatore coda per riferirsi al nuovo nodo.
Infine, il campo lunghezza della struttura Coda viene incrementato per riflettere l’aggiunta del nuovo elemento.
Grazie a questa organizzazione, la funzione enqueue garantisce un’inserzione in tempo costante O(1)

**********************************************************************************************/

/**********************************************************************************************

Fornire una rappresentazione in linguaggio C di una coda FIFO, i cui elementi siano formati da 3 campi:
descrizione (stringa), codice (intero), coeciente (numero in virgola mobile). Si pu`o assumere, se dovesse
servire, che il campo codice sia univoco. Riportare:

1. Una breve descrizione circa come si intende implementare la coda;

2. i costrutti struct (uno o pi`u) necessari alla definizione della stessa, commentando tipo e ruolo di
ciascun membro della struttura;

3. il prototipo della funzione enqueue, che inserisce un nuovo elemento in coda, descrivendone in maniera
chiara il prototipo (tipo di output, tipo argomenti di input) e la logica di funzionamento rispetto ai
suoi argomenti. La funzione NON va implementata (la sua implementazione `e facoltativa);

4. l’analisi di complessit`a della funzione stessa.

Per tutti i punti `e possibile fare riferimento, laddove lo si ritenga opportuno, sia a strutture dati proposte
durante il corso, che alle funzioni che le utilizzano.

**********************************************************************************************/

typedef struct Dati
{
    char descrizione[100]; // Stringa descrittiva dell'elemento
    int codice;            // Codice univoco associato all'elemento
    float coefficiente;    // Valore in virgola mobile associato all’elemento
} Dati;

typedef struct Nodo
{
    Dati dati;         // Struttura che contiene i dati dell'elemento
    struct Nodo *next; // Puntatore al prossimo nodo nella coda
} Nodo;

typedef struct Coda
{
    Nodo *testa;   // Puntatore al primo nodo della coda
    Nodo *coda;    // Puntatore all’ultimo nodo della coda
    int lunghezza; // Numero totale di elementi nella coda
} Coda;

void enqueue(Coda *c, Dati dati);

/**********************************************************************************************

La funzione enqueue ha il compito di inserire un nuovo elemento alla fine di una coda FIFO rappresentata tramite una lista concatenata.
La funzione riceve come parametri un puntatore alla struttura Coda e una struttura Dati che incapsula i valori del nuovo elemento,
tra cui una descrizione (stringa), un codice univoco (intero) e un coefficiente (numero in virgola mobile).
Per prima cosa, la funzione alloca dinamicamente memoria per un nuovo nodo Nodo.
I valori contenuti nella struttura Dati vengono copiati nel campo dati del nodo, e il puntatore next viene impostato a NULL,
poiché il nuovo nodo sarà l’ultimo della coda.
Successivamente, la funzione controlla se la coda è vuota esaminando il puntatore testa.
Se la coda è vuota, il nuovo nodo viene impostato sia come testa che come coda della coda.
Se invece la coda contiene già elementi, la funzione aggiorna il puntatore next dell’attuale ultimo nodo affinché
punti al nuovo nodo, e sposta il puntatore coda della struttura Coda per riferirsi al nuovo nodo.
Infine, il campo lunghezza della coda viene incrementato per riflettere l’aggiunta di un nuovo elemento.
Grazie a questa organizzazione, la funzione garantisce un inserimento in tempo costante O(1),
mantenendo l’efficienza della coda anche in presenza di un numero elevato di elementi.

**********************************************************************************************/

/**********************************************************************************************

Fornire in linguaggio C un”implementazione della struttura dati coda di priorit`a minima. Ogni elemento,
oltre ad una priorit`a intera, contiene anche dei dati satellite, nello specifico una nome (stringa) e un
identificativo (stringa). Per chiarezza, l’aggettivo “minima” indica che ad ogni estrazione di un elemento
della coda viene sempre estratto quello che ha il campo priorit`a minimo, tra tutti gli elementi presenti al
momento nella coda. Riportare:

1. come si vuole realizzare la struttura dati, da un punto di vista astratto, logico (in breve);

2. i costrutti struct (uno o pi`u) necessari alla definizione in C della coda di priorit`a, commentando tipo
e ruolo di ciascun membro della struttura;

3. il prototipo in C della funzione extractMin, che che estrae dalla coda di priorit`a l’elemento che ha
priorit`a minima. Descrivere concettualmente i passi della funzione, facendo specifico riferimento agli
input e ai loro membri per la realizzazione dell’operazione. Tale funzione non va implementata in C.

Accennare anche alla complessit`a della funzione stessa, assumendo che nella coda al momento della
chiamata ci siano n elementi.

**********************************************************************************************/

// La coda di priorità minima sarà realizzata utilizzando un heap binario minimo rappresentato tramite un array dinamico.

typedef struct Dati
{
    char nome[50];           // Nome associato all'elemento
    char identificativo[50]; // Identificativo unico dell'elemento
} Dati;

typedef struct Elemento
{
    int priorita; // Priorità dell'elemento (utilizzata per l'ordinamento)
    Dati dati;    // Dati satellite associati all'elemento
} Elemento;

typedef struct PriorityQueue
{
    Elemento *heap; // Array dinamico che rappresenta gli elementi nell'heap binario
    int capacita;   // Capacità massima dell'array
    int dimensione; // Numero di elementi attualmente presenti nell'heap
} PriorityQueue;

Elemento extractMin(PriorityQueue *pq);

/**********************************************************************************************

La funzione extractMin ha il compito di estrarre dalla coda di priorità minima l’elemento con la priorità più bassa,
preservando la proprietà dell’heap binario minimo.
La funzione riceve come parametro un puntatore alla struttura PriorityQueue, che rappresenta la coda di priorità.
Per prima cosa, verifica se la coda è vuota controllando il valore del campo dimensione; in caso affermativo,
restituisce un valore indicativo di errore o gestisce l’eccezione.
L’elemento minimo si trova sempre nella radice dell’heap, corrispondente al primo elemento dell’array heap (indice 0).
Questo elemento viene salvato per essere restituito al termine della funzione.
Successivamente, l’ultimo elemento dell’heap viene spostato nella posizione 0, e la funzione esegue un’operazione di "heapify-down"
per ripristinare la proprietà dell’heap: il nuovo elemento viene confrontato con i suoi figli,
scambiandolo con il figlio più piccolo se necessario, fino a raggiungere una posizione che soddisfa la proprietà dell’heap
binario minimo. Infine, il campo dimensione della coda viene decrementato per riflettere la rimozione dell’elemento.
La complessità temporale dell’operazione è O(log⁡n), dove n è il numero di elementi nella coda,
poiché la riorganizzazione dell’heap coinvolge al massimo l’altezza dell’albero binario.

**********************************************************************************************/
