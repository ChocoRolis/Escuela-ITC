
struct node {
    int info;
    struct node *next;
};

typedef struct node Nodo;

Nodo* crearNodo(int Info){
    Nodo* nuevo;
    nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->next = 0;
    nuevo->info = Info;
    return nuevo;
}

void borrarNodo(Nodo* nodo){
    free(nodo);
}