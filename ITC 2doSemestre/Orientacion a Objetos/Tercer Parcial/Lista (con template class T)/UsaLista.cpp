#include <iostream>
//#include <string>
using namespace std;
#include "Lista.h"

//template <class T>
int main(){
    Lista<double> listaDoubles;
    Lista<int> listaEnteros;
    int i;
    for (i = 62; i < 68; i++){
        listaDoubles.agrega(i/10.0);
    }

    for (i = 0; i < 5; i++){
        listaEnteros.agrega(i);
    }

    if (listaEnteros.agrega(3)) {
        cout << "se pudo agregar el 3 " << endl;
    }
    else {
        cout << "no se pudo agregar el 3 " << endl;
    }

    cout<<"Los elementos de la lista de doubles son:"<<endl;

    for (int i = 0; i < listaDoubles.getSize(); i++){
        cout<<listaDoubles.getElem(i)<<endl;
    }

    cout<<"Los elementos de la lista de enteros son:"<<endl;

    for (int i = 0; i < listaEnteros.getSize(); i++){
        cout<<listaEnteros.getElem(i)<<endl;
    }
    
    cout << "El dato de la casilla 7 es " << listaDoubles.getElem(7) << endl;
}