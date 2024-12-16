#include <iostream>
using namespace std;
#include "Rectangulo.h"

int main(){
    Rectangulo r[4];
    double largo, ancho;
    for (int i = 0; i<3; i++){
        cout << "Dame el largo del rectangulo " << i<< " ";
        cin >> largo;
        cout << "Dame el ancho del rectangulo " << i<< " ";
        cin >> ancho;
        r[i].setLargo(largo);
        r[i].setAncho(ancho);
    }
    for (int i = 0; i<3; i++){
        cout << "El rectangulo " << i << " es de largo " << r[i].getLargo() << " de ancho " << r[i].getAncho() << " y su area es de " << r[i].calcArea() << endl;
    }
}