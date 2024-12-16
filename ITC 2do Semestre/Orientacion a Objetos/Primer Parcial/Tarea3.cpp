#include <iostream>
using namespace std;
#include "Fraccion.h"

int main(){
    Fraccion F, F1;
    F1.setNum(3);
    F1.setDen(4);
    F.fraccion();
    cout << "El valor de la fraccion " << F.getNum() << "/" << F.getDen() << "es " << F.calcVreal();
}