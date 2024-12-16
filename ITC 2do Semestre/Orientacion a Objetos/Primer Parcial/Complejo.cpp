#include <iostream>
using namespace std;
#include "Complejo.h"

int main(){
    Complejo c1, c2, c3, c4, c5;
    double p1, p2, p3, p4;
    c1.construirD();
    cout << "Dame el parametro real del complejo 1: ";
    cin >> p1; 
    cout << "Dame el parametro imaginario del complejo 1: ";
    cin >> p2;
    c2.construir(p1, p2);
    cout << "Dame el parametro real del complejo 2: ";
    cin >> p1; 
    cout << "Dame el parametro imaginario del complejo 2: ";
    cin >> p2;
    c3.construir(p1, p2);
    c4.construir(c2.geta(), c2.getbi());
    c4.sumaC(c3.geta(), c3.getbi());
    c5.construir(c2.geta(), c2.getbi());
    c5.restaC(c3.geta(), c3.getbi());
    cout << "-----------------"<< endl;
    cout << "El numero complejo 1 es " << c1.geta() << " + " << c1.getbi()<< "i" << endl;
    cout << "El numero complejo 2 es " << c2.geta() << " + " << c2.getbi()<< "i" << endl;
    cout << "El numero complejo 3 es " << c3.geta() << " + " << c3.getbi()<< "i" << endl;
    cout << "El numero complejo 4 es " << c4.geta() << " + " << c4.getbi()<< "i" << endl;
    cout << "El numero complejo 5 es " << c5.geta() << " + " << c5.getbi()<< "i" << endl;
}