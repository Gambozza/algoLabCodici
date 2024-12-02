/**********************************************************************************************

Fornire il codice C che definisca una struttura dati pila, i cui elementi
contengano siano degli interi. Descrivere la procedura di push,
indicandone anche al prototipo, e facendo riferimento agli argomenti
in input nel fornirne la spiegazione logica

**********************************************************************************************/

typedef struct stack
{
    int valore;         // Valore intero contenuto nella pila
    struct stack *next; // Puntatore al prossimo elemento
} stack;

stack *push(stack *top, int nuovo_valore);


/*********************************************************************************

La funzione push serve per aggiungere un nuovo elemento in cima alla pila. 
La procedura riceve in input un puntatore al nodo in cima alla pila, rappresentato da top, 
e il valore intero da aggiungere, nuovo_valore. Per eseguire l'operazione, la funzione crea un nuovo nodo 
allocando memoria dinamicamente. Il nuovo nodo viene inizializzato con il valore fornito 
e il suo puntatore next viene collegato al nodo attualmente in cima alla pila. Infine, il nuovo nodo diventa 
la nuova cima della pila e viene restituito come risultato. Questo garantisce che l’elemento appena inserito 
sia accessibile immediatamente in un’operazione successiva.

********************************************************************************/


/*********************************************************************************

Fornire un’implementazione in C della struttura dati Pila
Definire la struttura principale e indicare come verrebbe realizzata
l’operazione Head
– Analizzarne la complessità    

********************************************************************************/