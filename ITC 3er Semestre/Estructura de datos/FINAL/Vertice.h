#include "ListaEncadenada.h"

#ifndef _Vertice
#define _Vertice

template <typename T>
class Vertice 
{
  public:
    Vertice();
    Vertice(T info);
    void asignaInformacion(T info);
    T traeInformacion();
    void asignaEstado(int edo);
    int traeEstado();
    ListaEncadenada<int>* traeAdyacencias();

  private:
    T informacion;
    ListaEncadenada<int> adyacencias;
    int estado;
};

template <typename T>
Vertice<T>::Vertice()
{
  estado = 0;
}

template <typename T>
Vertice<T>::Vertice(T info)
{
  informacion = info;
  estado = 0;
}

template <typename T>
void Vertice<T>::asignaInformacion(T info)
{
  informacion = info;
}

template <typename T>
T Vertice<T>::traeInformacion()
{
  return informacion;
}

template <typename T>
void Vertice<T>::asignaEstado(int edo)
{
  estado = edo;
}

template <typename T>
int Vertice<T>::traeEstado()
{
  return estado;
}

template <typename T>
ListaEncadenada<int>* Vertice<T>::traeAdyacencias()
{
  return &adyacencias;
}

#endif