/**********************************************************************************************

Fornire un’implementazione in C della struttura dati Coda FIFO
Definire la struttura principale e indicare come verrebbe realizzata
l’operazione enqueue
– Analizzarne la complessità

**********************************************************************************************/

// Nodo della coda
typedef struct Nodo
{
    int valore;        // Valore intero contenuto nel nodo
    struct Nodo *next; // Puntatore al nodo successivo
} Nodo;

// Coda
typedef struct Coda
{
    Nodo *front; // Puntatore al primo elemento (fronte)
    Nodo *rear;  // Puntatore all'ultimo elemento (retro)
} Coda;

void enqueue(Coda *q, int nuovo_valore);

/**********************************************************************************************

La funzione enqueue ha il compito di aggiungere un nuovo elemento alla fine di una coda FIFO,
mantenendo l'ordine di inserimento degli elementi. La coda è rappresentata da una struttura con due puntatori:
front, che indica il primo elemento della coda, e rear, che punta all’ultimo elemento.
La funzione riceve due parametri: un puntatore alla struttura Coda, che rappresenta la coda su cui si opera,
e un valore intero nuovo_valore, che rappresenta il dato da inserire.

La funzione inizia allocando dinamicamente memoria per un nuovo nodo.
Questo nodo viene inizializzato con il valore fornito tramite nuovo_valore, e il suo puntatore next viene impostato a NULL,
poiché sarà il nuovo ultimo elemento della coda. Successivamente,
la funzione verifica se la coda è vuota controllando se rear è nullo. Se la coda è vuota, il nuovo nodo viene assegnato sia a front che a rear, rendendolo l’unico elemento della coda. In caso contrario, il nuovo nodo viene collegato al nodo attualmente indicato da rear, e poi il puntatore rear viene aggiornato per riferirsi al nuovo nodo.

Questa operazione avviene in tempo costante, O(1),
poiché richiede soltanto l’allocazione di memoria e l’aggiornamento di alcuni puntatori,
indipendentemente dal numero di elementi nella coda.
Inoltre, la funzione utilizza una quantità fissa di memoria aggiuntiva per il nuovo nodo,
rendendola efficiente sia in termini di spazio che di tempo.

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