#include <iostream>
#include <math.h>
using std::cout;
using std::cin;

double crecimiento = 3.78;
double fallecimiento = 2.34;

int modelo(int days, double bacteria){
    if (days == 0){
        return bacteria;
    }
    else{
        return modelo(days-1, bacteria+=floor((bacteria * crecimiento)) - floor((bacteria * fallecimiento)));
    }
}

int main(){
    int dias;
    double bacterias = 1;
    cout << "Inserte numero de dias a modelar las bacterias: ";
    cin >> dias;
    cout << "El numero de bacterias es de: " << modelo(dias, bacterias);
}