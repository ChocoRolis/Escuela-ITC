#include <iostream>
#include <string>
#include <fstream>
using std::cout;
using std::cin;
using std::string;
#include "Funcion.h"
#include "Actor.h"
#include "Pelicula.h"

int string_a_int(string num){
    int ValorInt, temp = 1;
    for (int i = 0; i < num.size(); i++){
        for (int a = i+1; a < num.size(); a++){
            temp = temp * 10;
        }
        ValorInt += ((int) num[i] - 48) * temp;
        temp = 1;
    }
    return ValorInt;
}

int main(){
    /*
    Carga los datos para el arreglo de Películas de un archivo de texto 
    que contiene en cada renglón el número de película, el año en que se
    hizo, su duración, su género (siempre será una palabra), la cantidad de
    actores que se agregarán y la lista de id de los actores, finalmente el
    título de la película que es un string que puede tener varias palabras.
    Pide al usuario que teclee los datos para cada una de las funciones disponibles del día.
    */
    Actor arrActor[20];
    Funcion arrFuncion[20];
    Pelicula arrPelicula[20];
    std::ifstream entrada;
    string renglon, actorId, actorNom, PeliNum, PeliAnio, PeliLen, PeliGen, PeliActores;
    int contador = 0;
    entrada.open("Actores.txt");
    while (std::getline(entrada, renglon)){
        actorId = renglon.substr(0,2);
        actorNom = renglon.erase(0,2);
        arrActor[contador].actor(actorNom, string_a_int(actorId));
        contador++;
    }
    contador = 0;
    entrada.ignore();
    while (std::getline(entrada, renglon)){
        PeliNum = renglon.substr(0,3);
        PeliAnio = renglon.substr(4,7);
        PeliLen = renglon.substr(9,3);
        renglon.erase(0,12);
        entrada >> PeliGen;
        entrada >> PeliActores;
    }
    printf("d");
    entrada.close();
    return 0;
}