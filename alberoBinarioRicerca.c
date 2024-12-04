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

/**********************************************************************************************

Fornire una rappresentazione in linguaggio C di un albero binario di ricerca in cui la chiave sia una
stringa. Fornire inoltre il prototipo della funzione bst search, che esegue la ricerca nell’albero di una data
stringa. Riportare i costrutti struct (uno o pi`u) necessari alla definizione dell’albero binario di ricerca,
commentando brevemente il tipo e il ruolo di ciascun membro della struttura.
E' possibile fare riferimento, laddove lo si ritenga opportuno, sia a strutture dati proposte durante il corso,
che alle funzioni che le utilizzano.

**********************************************************************************************/

typedef struct Chiave
{
    char stringa[50]; // Chiave di ricerca: stringa di massimo 50 caratteri
} Chiave;

typedef struct Nodo
{
    Chiave chiave;         // Stringa che rappresenta la chiave del nodo
    struct Nodo *sinistro; // Puntatore al figlio sinistro
    struct Nodo *destro;   // Puntatore al figlio destro
} Nodo;

typedef struct BST
{
    Nodo *radice; // Puntatore alla radice dell'albero
} BST;

Nodo *bst_search(BST *albero, const char *chiave);

/**********************************************************************************************

La funzione bst_search esegue la ricerca di una chiave all’interno di un albero binario di ricerca.
La ricerca sfrutta la proprietà fondamentale dell’albero binario di ricerca,
che garantisce che per ogni nodo tutte le chiavi nel suo sottoalbero sinistro siano inferiori alla chiave del nodo stesso
e tutte quelle nel sottoalbero destro siano superiori, considerando un confronto lessicografico nel caso delle stringhe.
La funzione inizia dalla radice dell’albero, accedibile tramite il puntatore albero->radice,
e confronta la chiave cercata con la chiave del nodo corrente. Se le due chiavi coincidono,
la funzione restituisce un puntatore al nodo contenente la chiave cercata. In caso contrario,
se la chiave cercata è minore della chiave del nodo corrente,
la funzione si sposta ricorsivamente o iterativamente nel sottoalbero sinistro;
se invece la chiave è maggiore, prosegue nel sottoalbero destro.
Se durante la discesa nell’albero si raggiunge un nodo nullo (NULL),
significa che la chiave non è presente nell’albero e la funzione restituisce NULL.
La ricerca è efficiente, poiché esplora solo una parte dell’albero,
e la sua complessità temporale dipende dall’altezza dell’albero, risultando O(h),
dove h è l’altezza. In un albero bilanciato, questa complessità è logaritmica rispetto al numero di nodi,
mentre in un albero sbilanciato può diventare lineare

**********************************************************************************************/

/**********************************************************************************************

Fornire una rappresentazione, in linguaggio C, di un albero binario di ricerca, assumendo che la chiave
di ricerca sia composta da una stringa. L’ordine totale sulle chiavi `e dato dall’ordine lessicografico delle
stringhe. Rendere la definizione dell’albero indipendente dal tipo di chiave. Riportare:

1. i costrutti struct (uno o pi`u) necessari alla definizione dellalbero binario di ricerca, commentando
tipo e ruolo di ciascun membro di ogni struttura;

2. il prototipo della funzione check branch (tipo di output, tipo argomenti di input), che preso in input
un nodo dell’albero e una chiave k, confronti k con quella contenuta nel nodo e restituisca un intero
indicante lesito del confronto:

0, k `e minore oppure le chiavi sono uguali;

1, k `e maggiore.

Limplementazione in C di tale funzione `e FACOLTATIVA, ma ne va descritta la logica di funziona-
mento in relazione a ciascun argomento.
`E possibile fare riferimento, laddove lo si ritenga opportuno, sia a strutture dati proposte durante il
corso, che alle funzioni che le utilizzano.

**********************************************************************************************/

typedef struct Chiave
{
    void *valore; // Puntatore generico al valore della chiave
} Chiave;

typedef struct Nodo
{
    Chiave *chiave;        // Puntatore alla chiave associata al nodo
    struct Nodo *sinistro; // Puntatore al figlio sinistro
    struct Nodo *destro;   // Puntatore al figlio destro
} Nodo;

typedef struct BST
{
    Nodo *radice;                   // Puntatore alla radice dell'albero
    int (*compara)(void *, void *); // Puntatore alla funzione di confronto per le chiavi
} BST;

int check_branch(Nodo *nodo, Chiave *k, int (*compara)(void *, void *));

