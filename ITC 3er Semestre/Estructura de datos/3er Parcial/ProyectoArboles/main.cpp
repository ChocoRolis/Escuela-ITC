/*
Se te pide que escribas un programa en C++ que utilizando la clase Árbol que se desarrolló en el curso pueda ir recorriendo el árbol, pidiendo los valores definidos en cada nodo hasta que llegue a una clasificación o a decir que no tiene respuesta.
Los datos para poblar el árbol se leerán de un archivo de texto que tendrá la información del recorrido de acuerdo a lo indicado en su primera línea. Por ejemplo, para el árbol anterior si el recorrido fuera preorden, el contenido del archivo sería (se agregan los nodos nulos para identificar cuando se llegó a un nodo hoja):
Preorden
Color rojo
Tamanio grande
Fruta Manzana
Nulo
Nulo
Fruta Cereza
Nulo
Nulo
Color amarillo
Tamanio Grande
Fruta Pera
Nulo
Nulo
Fruta Limon
Nulo
Nulo
Sin respuesta
Nulo
Nulo
Será necesario entonces que añadas al menos dos funciones a la clase Arbol, una para que haga el recorrido pidiendo los valores de los atributos, y otra para que cargue los datos del árbol
Deberás incluir lo siguiente como parte de la entrega:
1.- Análisis
    Entradas, salidas, proceso, descripción del uso de las estructuras lineales como parte del proceso
2.- Diseño
     Plantillas de diseño operacional, funcional y lógico, casos de prueba (incluyendo al menos uno de camino feliz y uno de error en la entrada), contenido de cada uno de los archivos de texto a utilizar
3.- Código fuente que respete el estándar de codificación
4.- Reporte de pruebas unitarias
     Documento que contiene los casos de prueba y las imagenes del resultado de su ejecución 
*/


#include <iostream>
#include <fstream>
#include <string>
#include "Arbol.h"


using namespace std;

int main()
{
  ifstream entrada;
  string recorrido;
  NodoA<string>* nodo;
  Arbol<string> r;

  entrada.open("prueba.txt");
  getline(entrada, recorrido);
  if (recorrido == "Preorden")
  {
    r.asignaRaiz(r.crearPreorden(entrada, nodo));
    r.recorridoPreOrden(r.obtenerRaiz());
    cout << "\n\n";
  }
  else if (recorrido == "Postorden")
  {
    r.asignaRaiz(r.crearPostOrden(entrada, nodo));
    r.recorridoPostOrden(r.obtenerRaiz());
    cout << "\n\n";
  }
  else
  {
    cout << "Tipo de recorrido no válido";
  }

  r.recorrerArbol(r.obtenerRaiz());
  
  entrada.close();

}