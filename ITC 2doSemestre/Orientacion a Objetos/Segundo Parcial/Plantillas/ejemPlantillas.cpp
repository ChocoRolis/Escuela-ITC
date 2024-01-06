#include <iostream>
#include <string>
using namespace std;
#include "Fraccion.h"

template<class T>
T suma(T dato1, T dato2, T dato3){
    return dato1 + dato2 + dato3;
}
int main(){
    double d1 = 1.1, d2 = 2.2, d3 = 3.3,d4;
    string s1 = "hola ", s2 = "lola ", s3 = "bunny", s4;
    int i1 = 1, i2 = 2, i3 =3, i4=4;
    Fraccion f0(2,4), f1(9,4), f2(3,5), f3;

    cout << "Suma de doubles " <<suma(d1,d2,d3);
    d4 = suma(d1,d2,d3);

    cout << "\nSuma de enteros " << suma(i1,i2,i3);
    i4 = suma(i1,i2,i3);

    cout << "\nSuma de strings" << suma(s1,s2,s3);
    s4 = suma(s1,s2,s3);

    f3 = suma(f0,f1,f2);
    cout << "\nSuma de fracciones " << f3.calcVreal();
    
}