/**********************************************************************************************

La funzione check_branch si occupa di confrontare una chiave generica con quella contenuta in un nodo dell’albero binario di ricerca,
utilizzando una funzione di confronto fornita come parametro.
La funzione accetta un puntatore al nodo da verificare, un puntatore alla chiave da confrontare e un puntatore a una funzione di confronto generica.
In primo luogo, verifica che il nodo non sia nullo; se il nodo è nullo, restituisce un valore di errore,
come -1, per indicare che il confronto non può essere effettuato.
In caso contrario, richiama la funzione di confronto passando i valori della chiave da verificare e della chiave contenuta nel nodo.
La funzione di confronto restituisce un intero:
un valore positivo se la chiave in input è maggiore di quella del nodo,
zero se le chiavi sono uguali o è minore.
Questo approccio permette di mantenere il codice dell’albero generico e indipendente dal tipo di chiave,
delegando il confronto alla funzione fornita dall’utente, garantendo così flessibilità e compatibilità con vari tipi di dati.
La complessità della funzione dipende dalla funzione di confronto, e per stringhe lessicografiche è proporzionale alla lunghezza della stringa,
cioè O(L)O, dove L è la lunghezza della stringa più lunga tra quelle confrontate.

**********************************************************************************************/

/**********************************************************************************************

Fornire una rappresentazione, in linguaggio C, di un albero binario di ricerca, assumendo che la chiave di
ricerca sia composta da una coppia di numeri interi (x, y). L’ordine sulle chiavi `e dato prima dall’ordine ≤
su x, poi, a parit`a di x, dall’ordine ≤ su y. L’implementazione deve fornire un’astrazione sia del concetto
di chiave che di quello di nodo dell’albero.
Riportare:

1. i costrutti struct (uno o eventualmente pi`u) necessari alla definizione dell’albero binario di ricerca,
commentando tipo e ruolo di ciascun membro di ciascuna struttura;

2. il prototipo della funzione compare node, indicando tipo di output e tipo argomenti di input, che
presi in input due nodi, ne confronti le chiavi e restituisca un intero indicante l’esito del confronto.
L’implementazione di tale funzione `e facoltativa, ma ne va descritta la logica di funzionamento in
relazione a ciascun argomento.

`E possibile fare riferimento, laddove lo si ritenga opportuno, sia a strutture dati proposte durante il corso,
che alle funzioni che le utilizzano

**********************************************************************************************/

typedef struct Chiave
{
    int x; // Primo valore della chiave
    int y; // Secondo valore della chiave
} Chiave;

typedef struct Nodo
{
    Chiave chiave;         // Chiave associata al nodo
    struct Nodo *sinistro; // Puntatore al figlio sinistro
    struct Nodo *destro;   // Puntatore al figlio destro
} Nodo;

typedef struct BST
{
    Nodo *radice; // Puntatore alla radice dell'albero
} BST;

int compare_node(Nodo *nodo1, Nodo *nodo2);

/**********************************************************************************************

La funzione compare_node confronta le chiavi associate a due nodi di un albero binario di ricerca,
dove ciascuna chiave è composta da una coppia di numeri interi (x,y).
Il confronto segue una gerarchia: prima viene valutato il valore xx, e in caso di uguaglianza, viene valutato il valore y.
La funzione inizia confrontando i valori x delle chiavi dei due nodi.
Se il valore x del primo nodo è minore di quello del secondo, la funzione restituisce -1; se è maggiore, restituisce 1.
Se i valori x sono uguali, la funzione procede al confronto dei valori y:
se il valore y del primo nodo è minore di quello del secondo, restituisce -1; se è maggiore, restituisce 1.
Infine, se entrambi i valori x e y sono uguali, la funzione restituisce 0.
Questa logica garantisce un confronto coerente con l'ordine stabilito per l’albero binario di ricerca.
Poiché la funzione esegue solo confronti tra coppie di interi, la sua complessità temporale è O(1)

**********************************************************************************************/

/**********************************************************************************************

Fornire una rappresentazione, in linguaggio C, di un albero binario di ricerca. Si assuma che:

• i nodi dell’albero contengano tra le altre informazioni, una chiave e tre campi: nome (stringa), cognome (stringa)
ed et`a (intero);

• la chiave sia composta da un numero reale.

Si richiede di riportare:

1. i costrutti struct (uno o pi`u) necessari alla definizione dell’albero, commentando tipo e ruolo di ciascun membro
della struttura;

2. il prototipo della funzione di ricerca di un elemento, cerca nodo, descrivendone in maniera chiara il prototipo
(tipo di output, tipo argomenti di input) e la logica di funzionamento rispetto ai suoi argomenti. La funzione
NON va implementata (la sua implementazione `e facoltativa);

3. l’analisi di complessit`a della funzione cerca nodo.

Per tutti i punti `e possibile fare riferimento, laddove lo si ritenga opportuno, sia a strutture dati proposte durante il
corso, che alle funzioni che le utilizzano.

**********************************************************************************************/

typedef struct Chiave
{
    double valore; // Chiave di ricerca del nodo (numero reale)
} Chiave;

