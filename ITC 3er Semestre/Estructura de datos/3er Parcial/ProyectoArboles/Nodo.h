template <typename T> class ListaEncadenada;

template <typename T>
class Nodo
{ 
    friend class ListaEncadenada<T>;

public:
    Nodo(T e);          

private:
    T informacion;        
    Nodo<T>* siguiente;       
};

template <class T>
Nodo<T>::Nodo(T e) 
{ 
    informacion=e; 
    siguiente = nullptr;
}; 

