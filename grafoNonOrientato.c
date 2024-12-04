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

typedef struct
{
    int **matrice_adiacenza; // Matrice di adiacenza: matrice quadrata di interi
    int dimensione;          // Numero di nodi nel grafo
} Grafo;

void inserisci_arco(Grafo* g, int nodo1, int nodo2, int peso);

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

