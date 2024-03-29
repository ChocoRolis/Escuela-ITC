//  Olivia Maricela Barrón Cano
//  Creación: 19/Septiembre/2023
//  Última modificación: 20/Septiembre/2023

# include <iostream>
# include "Nodo.h"
# ifndef _ListaEncadenada
# define _ListaEncadenada

using namespace std;

// Definición de la clase Lista Encadenada
template <typename T>
class ListaEncadenada 
{
public:
    ListaEncadenada();            // constructor
    ~ListaEncadenada();           // destructor
    bool estaVacia();
    bool insertarElementoInicio(T info);
    bool insertarElementoFinal(T info);
    int tamanio();
    int encontrarPosicionElemento(T info);
    void borrarElementoInicio();
    void borrarElementoFinal();
    void borrarElemento(int posicion);
    void desplegarLista();
    T traerDatosInicio();
    T traerDatosFinal();
    T traerDatosPosicion(int pos);
    void avanzarUnNodo();
    void restablecerNodo();
private:       
    Nodo<T>* inicio;
    Nodo<T>* final;
};

template <typename T>
ListaEncadenada<T>::ListaEncadenada()
{
    inicio = nullptr;
    final = inicio;
}

template <typename T>
ListaEncadenada<T>::~ListaEncadenada()
{
    Nodo<T>* auxiliar;

    while (inicio != nullptr)
    {
        auxiliar = inicio->siguiente;
        delete inicio;
        inicio = auxiliar;
    }

}

template <typename T>
bool ListaEncadenada<T>::estaVacia()
{
    return inicio == nullptr;
}

template <typename T>
bool ListaEncadenada<T>::insertarElementoInicio(T info)
{
    Nodo<T>* nuevo;
    bool bandera;

    nuevo = new Nodo<T>(info);
    bandera = (nuevo != nullptr);

    if (bandera)
    {
        if (inicio == nullptr)
        {
          inicio = nuevo;
          final = nuevo;
        }
        else
        {
            nuevo->siguiente = inicio;
            inicio = nuevo;
        }
    }

    return bandera;
}

template <typename T>
bool ListaEncadenada<T>::insertarElementoFinal(T info)
{
    Nodo<T>* nuevo;
    Nodo<T>* auxiliar = inicio;
    bool bandera;

    nuevo = new Nodo<T>(info);
    bandera = (nuevo != nullptr);

    if (bandera)
    {
        if (inicio == nullptr)
        {
          inicio = nuevo;
          final = nuevo;
        }
        else
        {
           while(auxiliar->siguiente != nullptr)
                auxiliar = auxiliar->siguiente;
           auxiliar->siguiente = nuevo;
           final = auxiliar->siguiente;
        }
    }

    return bandera;
}

template <typename T>
void ListaEncadenada<T>::desplegarLista()
{
    Nodo<T>* auxiliar = inicio;
    int indice = 0;

    if (inicio != nullptr)
        do
        {
            indice = indice + 1;
            cout << "La informacion del nodo "<<indice<<" es "<<auxiliar->informacion<<endl;
            auxiliar = auxiliar ->siguiente;
        }while(auxiliar != nullptr);
    else
        cout << "La lista esta vacia"<<endl;
    
}

template <typename T>
int ListaEncadenada<T>::tamanio()
{
    Nodo<T>* auxiliar = inicio;
    int indice = 0;

    if (inicio != nullptr)
        do
        {   
            indice = indice + 1;
            auxiliar = auxiliar->siguiente;
        }while(auxiliar != nullptr);
    
    return indice;
    
}

template <typename T>
void ListaEncadenada<T>::borrarElementoFinal()
{
    Nodo<T>* auxiliar = inicio;

    if (inicio != nullptr)
    {
        if (inicio->siguiente == nullptr)
        {  
            delete inicio;
            inicio = nullptr;
        }
        else
        {   while((auxiliar->siguiente)->siguiente != nullptr)
                auxiliar = auxiliar->siguiente;
            final = auxiliar;
            delete auxiliar->siguiente;
            auxiliar->siguiente = nullptr;
        }
    }

}

template <typename T>
void ListaEncadenada<T>::borrarElemento(int posicion)
{
    Nodo<T>* auxiliar = inicio;
  
    if (inicio != nullptr)
    {
        if (posicion == 1)
          this->borrarElementoInicio();
        else
        {
          for (int i = 1; i < posicion-1; i++)
            auxiliar = auxiliar->siguiente;
          Nodo<T>* auxiliar2 = auxiliar->siguiente;
          auxiliar->siguiente = auxiliar2->siguiente;
          delete auxiliar2;
        }
    }
}

template <typename T>    
int ListaEncadenada<T>::encontrarPosicionElemento(T info)
{
    Nodo<T>* auxiliar = inicio;
    int indice = 1;

 
    while ( (auxiliar != nullptr) and (auxiliar->informacion != info))
    {   
        indice = indice + 1;
        auxiliar = auxiliar ->siguiente;
    };

    if (auxiliar == nullptr)
        indice = 0;

    return indice;
 
}

template <typename T>  
void ListaEncadenada<T>::borrarElementoInicio()
{
  Nodo<T>* auxiliar;

  if (inicio != nullptr)
  {
    auxiliar = inicio -> siguiente;
    delete inicio;
    inicio = auxiliar;
  }
}

template <typename T>     
T ListaEncadenada<T>::traerDatosInicio()
{
    return inicio->informacion;
}

template <typename T>     
T ListaEncadenada<T>::traerDatosFinal()
{
    return final->informacion;
}

template <typename T>     
T ListaEncadenada<T>::traerDatosPosicion(int pos)
{
  Nodo<T>* auxiliar = inicio;
  if (inicio != nullptr)
  {
    for (int i = 1; i < pos; i++)
      auxiliar = auxiliar->siguiente;
  }
  return auxiliar->informacion;
}


template <typename T>  
void ListaEncadenada<T>::avanzarUnNodo(){
  inicio = inicio->siguiente;
}

#endif