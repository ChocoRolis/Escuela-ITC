#include "NodoArbol.h"
#include "ListaEncadenada.h"
using namespace std;

template <typename T>
class Arbol
{
  public:
      Arbol();
      bool esHoja(NodoA<T>* nodito); 
      void recorridoInOrden(NodoA<T>* nodito); 
      void recorridoPreOrden(NodoA<T>* nodito); 
      void recorridoPostOrden(NodoA<T>* nodito);
      void recorridoEnAnchura(NodoA<T>* nodito);
      void visitaNodo(NodoA<T>* nodito); 
      NodoA<T>* predecesor(NodoA<T>* nodito);
      NodoA<T>* Sucesor(NodoA<T>* nodito); 
      NodoA<T>* padre(T info); 
      NodoA<T>* obtenerRaiz(); 
      bool borrarNodo(T info); 
      bool agregarNodo(T info); 
      int altura();
      void asignaRaiz(NodoA<T>* nodito);
  
      NodoA<T>* crearPreorden(ifstream &archivo, NodoA<T>* nodito);
      NodoA<T>* crearPostOrden(ifstream &archivo, NodoA<T>* nodito);
      NodoA<T>* postOrden(ListaEncadenada<T> &pila, NodoA<T>* auxiliar);

      void recorrerArbol(NodoA<T>* nodito);
  
  private:
      NodoA<T>* raiz;
};  

template <class T>
Arbol<T>::Arbol()
{
    raiz = nullptr;
}

template <class T>
bool Arbol<T>::agregarNodo(T info)
{
  NodoA<T>* nuevoNodo = new NodoA<T>(info);
  if (nuevoNodo == nullptr) {
    return false;
  }

  if (raiz == nullptr) {
    raiz = nuevoNodo;
  } else {
    NodoA<T>* actual = raiz;
    NodoA<T>* padre = nullptr;

    while (actual != nullptr) {
      padre = actual;

      if (info < actual->obtieneInformacion()) {
        actual = actual->obtieneIzquierda();
      } else if (info > actual->obtieneInformacion()) {
        actual = actual->obtieneDerecha();
      } else {
        // El nodo con el mismo valor ya existe, no se permite duplicados
        delete nuevoNodo;
        return false;
      }
    }

    if (info < padre->obtieneInformacion()) {
      padre->asignaIzquierda(nuevoNodo);
    } else {
      padre->asignaDerecha(nuevoNodo);
    }
  }

  return true;
}


template <class T>
bool Arbol<T>::esHoja(NodoA<T>* nodito)
{
    bool bandera;
    NodoA<T>* hijoIzquierdo;
    NodoA<T>* hijoDerecho;
    bandera = false;
    if (nodito == nullptr)
    {
        bandera = false;
    }
    else
    {
        hijoIzquierdo = nodito->obtieneIzquierda();
        hijoDerecho = nodito->obtieneDerecha();
        if (hijoIzquierdo == nullptr && hijoDerecho == nullptr)
        {
            bandera = true;
        }
    }
    return bandera;
}

template <class T>
void Arbol<T>::visitaNodo(NodoA<T>* nodito)
{
    if (nodito != nullptr)
    {
        cout << nodito->obtieneInformacion() << "\n";
    }
}

template <class T>
void Arbol<T>::recorridoInOrden(NodoA<T>* nodito)
{
    if (nodito != nullptr)
    {
        recorridoInOrden(nodito->obtieneIzquierda());
        visitaNodo(nodito);
        recorridoInOrden(nodito->obtieneDerecha());
    }
}

template <class T>
void Arbol<T>::recorridoPostOrden(NodoA<T>* nodito)
{
    if (nodito != nullptr)
    {
        recorridoPostOrden(nodito->obtieneIzquierda());
        recorridoPostOrden(nodito->obtieneDerecha());
        visitaNodo(nodito);
    }
}

