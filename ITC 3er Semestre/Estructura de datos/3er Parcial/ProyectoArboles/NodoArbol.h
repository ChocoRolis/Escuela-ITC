template <typename T>
class NodoA
{ 

public:
    NodoA(T info);            // constructor
    void asignaInformacion(T info);
    void asignaIzquierda(NodoA<T>* izq);
    void asignaDerecha(NodoA<T>* der);
    T obtieneInformacion();
    NodoA<T>* obtieneIzquierda();
    NodoA<T>* obtieneDerecha();
    int cantidadHijos();
    NodoA<T>* predecesor();
    NodoA<T>* sucesor();


private:
    T informacion;             // datos almacenados en este nodo
    NodoA<T>* izquierda;         // ptr al hijo izquierdo
    NodoA<T>* derecha;         // ptr al hijo derecho
};

template <class T>
NodoA<T>::NodoA(T info) 
{ 
    informacion=info; 
    izquierda = nullptr;
    derecha = nullptr;
}; 

template <class T>
void NodoA<T>::asignaInformacion(T info)
{
    informacion = info;
}

template <class T>
void NodoA<T>::asignaIzquierda(NodoA<T>* izq)
{
    izquierda = izq;
}

template <class T>
void NodoA<T>::asignaDerecha(NodoA<T>* der)
{
    derecha = der;
}

template <class T>
 T NodoA<T>::obtieneInformacion()
 {
    return informacion;
 }

template <class T>
NodoA<T>* NodoA<T>::obtieneIzquierda()
{
    return izquierda;
}

template <class T>
 NodoA<T>* NodoA<T>::obtieneDerecha()
 {
    return derecha;
 }

 template <class T>
int NodoA<T>::cantidadHijos()
 {
    int cantidad;
    cantidad = 0;
    if(obtieneDerecha()!=nullptr)
    {
        cantidad++;
    }
    if(obtieneIzquierda()!=nullptr)
    {
        cantidad++;
    }
    return cantidad;
 }

template <class T>
NodoA<T>* NodoA<T>::predecesor()
{
    NodoA<T>* auxiliar = obtieneIzquierda();
    while (auxiliar != nullptr && auxiliar->obtieneDerecha() != nullptr)
    {
        auxiliar = auxiliar->obtieneDerecha();
    }
    return auxiliar;
}

template <class T>
NodoA<T>* NodoA<T>::sucesor()
{
    NodoA<T>* auxiliar = obtieneDerecha();
    while (auxiliar != nullptr && auxiliar->obtieneIzquierda() != nullptr)
    {
        auxiliar = auxiliar->obtieneIzquierda();
    }
    return auxiliar;
}
