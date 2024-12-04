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
    int nodo_dest;     // Nodo di destinazione dell'arco
    int peso;          // Peso dell'arco
    struct Arco *next; // Puntatore al prossimo arco della lista
} Arco;

typedef struct Grafo
{
    int num_nodi;           // Numero totale di nodi nel grafo
    Arco **liste_adiacenza; // Array di puntatori alle liste di adiacenza
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