template <class T>
NodoA<T>* Arbol<T>::obtenerRaiz()
{
    return raiz;
}

template <class T>
bool Arbol<T>::borrarNodo(T info)
{
    NodoA<T>* auxiliar = raiz;
    NodoA<T>* padre = nullptr;
    NodoA<T>* predecesor = nullptr;
    T infoPredecesor;
    int cantidadHijos;
    bool bandera = false;

    while (auxiliar != nullptr)
    {
        if (info == auxiliar->obtieneInformacion())
        {
            bandera = true;
            cantidadHijos = auxiliar->cantidadHijos();
            if (cantidadHijos == 0)
            {
                if (padre == nullptr)
                {
                    delete raiz;
                    raiz = nullptr;
                }
                else
                {
                    if (info < padre->obtieneInformacion())
                        padre->asignaIzquierda(nullptr);
                    else
                        padre->asignaDerecha(nullptr);
                    delete auxiliar;
                }
            }
            else if (cantidadHijos == 1)
            {
                NodoA<T>* hijoNoNulo = (auxiliar->obtieneIzquierda() != nullptr) ? auxiliar->obtieneIzquierda() : auxiliar->obtieneDerecha();
                if (padre == nullptr)
                {
                    delete raiz;
                    raiz = hijoNoNulo;
                }
                else
                {
                    if (info < padre->obtieneInformacion())
                        padre->asignaIzquierda(hijoNoNulo);
                    else
                        padre->asignaDerecha(hijoNoNulo);
                }
                delete auxiliar;
            }
            else // en caso de 2 hijs
            {
                predecesor = auxiliar->predecesor();
                infoPredecesor = predecesor->obtieneInformacion();
                borrarNodo(infoPredecesor); // Llamada recursiva para eliminar el predecesor
                auxiliar->asignaInformacion(infoPredecesor);
            }
            break;
        }
        padre = auxiliar;
        if (info < auxiliar->obtieneInformacion())
            auxiliar = auxiliar->obtieneIzquierda();
        else
            auxiliar = auxiliar->obtieneDerecha();
    }
    return bandera;
}

template <class T>
void Arbol<T>::recorridoPreOrden(NodoA<T>* nodito)
{
    if (nodito != nullptr)
    {
        visitaNodo(nodito);                  // Visita el nodo actual
        recorridoPreOrden(nodito->obtieneIzquierda());   // Recorre el sub izquierdo
        recorridoPreOrden(nodito->obtieneDerecha());     // Recorre el sub derecho
    }
}

template <class T>
NodoA<T>* Arbol<T>::predecesor(NodoA<T>* nodito)
{
  NodoA<T>* auxiliar;
  auxiliar = new NodoA<T>(nodito);

  if (auxiliar != nullptr)
  {
    auxiliar = auxiliar->obtieneIzquierda();

    if (auxiliar != nullptr)
    {
      while (auxiliar->obtieneDerecha() != nullptr)
        {
          auxiliar = auxiliar->obtieneDerecha();
        }
    }
  }
  return auxiliar;
}

template <class T>
NodoA<T>* Arbol<T>::Sucesor(NodoA<T>* nodito)
{
  NodoA<T>* auxiliar;
  auxiliar = new NodoA<T>(nodito);

  if (auxiliar != nullptr)
  {
    auxiliar = auxiliar->obtieneDerecha();

    if (auxiliar != nullptr)
    {
      while (auxiliar->obtieneIzquierda() != nullptr)
        {
          auxiliar = auxiliar->obtieneIzquierda();
        }
    }
  }
  return auxiliar;
}

template <class T>
NodoA<T>* Arbol<T>::padre(T info)
{
  NodoA<T>* auxiliar, padre;
  auxiliar = raiz;
  padre = nullptr;

  if (auxiliar != nullptr)
  {
    while (auxiliar->obtieneInformacion() != info && auxiliar != nullptr)
    {
      padre = auxiliar;
      if (info > auxiliar->obtieneInformacion())
      {
        auxiliar = auxiliar->obtieneIzquierda();
      }
      else 
      {
        auxiliar = auxiliar->obtieneDerecha();
      }
    }
    if (auxiliar == nullptr)
    {
      padre = nullptr;
    }
  }

  return padre;
}

