#include <iostream>  
using namespace std;
#include "Reloj.h"  
int main(){
    Reloj horaI, horaF;
    int hora, minutos;
    cout << "Dame la hora inicial ";
    cin >> hora;
    cout << "\n Dame los minutos iniciales ";
    cin >> minutos;
    horaI.setHora(hora);
    horaI.setMin(minutos);
    cout << "Dame la hora final ";
    cin >> hora;
    cout << "Dame los minutos finales ";
    cin >> minutos;
    horaF.setHora(hora);
    horaF.setMin(minutos);
    cout << "la hora inicial es " << horaI.getHora() << endl;
    cout << "la hora final es " << horaF.getHora()<< endl;
    horaI.muestra();

}