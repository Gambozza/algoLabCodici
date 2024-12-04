/*******************************************************************************************************************

Rappresentare in linguaggio C il seguente problema, facendo riferimento alle strutture dati studiate durante
il corso. Occorre memorizzare i dati di alcune compagnie aeree, le quali realizzano voli verso un certo insieme
di citt`a.

• Di ogni compagnia sono memorizzate il nome (una stringa univoca) e la residenza legale (intesa come
nazione).

• Una citt`a viene rappresentata mediante una stringa nomecitta (univoca) e una seconda stringa
nazione.

• Le compagnie coprono un certo insieme di citt`a con le proprie tratte, e analogamente, una citt`a pu`o
essere raggiunta da voli di pi`u compagnie.

• L’operazione pi`u frequente che la struttura dati deve supportare `e la verifica di copertura per una
data citt`a. Cio`e, data una stringa di input cerca, verificare se cerca sia coperta da almeno una
compagnia aerea, e, in tal caso, restituire nome e residenza legale della prima compagnia trovata (la
parola ‘prima’ non fa riferimento ad alcun ordine particolare, indica che la ricerca si pu`o arrestare
alla prima trovata).

Scegliere una rappresentazione che renda eciente l’operazione verifica di copertura, e che possibilmente
sia eciente anche nella memorizzazione delle informazioni (evitare ridondanze nella rappresentazione delle
stesse). Riportare:

1. i costrutti struct (uno o pi`u) necessari alla rappresentazione del problema, commentando tipo e ruolo
di ciascun membro di ciascuna struttura;

2. il prototipo della funzione verifica copertura, indicando il tipo degli argomenti e dell’output.
L’implementazione di tale funzione `e facoltativa, ma ne va descritta la logica di funzionamento in
relazione a ciascun argomento;

3. Complessit`a della funzione verifica copertura.

`E possibile fare riferimento, laddove lo si ritenga opportuno, sia a strutture dati proposte durante il corso,
che alle funzioni che le utilizzano.

********************************************************************************************************************/

typedef struct Compagnia
{
    char nome[50];          // Nome univoco della compagnia
    char nazione[50];       // Nazione della residenza legale
    struct Compagnia *next; // Puntatore alla prossima compagnia nella lista
} Compagnia;

typedef struct Citta
{
    char nomecitta[50];   // Nome univoco della città
    char nazione[50];     // Nazione della città
    Compagnia *compagnie; // Puntatore alla lista delle compagnie che coprono la città
    struct Citta *next;   // Puntatore alla prossima città nella lista hash
} Citta;

typedef struct TabellaHash
{
    Citta **buckets; // Array di puntatori a liste di città
    int num_buckets; // Numero di bucket nella tabella hash
} TabellaHash;

Compagnia* verifica_copertura(TabellaHash* t, const char* nomecitta);

/*******************************************************************************************************************

La funzione verifica_copertura è progettata per verificare se una città è coperta da almeno una compagnia aerea e, 
in caso positivo, restituisce i dati della prima compagnia trovata. 
La funzione riceve come parametri un puntatore alla tabella hash, che memorizza le città e le loro compagnie aeree, 
e il nome della città da cercare. In primo luogo, calcola il bucket associato alla città utilizzando una funzione hash, 
che converte il nome della città in un indice. Successivamente, attraversa la lista concatenata di città presente nel bucket, 
confrontando il nome di ogni città con il valore fornito come input utilizzando una funzione di confronto delle stringhe come strcmp. 
Se la città viene trovata, la funzione verifica se il campo compagnie della città punta a una lista non vuota. 
Se sì, restituisce un puntatore alla prima compagnia della lista. 
In caso contrario, o se la città non è presente nella tabella hash, restituisce NULL. 
Grazie all'uso della tabella hash, la complessità temporale della funzione è O(1) in media, 
poiché l’operazione di calcolo del bucket e l’accesso al bucket stesso sono costanti, 
mentre la ricerca all’interno del bucket è rapida per un bilanciamento adeguato della tabella.

********************************************************************************************************************/