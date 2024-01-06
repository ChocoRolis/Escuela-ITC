#include <iostream>
using std::cout;
using std::cin;

void InteresCompuesto(double Cantidad, int Meses, double Interes){

    if (Meses < 1) {
        cout << "Monto final: " << Cantidad;
        return;
    }
    Cantidad = Cantidad + (Cantidad * (Interes / 100));
    cout << "monto acumulado del mes " << Meses << " es " << Cantidad << "\n";

    InteresCompuesto(Cantidad, Meses-1, Interes);
}

int main(){
    
    int meses;
    double ValorInicial, interes;
    
    cout << "Cálculo del interés compuesto\nCantidad inicial:";
    cin >> ValorInicial;
    cout << "Ingresa meses de inversión: ";
    cin >> meses;
    cout << "Tasa de interés (%): ";
    cin >> interes;

    InteresCompuesto(ValorInicial, meses, interes);
}