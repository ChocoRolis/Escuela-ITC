#include <iostream>
using namespace std;
int main (){
    int a,b,c,R,x,y;
    cout << "------Menu------" << endl;
    cout << "1: Suma" << endl;
    cout << "2: Resta" << endl;
    cout << "3: Multiplicacion" << endl;
    cout << "4: Intercambio" << endl;
    cout << "5: Salir" << endl;
    cout << "----------------\n" << endl;
    cout << "¿Que opcion quieres? ";
    cin >> a;
    switch(a) 
    {
    case 1: 
        cout << "Ingresa un numero a: ";
        cin >> b;  
        cout << "Ingresa un numero b: ";
        cin >> c;
        R = b + c;
        cout << "Su resultado es " << R << endl;
        break;
    case 2: 
        cout << "Ingresa un numero a: ";
        cin >> b;  
        cout << "Ingresa un numero b: ";
        cin >> c;
        R = b - c;
        cout << "Su resultado es " << R << endl;
        break;
    case 3:
        cout << "Ingresa un numero a: ";
        cin >> b;  
        cout << "Ingresa un numero b: ";
        cin >> c;
        R = b*c;
        cout << "Su resultado es " << R << endl;
        break;
    case 4:
        cout << "Ingresa un numero a: ";
        cin >> b;  
        cout << "Ingresa un numero b: ";
        cin >> c;
        x = b;
        y = c;
        b = y;
        c = x;
        cout << "Su resultado es a = " << b << " y b = " << c << endl;
        break;
    case 5:
        cout << "Ha elegido salir, tenga buen dia" << endl;
        break;
    default:
        cout << "Por favor elija un numero entre el 1 y el 5";
        break;
    }
}