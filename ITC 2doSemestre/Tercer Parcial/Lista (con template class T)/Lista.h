const int TAMMAX = 20;

template <class T>
class Lista {
    public:
        Lista();
        bool agrega(T);
        int getSize();
        T getElem(int i);
        int posicion(T);
    private:
        int size;
        T listaDatos[TAMMAX];
};

template <class T>
Lista<T> :: Lista() {
    size = 0;
}

template <class T>
int Lista<T> :: posicion(T dato) {
    int donde = -1;
    for (int c = 0; c < size; c++){
        if (listaDatos[c] == dato){
            donde = c;
            return donde;
        }
    }
    return donde;
}

template <class T>
bool Lista<T> :: agrega(T dato) {
    int p = posicion(dato);
    
    if ((size < TAMMAX) && (p == -1)){
        listaDatos[size++] = dato;
        return true;
    }
    else {
        return false;
    }
}

template <class T>
int Lista<T> ::getSize() {
    return size;
}

template <class T>
T Lista<T> :: getElem(int i) {
    T dato;
    dato = (i >= 0 && i < size) ? listaDatos[i] : -1;
    return dato;
}