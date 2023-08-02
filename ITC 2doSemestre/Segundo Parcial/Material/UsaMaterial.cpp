#include <iostream>
#include <string>
using namespace std;
#include "Libro.h"
#include "TutorialElectronico.h"

/*4. Escribe ahora un programa que pregunte la bibliografía utilizada para realizar un trabajo de
investigación. Lo primero que debe hacer es preguntar si es un libro o es un Tutorial bajado de
Internet y luego debe pedir los datos adecuados según el caso y guardar los datos en un
arreglo de objetos de tipo MaterialDeLectura.
Después el programa debe mostrar un mensaje que diga: “La bibliografía utilizada para
realizar la investigación es” y enseguida debe aparecer la lista de todos los materiales
utilizados.*/

int main(){
    MaterialDeLectura *arrMaterial[10];
    Libro arrLibro[10];
    TutorialElectronico arrTutorial[10];
    int opcion, cant, _numpaginas, contLibro = 0, contTutorial = 0;
    string _titulo, _autor, _editorial, _url, _fechaLastUpdate;

    do {
        cout << "Cuantos materiales quiere guardar? (Maximo 10): "; cin >> cant;
    } while (cant > 11);
    
    cout << "Para elegir una opcion seleccione su numero correspondiente, de otra manera será error:\n";
    for (int i = 0; i < cant; i++){
        cout << "====================================================================================\n";
        cout << "Seleccione el tipo de material para el que desea hacer un trabajo de investigacion:\n";
        cout << "1. Libro\n2. Tutorial bajado de internet\n";
        cout << "------------------------------------------------------------------------------------\n";
        cin >> opcion;
        switch (opcion){
            case 1:
                cout << "Libro " << contLibro+1 << "\n";
                cout << "Inserte el nombre del libro: "; cin >> _titulo; 
                cout << "Inserte el autor del libro: "; cin >> _autor; 
                cout << "Inserte la editorial del libro: "; cin >> _editorial; 
                cout << "Inserte la cantidad de paginas del libro: "; cin >> _numpaginas; 
                cout << "====================================================================================\n";
                arrLibro[contLibro].setTitulo(_titulo);
                arrLibro[contLibro].setAutor(_autor);
                arrLibro[contLibro].setEditorial(_editorial);
                arrLibro[contLibro].setNumPaginas(_numpaginas);
                arrMaterial[i]  = &arrLibro[contLibro];
                contLibro++;
                break;
            case 2:
                cout << "Tutorial " << contTutorial+1 << "\n";
                cout << "Inserte el nombre del tutorial: "; cin >> _titulo; 
                cout << "Inserte la autor del tutorial: "; cin >> _autor; 
                cout << "Inserte la url del tutorial: "; cin >> _url; 
                cout << "Inserte la fecha de ultima actualizacion: "; cin >> _fechaLastUpdate; 
                cout << "====================================================================================\n";
                arrTutorial[contTutorial].setTitulo(_titulo);
                arrTutorial[contTutorial].setAutor(_autor);
                arrTutorial[contTutorial].setUrl(_url);
                arrTutorial[contTutorial].setFecha(_fechaLastUpdate);
                arrMaterial[i] = &arrTutorial[contTutorial];
                contTutorial++;
                break;
            default: 
            cout << "No seleccionaste una de las opciones";
        }
    }
    
    cout << "\nLa bibliografía utilizada para realizar la investigación es:\n";

    for (int i = 0; i < cant; i++){
        arrMaterial[i]->muestra();
    }
}