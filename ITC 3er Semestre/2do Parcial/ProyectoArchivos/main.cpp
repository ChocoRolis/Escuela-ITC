/*
Actualmente están de moda los chats "inteligentes" en los cuales un robot puede mantener una conversación en 
tiempo real en el lenguaje de la persona con la que está hablando. Para que eso sea posible, el robot debe realizar 
un análisis sintáctico y semántico de las oraciones que la persona le transmite. El análisis es de hecho similar 
al que realizan los compiladores para poder traducir de un lenguaje de alto nivel al lenguaje de una computadora.
Un primer paso dentro de todo el procesamiento necesario es reconocer las oraciones. Se te pide que desarrolles un 
programa en C++ que utilice estructuras lineales (listas, pilas y/o colas) para procesar un texto 
(que leera de un archivo que se le dará como entrada) y despliegue en la pantalla las oraciones válidas que encuentre en dicho texto 
(una oración por renglón).

Asume que además del texto a analizar, cuentas con 5 archivos que contienen respectivamente artículos, sustantivos, adjetivos, verbos 
y objetos directos válidos, y que la oración siempre tiene la forma: articulo sustantivo adjetivo verbo objeto directo. 
Un ejemplo de oración válida sería entonces La niña alegre come frutas, mientras que Juan come frutas no sería una oración válida.
*/



%:include <iostream>
%:include <fstream>
%:include <vector>
%:include <string>
%:include <sstream>
#include "ListaEncadenada.h"

using namespace std;

int main() {
  ListaEncadenada<string> partes[5], Oraciones, Temp, oracionValida;
  string palabra, renglon;
  vector<string> oraciones;
  ifstream archivoEntrada;

  archivoEntrada.open("articulos.txt");
  while (archivoEntrada >> palabra){
      partes[0].insertarElementoInicio(palabra);
    
  }
  archivoEntrada.close();

  archivoEntrada.open("sustantivos.txt");
  while (archivoEntrada >> palabra){
      partes[1].insertarElementoInicio(palabra);
  }
  archivoEntrada.close();

  archivoEntrada.open("adjetivos.txt");
  while(archivoEntrada >> palabra){
      partes[2].insertarElementoInicio(palabra);
  }
  archivoEntrada.close();

  archivoEntrada.open("verbos.txt");
  while(archivoEntrada >> palabra){
      partes[3].insertarElementoInicio(palabra);
  }
  archivoEntrada.close();

  archivoEntrada.open("objetos.txt");
  while(archivoEntrada >> palabra){
      partes[4].insertarElementoInicio(palabra);
  }
  archivoEntrada.close();


  archivoEntrada.open("text.txt");
  while(getline(archivoEntrada, renglon)){
      Oraciones.insertarElementoInicio(renglon);
  }
  archivoEntrada.close();
  
  for (int i = 0; i < Oraciones.tamanio(); i++)
  {
    cout << Oraciones.traerDatosInicio() << "\n";
    stringstream ss(Oraciones.traerDatosInicio());
    while (ss >> palabra)
    {
      Temp.insertarElementoInicio(palabra);
    
    }
    //Código para determinar si la oracion es correcta
    int contador = 0;
    if (Temp.tamanio() == 5)
    {
      
      for (int i = 0; i < 5; i++)
      {
        if (partes[i].encontrarPosicionElemento(Temp.traerDatosInicio()) != 0)
        {
          contador++;
        }
        Temp.avanzarUnNodo();
      }
      Temp.restablecerNodo();

      
      if (contador == 5)
      {
        oracionValida.insertarElementoInicio(Oraciones.traerDatosInicio());
      }
      //cout << Oraciones.traerDatosInicio() << "\n";
      //Oraciones.avanzarUnNodo();
    }    
    Oraciones.avanzarUnNodo();
    
  }  
  cout << "-----\n"<< oracionValida.traerDatosInicio() << "\n-----";
  for (int i = 0; i < oracionValida.tamanio(); i++)
  {
    //cout << oracionValida.traerDatosInicio() << endl;
    oracionValida.avanzarUnNodo();
  }
}