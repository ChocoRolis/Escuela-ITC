#include <iostream>
#include <fstream>
#include <string>
#include "Arbol.h"

using namespace std;

int main()
{
  ifstream entrada;
  string recorrido;
  NodoA<string>* nodo = nullptr;
  Arbol<string> r;

  entrada.open("prueba.txt");
  getline(entrada, recorrido);
  if (recorrido == "Preorden")
  {
    r.crearPreorden(entrada, nodo);
    r.recorridoPreOrden(nodo);
  }
  else if (recorrido == "Postorden")
  {
    r.crearPostOrden(entrada, nodo);
    r.recorridoPostOrden(nodo);
  }
  else
  {
    cout << "Tipo de recorrido no válido";
  }
  
  entrada.close();

}