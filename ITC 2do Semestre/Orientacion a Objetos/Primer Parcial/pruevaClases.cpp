#include <iostream>  
using namespace std;
#include "Rectangulo.h"  
int main( ) {
    Rectangulo rect;
    double area;
    rect.setLargo(10);  
    rect.setAncho(5);
    area = rect.calcArea();
    cout<<"El area es "<< area << endl;  
    return 0;
}