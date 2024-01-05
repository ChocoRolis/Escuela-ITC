//  Olivia Maricela Barrón Cano
//  Creación: 19/Septiembre/2023
//  Última modificación: 20/Septiembre/2023

#include <iostream>
#include "Nodo.h"
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
    void desplegarLista();
    int tamanio();
    void borrarElementoFinal();
    int encontrarPosicionElemento(T info);
    void borrarElementoInicio();
    T traerDatosInicio();

    void mete(T info);
    void saca();
    T tope();
    bool PilaestaVacia();
private:       
    Nodo<T>* inicio, *Tope;        // ptr a objeto inicial de la lista
    int cant = -1;
};

template <typename T>
ListaEncadenada<T>::ListaEncadenada()
{
    inicio = nullptr;
    Tope = inicio;
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
          inicio = nuevo;
        else
        {
            nuevo->siguiente = inicio;
            inicio = nuevo;
        }
    }

    return bandera;
}

template <typename T>
void ListaEncadenada<T>::desplegarLista()
{
    Nodo<T>* auxiliar = Tope;
    int indice = 0;

    if (inicio != nullptr)
        do
        {
            indice = indice + 1;
            cout << "La informacion del nodo "<<indice<<" es "<<auxiliar->informacion<<endl;
            auxiliar = auxiliar->siguiente;
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
            auxiliar = auxiliar ->siguiente;
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
            inicio = nullptr;
        else
        {   while((auxiliar->siguiente)->siguiente != nullptr)
                auxiliar = auxiliar->siguiente;
            delete auxiliar->siguiente;
            auxiliar->siguiente = nullptr;
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
  Nodo<T>* auxiliar;

  if (inicio != nullptr)
    return inicio -> informacion;
}

template <typename T> 
void ListaEncadenada<T>::mete(T info){
  if (inicio == nullptr){
    inicio = new Nodo<T>(info);
    Tope = inicio;
  }
  else {
    Nodo<T>* nuevo;
    nuevo = new Nodo<T>(info);
    nuevo->siguiente = Tope;
    Tope = nuevo;
  }
}
template <typename T> 
void ListaEncadenada<T>::saca(){
  Nodo<T>* auxiliar;
  auxiliar = Tope;
  Tope = Tope->siguiente;
  delete (auxiliar);
}

template <typename T> 
T ListaEncadenada<T>::tope(){
  return Tope->informacion;
}

template <typename T> 
bool ListaEncadenada<T>::PilaestaVacia(){
  return Tope == nullptr;
}