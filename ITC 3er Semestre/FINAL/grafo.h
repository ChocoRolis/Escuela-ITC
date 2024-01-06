#include "Vertice.h"

template <typename T>
class Grafo {
  public:
    bool insertaVertice(T info);
    bool insertaArco(int origen, int destino);
    bool borraVertice(int posicion);
    bool borraArco(int origen, int destino);
    void recorridoAnchura();
    void recorridoProfundidad();
    void despliegaInformacion();
  private:
    ListaEncadenada<Vertice<T>*> vertices;
};

template <typename T>
bool Grafo<T>::insertaVertice(T info)
{
  Vertice<T>* auxiliar = new Vertice<T>(info);
  bool bandera = vertices.insertarElementoFinal(auxiliar);
  return bandera;
}

template <typename T>
bool Grafo<T>::insertaArco(int origen, int destino)
{
  Vertice<T>* auxiliar;
  bool bandera;
  int tamanio;
  ListaEncadenada<int>* ady;
  tamanio = vertices.tamanio(); 
  if ((origen <= tamanio) && (destino <= tamanio) && (tamanio != 0))
  {
    auxiliar = vertices.traerDatosPosicion(origen);
    ady = auxiliar->traeAdyacencias();
    bandera = ady->insertarElementoFinal(destino);
  }
  else
  {
    bandera = false;
  }
  return bandera;
}

template <typename T>
bool Grafo<T>::borraVertice(int posicion)
{
  bool bandera;
  int tamanio;
  tamanio = vertices.tamanio();
  if (posicion <= tamanio)
  {
    bandera = true;
    vertices.borrarElemento(posicion);
  }
  else
  {
    bandera = false; 
  }
  return bandera;
}

template <typename T>
bool Grafo<T>::borraArco(int origen, int destino)
{
  Vertice<T>* auxiliar;
  bool bandera;
  int tamanio;
  ListaEncadenada<T>* ady;
  if ((origen <= tamanio) && (destino <= tamanio) && (tamanio != 0))
  {
    auxiliar = vertices.traerDatosPosicion(origen);
    ady = auxiliar->traeAdyacencias();
    bandera = ady->borrarElemento(auxiliar.encontrarPosicionElemento(destino));
  }
  else
  {
    bandera = false;
  }
  return bandera;
}

template <typename T>
void Grafo<T>::recorridoAnchura()
{
  int tamanio = vertices.tamanio();
  ListaEncadenada<Vertice<T>*> fila;
  Vertice<T>* nodo;
  ListaEncadenada<int>* ady;
  int VecinoPos;
  Vertice<T>* Vecino;

  for (int i = 1; i <= tamanio; i++)
  {
    vertices.traerDatosPosicion(i)->asignaEstado(0);
  }

  for (int i = 1; i <= tamanio; i++)
  {
    nodo = vertices.traerDatosPosicion(i);
    if (nodo->traeEstado() == 0)
    {
      fila.insertarElementoInicio(nodo);
      nodo->asignaEstado(1);
      while (!fila.estaVacia())
      {
        nodo = fila.traerDatosFinal();
        cout << nodo->traeInformacion() << " ";
        ady = nodo->traeAdyacencias();
        for (int j = 1; j <= ady->tamanio(); j++)
          {
            VecinoPos = ady->traerDatosPosicion(j);
            Vecino = vertices.traerDatosPosicion(VecinoPos);
            if (Vecino->traeEstado() == 0)
            {
              fila.insertarElementoInicio(Vecino);
              Vecino->asignaEstado(1);
            }
          }
        fila.borrarElementoFinal();
      }
    }
  }
}

template <typename T>
void Grafo<T>::recorridoProfundidad()
{
  int tamanio = vertices.tamanio();
  ListaEncadenada<Vertice<T>*> pila;
  Vertice<T>* nodo;
  ListaEncadenada<int>* ady;
  int VecinoPos;
  Vertice<T>* Vecino;

  for (int i = 1; i <= tamanio; i++)
  {
    vertices.traerDatosPosicion(i)->asignaEstado(0);
  }

  for (int i = 1; i <= tamanio; i++)
  {
    nodo = vertices.traerDatosPosicion(i);
    if (nodo->traeEstado() == 0)
    {
      pila.insertarElementoInicio(nodo);
      nodo->asignaEstado(1);
      while (!pila.estaVacia())
      {
        nodo = pila.traerDatosInicio();
        cout << nodo->traeInformacion() << " ";
        ady = nodo->traeAdyacencias();
        pila.borrarElementoInicio();
        for (int j = 1; j <= ady->tamanio(); j++)
          {
            VecinoPos = ady->traerDatosPosicion(j);
            Vecino = vertices.traerDatosPosicion(VecinoPos);
            if (Vecino->traeEstado() == 0)
            {
              pila.insertarElementoInicio(Vecino);
              Vecino->asignaEstado(1);
            }
          }
        
      }
    }
  }
}

template <typename T>
 void Grafo<T>::despliegaInformacion()
{
  Vertice<T>* auxiliar;
  int tamanio;
  ListaEncadenada<int>* ady;
  int tamAdy;
  tamanio = vertices.tamanio();
  for (int i = 1; i <= tamanio; ++i) {
    auxiliar = vertices.traerDatosPosicion(i);
    cout << "Informacion del vertice " << i << ": ";
    cout << auxiliar->traeInformacion() << endl;
    ady = auxiliar->traeAdyacencias();
    tamAdy = ady->tamanio();
 
    for (int j = 1; j <= tamAdy; ++j) 
    {
      cout << "Arco con vertice no. " << ady->traerDatosPosicion(j) << endl;
    }
  }
}