typedef struct Dati
{
    char nome[50];    // Nome associato al nodo
    char cognome[50]; // Cognome associato al nodo
    int eta;          // Età associata al nodo
} Dati;

typedef struct Nodo
{
    Chiave chiave;         // Struttura che incapsula la chiave del nodo
    Dati dati;             // Struttura che contiene i dati associati al nodo
    struct Nodo *sinistro; // Puntatore al figlio sinistro
    struct Nodo *destro;   // Puntatore al figlio destro
} Nodo;

typedef struct BST
{
    Nodo *radice; // Puntatore alla radice dell'albero
} BST;

Nodo *cerca_nodo(Nodo *radice, Chiave chiave);

/**********************************************************************************************

La funzione cerca_nodo è progettata per cercare un nodo specifico in un albero binario di ricerca (BST),
basandosi su una chiave di tipo double.
La funzione riceve come parametri un puntatore alla radice del sottoalbero in cui eseguire la ricerca e la chiave da trovare,
incapsulata nella struttura Chiave. Il funzionamento della funzione si basa su confronti ricorsivi:
in primo luogo, verifica se il nodo corrente (indicato dal puntatore alla radice) è nullo;
se lo è, restituisce NULL, indicando che la chiave non è presente nell'albero.
Se il nodo corrente non è nullo, confronta la chiave fornita in input con quella del nodo corrente.
Se le chiavi sono uguali, restituisce un puntatore al nodo trovato.
Se la chiave cercata è minore della chiave del nodo corrente, la funzione viene richiamata ricorsivamente sul figlio sinistro del nodo.
Al contrario, se la chiave cercata è maggiore, la funzione si sposta ricorsivamente sul figlio destro.
Questo processo continua fino a quando viene trovato un nodo con la chiave corrispondente o si raggiunge un nodo nullo.
La complessità temporale della funzione dipende dall’altezza dell’albero: nel caso migliore, con un albero bilanciato,
la complessità è O(log⁡n), mentre nel caso peggiore, con un albero completamente sbilanciato, la complessità diventa O(n),
dove n è il numero di nodi.

**********************************************************************************************/

/**********************************************************************************************

Fornire una rappresentazione, in linguaggio C, di un albero binario di ricerca avente la seguenti caratteristiche:

• i nodi dell’albero hanno una chiave composta da due stringhe, str1 e str2. La relazione d’ordine totale ≤
sulle chiavi `e data dall’ordinamento lessicografico di str1, e a parit`a di ordinamento str1, dall’ordinamento
lessicografico di str2 ;

• Ogni nodo ha due campi satellite: descrizione (stringa), valore (intero).
Riportare:

1. come si intende implementare l’albero binario di ricerca;

2. i costrutti struct (uno o pi`u) necessari alla definizione dell’albero, commentando tipo e ruolo di ciascun membro
della struttura;

3. il prototipo della funzione di ricerca di un elemento, cerca nodo, descrivendone in maniera chiara il prototipo
(tipo di output, tipo argomenti di input) e la logica di funzionamento rispetto ai suoi argomenti. La funzione
NON va implementata (la sua implementazione `e facoltativa);

4. l’analisi di complessit`a della funzione cerca nodo.

Per tutti i punti `e possibile fare riferimento, laddove lo si ritenga opportuno, sia a strutture dati proposte durante il
corso, che alle funzioni che le utilizzano.

**********************************************************************************************/

typedef struct Chiave
{
    char str1[50]; // Prima stringa della chiave (principale)
    char str2[50]; // Seconda stringa della chiave (secondaria)
} Chiave;

typedef struct Dati
{
    char descrizione[100]; // Stringa descrittiva associata al nodo
    int valore;            // Valore intero associato al nodo
} Dati;

typedef struct Nodo
{
    Chiave chiave;         // Chiave composta da due stringhe
    Dati dati;             // Dati satellite associati al nodo
    struct Nodo *sinistro; // Puntatore al figlio sinistro
    struct Nodo *destro;   // Puntatore al figlio destro
} Nodo;

typedef struct BST
{
    Nodo *radice; // Puntatore alla radice dell’albero
} BST;

Nodo *cerca_nodo(Nodo *radice, Chiave chiave);