template <class T>
int Arbol<T>::altura()
{
  NodoA<T>* auxiliar;
  if (auxiliar != nullptr)
  {
    int alturaL = altura(auxiliar->obtieneIzquierda());
    int alturaD = altura(auxiliar->obtieneDerecha());

    if (alturaL > alturaD)
    {
      return alturaL + 1;
    }
    else
    {
      return alturaD + 1;
    }
  }
  else
  {
    return 0;
  }
}

template <class T>
void imprimeNivel(NodoA<T> auxiliar, int n)
{
  if (auxiliar == nullptr)
  {
    return;
  }
  if (n == 1)
  {
    cout << auxiliar->obtieneInformacion() << "\n";
  }
  if (n > 1)
  {
    imprimeNivel(auxiliar->obtieneIzquierda(), n - 1);
    imprimeNivel(auxiliar->obtieneDerecha(), n - 1);
  }
}

template <class T>
void Arbol<T>::recorridoEnAnchura(NodoA<T>* nodito)
{
  int altitud = altura(nodito);
  for (int i = 1; i <= altitud; i++)
    {
      imprimeNivel(nodito, i);
    }
}

template <class T>
NodoA<T>* Arbol<T>::crearPreorden(ifstream &archivo, NodoA<T>* nodito)
{
  string linea;
  getline(archivo, linea);
  
  if (linea == "Nulo" || archivo.eof()) 
  {
    return nullptr;
  }
  else
  {
    nodito = new NodoA<T>(linea);
    nodito->asignaIzquierda(crearPreorden(archivo, nodito->obtieneIzquierda()));
    nodito->asignaDerecha(crearPreorden(archivo, nodito->obtieneDerecha()));
    return nodito;
  }
}

template <class T>
NodoA<T>* Arbol<T>::crearPostOrden(ifstream &archivo, NodoA<T>* nodito)
{
  string linea;
  ListaEncadenada<T> Pila;
  while (getline(archivo, linea))
    {
      Pila.mete(linea);
    }
  return postOrden(Pila, nodito);
}

template <class T>
NodoA<T>* Arbol<T>::postOrden(ListaEncadenada<T> &pila, NodoA<T>* auxiliar)
{
  if (pila.estaVacia())
  {
    return nullptr;
  }
  else
  {
    if (pila.tope() == "Nulo")
    {
      pila.saca();
      return nullptr;
    }
    else 
    {
      auxiliar = new NodoA<T>(pila.tope());
      pila.saca();
      auxiliar->asignaDerecha(postOrden(pila, auxiliar->obtieneDerecha()));
      auxiliar->asignaIzquierda(postOrden(pila, auxiliar->obtieneIzquierda()));
      return auxiliar;
    } 
  } 
}

template <class T>
void Arbol<T>::asignaRaiz(NodoA<T>* nodito)
{
  raiz = nodito;
}

template <class T>
void Arbol<T>::recorrerArbol(NodoA<T>* nodito)
{
  char opcion;
  if (nodito->obtieneIzquierda() != nullptr && nodito->obtieneDerecha() != nullptr)
  {
    cout << nodito->obtieneInformacion() << "? (Y/n) ";
    cin >> opcion;
    switch (opcion)
    {
      case 'Y':
        recorrerArbol(nodito->obtieneIzquierda());
        break;
      case 'n':
        recorrerArbol(nodito->obtieneDerecha());
        break;
      default:
        cout << "No seleccionaste una opción válida\n";
    }
  }
  else 
  {
    cout << "El objeto es: " << nodito->obtieneInformacion();
  }
}