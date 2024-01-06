/*
Las funciones de dispersión (hash functions) además de utilizarse para implementar las tablas de dispersión, pueden utilizarse para codificar y decodificar datos.
En este proyecto se te pide que hagas un programa que, utilizando solamente las estructuras de datos que desarrollamos durante el semestre, lea la definición de un grafo de un archivo de texto, genere el grafo (con su información ya decodificada) y despliegue su recorrido en anchura y su recorrido en profundidad.
El formato del archivo de texto es el siguiente:
texto para valor disperso
información codificada vértice1
información codificada vértice2
...
...
información codificada vérticen
-----------------------------
origen1 destino1
origen2 destino2
...
...
origenm destinom

Un ejemplo de un archivo sería
Hola
Prqwhuuh|
Vdowloor
WruuhÑq
---------------------
1 2
1 3
2 1
2 3
3 1
3 2

La función de dispersión a implementar debe sumar los valores ascii de cada uno de los caracteres del texto que recibe como entrada y regresar el residuo de dicha suma entre la suma de los dígitos de tu matrícula. Para el archivo del ejemplo y si  tu matrícula fuera 123032, la función de dispersión debe regresar el residuo de dividir (72+111+108+97)/(1+2+3+0+3+2) = 3.
La función que decodifica le debe restar el resultado de la función de dispersión a los caracteres del texto que decodifica. Para el archivo de ejemplo y si  tu matrícula fuera 123032, la información del vértice 1 sería Monterrey, la del 2 Saltillo y la del 3 Torreón.
El recorrido en anchura debe ser Monterrey, Saltillo, Torreón, y el de profundidad Monterrey, Torreón, Saltillo
Deberás incluir lo siguiente como parte de la entrega:
1.- Análisis
    Entradas, salidas, proceso
2.- Diseño
     Plantillas de diseño operacional, funcional y lógico, casos de prueba (incluyendo al menos uno de camino feliz y uno de error en la entrada, usa al menos un grafo diferente al del ejemplo), contenido de cada uno de los archivos de texto a utilizar
3.- Código fuente que respete el estándar de codificación
4.- Reporte de pruebas unitarias
     Documento que contiene los casos de prueba y las imagenes del resultado de su ejecución

Entregado el 4/Dic/2023
*/


#include <iostream>
#include <string>
#include <fstream>
#include "grafo.h"

using namespace std;

int Crearllave(ifstream &archivo)
{
    string llave;
    int suma = 0;
    archivo >> llave;
    for (int i = 0; i < llave.length(); i++)
    {
      suma += (int) llave[i];
    }
    return suma % 33;
}

string decodificacion(int llave, string info)
{
  string decodificado;
  for (int i = 0; i < info.length(); i++)
    {
      decodificado += (char) ((int) info[i] - llave);
    }
  return decodificado;
}

ListaEncadenada<string>* lista_vertices(ifstream &archivo, int llave)
{
  ListaEncadenada<string>* lista = new ListaEncadenada<string>();
  string info;
  while (archivo >> info)
    {
      if (info[0] != '-')
      {
        info = decodificacion(llave, info);
        lista->insertarElementoFinal(info);
      }
      else break;
    }
  return lista;
}

void adyacentes(ifstream &archivo, ListaEncadenada<int> &origenes, ListaEncadenada<int> &destinos)
{
  int origen, destino;
  while (!archivo.eof())
    {
      archivo >> origen;
      origenes.insertarElementoFinal(origen);
      archivo >> destino;
      destinos.insertarElementoFinal(destino);
    }
}


int main() {
  Grafo<string> g;
  ifstream entrada("grafo.txt");
  ListaEncadenada<int> Origenes, Destinos;
  ListaEncadenada<string>* ListaVertices;
  
  ListaVertices = lista_vertices(entrada, Crearllave(entrada));
  adyacentes(entrada, Origenes, Destinos);

  for (int i = 1; i <= ListaVertices->tamanio(); i++)
      g.insertaVertice(ListaVertices->traerDatosPosicion(i));

  for (int i = 1; i <= Origenes.tamanio(); i++)
      g.insertaArco(Origenes.traerDatosPosicion(i), Destinos.traerDatosPosicion(i));


  g.recorridoAnchura();
  cout << "\n";
  g.recorridoProfundidad();
}