/**********************************************************************************************

La funzione cerca_nodo è progettata per individuare un nodo specifico in un albero binario di ricerca (BST),
utilizzando una chiave composta da due stringhe, str1 e str2.
La funzione riceve come parametri un puntatore alla radice del sottoalbero in cui eseguire la ricerca
e una struttura Chiave che incapsula i valori delle stringhe da confrontare. Il funzionamento della funzione si basa su confronti
successivi: in primo luogo, verifica se il nodo corrente (indicato dal puntatore radice) è nullo;
se lo è, restituisce NULL, indicando che la chiave cercata non è presente nell’albero.
Successivamente, confronta la chiave fornita con quella del nodo corrente, utilizzando l’ordine lessicografico:
se str1 della chiave cercata è minore di str1 del nodo, la funzione prosegue ricorsivamente sul figlio sinistro;
se è maggiore, si sposta sul figlio destro.
In caso di uguaglianza su str1, il confronto passa a str2: se str2 è minore, si esplora il sottoalbero sinistro;
se è maggiore, si esplora il sottoalbero destro; se entrambe le stringhe coincidono,
la funzione restituisce il puntatore al nodo corrente.
Questo processo continua fino a trovare il nodo con la chiave corrispondente o raggiungere un nodo nullo.
La complessità temporale della funzione dipende dall’altezza dell’albero:
è O(log⁡n) in un albero bilanciato e O(n) in un albero completamente sbilanciato, dove nn è il numero totale di nodi.

**********************************************************************************************/

/**********************************************************************************************

ESAME MISTICO 03/07/2024

Fornire un’implementazione, in linguaggio C, di un albero binario di ricerca, dove ciascun nodo contiene
l’informazione di un utente, a sua volta abbinato a un codice fiscale (una stringa) e ad una residenza.
Quest’ultima `e individuata da una coppia di numeri reali (x, y) appartententi a RxR , che ne rappresentano le coordinate
geografiche. L’ordine sugli utenti `e dato dall’ordine lessicografico dei loro codici fiscali. Riportare:

1. come si vuole realizzare la struttura dati, da un punto di vista astratto, logico (in breve);

2. i costrutti struct (uno o pi`u) necessari alla definizione dell’albero, commentando tipo e ruolo di
ciascun membro della struttura;

3. il prototipo della funzione minima distanza, che trovi l’utente la cui residenza sia la pi`u vicina a un
dato punto di input D (congruo) (Xd ; Yd ). Come distanza consideriamo la distanza Euclidea d E tra i due
punti. Quindi, dato un utente u, la sua distanza dal punto D `e

                    dE((Xu, Yu),(Xd, Yd))

Descrivere, in maniera chiara, il prototipo della funzione (tipo di output, tipo argomenti di input) e
la logica di funzionamento, con specifico riferimento agli input e ai loro membri per la realizzazione
dell’operazione. La funzione NON va implementata. Indicare inoltre la complessit`a computazionale
della stessa.

Per tutti i punti `e possibile fare riferimento, laddove lo si ritenga opportuno, sia a strutture dati proposte
durante il corso, che alle funzioni che le utilizzano.

**********************************************************************************************/

typedef struct Residenza
{
    double x; // Coordinata geografica x della residenza
    double y; // Coordinata geografica y della residenza
} Residenza;

typedef struct Utente
{
    char codice_fiscale[17]; // Codice fiscale univoco (16 caratteri + terminatore)
    Residenza residenza;     // Struttura che contiene le coordinate della residenza
} Utente;

typedef struct Nodo
{
    Utente utente;         // Dati relativi all'utente
    struct Nodo *sinistro; // Puntatore al figlio sinistro
    struct Nodo *destro;   // Puntatore al figlio destro
} Nodo;

typedef struct BST
{
    Nodo *radice; // Puntatore alla radice dell'albero
} BST;

Utente* minima_distanza(Nodo* radice, double xD, double yD);

/**********************************************************************************************

La funzione minima_distanza è progettata per trovare l’utente la cui residenza è più vicina a un punto dato (Xd, Yd). 
in un albero binario di ricerca. La funzione riceve come input un puntatore alla radice del sottoalbero in cui effettuare la ricerca 
e le coordinate Xd e Yd​ del punto. Per ogni nodo visitato, calcola la distanza Euclidea tra le coordinate della residenza 
dell’utente contenuto nel nodo corrente e il punto (Xd, Yd) utilizzando la formula:

dE((Xu, Yu),(Xd, Yd)) = sqrt((Xu - Xd)^2 + (Yu - Yd)^2)

La funzione confronta questa distanza con quelle calcolate nei figli sinistro e destro del nodo corrente, 
determinando ricorsivamente quale utente ha la residenza più vicina. La ricerca prosegue in tutto l’albero, 
visitando ogni nodo per confrontare le distanze e aggiornando il puntatore all’utente con la distanza minima trovata finora. 
Quando tutti i nodi sono stati visitati, la funzione restituisce un puntatore all’utente con la residenza più vicina. 
Se l’albero è vuoto, la funzione restituisce NULL. La complessità temporale è O(n) nel caso peggiore, 
in cui tutti i nodi devono essere visitati, mentre è O(log⁡n) in alberi bilanciati, 
poiché la ricerca segue una struttura ben distribuita. 

**********************************************************************************************/