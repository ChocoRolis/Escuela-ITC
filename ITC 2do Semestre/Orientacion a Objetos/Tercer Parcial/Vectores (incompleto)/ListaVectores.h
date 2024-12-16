class ListaVectores
{
    public:
        ListaVectores();
        bool agrega(int dato);
        bool elimina(int dato);
        int getSize();
        int getElem(int i);
        int posicion(int dato);
    private:
        int size;
        vector<int> listaDatos;
};
ListaVectores::ListaVectores() {
    size = 0;
}

bool ListaVectores::agrega(int dato) {
    int p;
    p = posicion(dato);
    // si no esta duplicado
    if (p == -1){
        listaDatos.pushback(dato);
        size++;
        return true;
    }
    else return false;
}

int ListaVectores::posicion(int dato) { 
    int donde = -1;
    for (int c = 0; c < size; c++){
    if (listaDatos[c] == dato)
    donde = c;
    return donde;
    }
}
int ListaVectores::getSize() {
    return size;
}
// Si la i esta fuera de rango regresa -1 int
ListaVectores::getElem(int i) {
    return (i >= 0 && i < size) ? listaDatos[i] : -1;
}