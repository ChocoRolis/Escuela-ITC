#include <iostream>
using namespace std;
#include <string>
#include "Salon.h"
#include "Computadora.h"
int main(){
    Salon salones[10];
    Computadora com;
    string MarcaX, SOx;
    int a, RAMx, salonx, p;
    do {
        cout << "Cuantos salones desea registrar? (Maximo 10) ";
        cin >> a;
    } while (a > 10 && a < 0);
    cout << "-----------------------------------------------------------"<< endl;
    cout << "Se le pediran los datos del salon y su computadora, tome en cuenta que\n cualquier diferencia entre mayusculas y minusculas se tomara en cuenta" << endl;
    cout << "-----------------------------------------------------------"<< endl;
    for (int i = 0; i < a; i++){
        cout << "Ingresa el numero del salon no." << i+1 << " \n";
        cin >> salonx;
        cout << "Ingresa la marca de la computadora " << " \n";
        cin >> MarcaX;
        cout << "Ingresa el sistema operativo de la computadora " << " \n";
        cin >> SOx;
        cout << "Ingresa la cantidad de memoria RAM de la computadora " << " \n";
        cin >> RAMx;
        com.build(MarcaX, SOx, RAMx);
        salones[i].salon(salonx, com);
    }
    cout << "\n";
    cout << "A continuacion se le mostrara un menu de usted puede seleccionar con el numero asigando" << "\n";
    cout << "(Presione 4 u otro numero para terminar)" << "\n";
    cout << "\n";
    do{
        cout << "-----------MENU DE OPCIONES-----------" << "\n";
        cout << "(1) Buscar salones por marca" << "\n";
        cout << "(2) Buscar salones por sistema operativo" << "\n";
        cout << "(3) Mostrar todos los salones" << "\n";
        cout << "(4) Terminar" << "\n";
        cout << "--------------------------------------"<< "\n";
        cin >> p;
        if (p == 1) {
            cout << "Que marca deseas buscar? (Toma en cuenta mayusculas y minusculas),";
            cin >> MarcaX;
            for (int i = 0; i < a; i++){
                if (salones[i].getcompu().getMarca() == MarcaX){
                    cout << salones[i].getsalon();
                }
            }
        }
        else if (p == 2){
            cout << "Que sistema operativo deseas buscar? (Toma en cuenta mayusculas y minusculas) ";
            cin >> SOx;
            for (int i = 0; i < a; i++){
                if (salones[i].getcompu().getSO() == SOx){
                    cout << salones[i].getsalon();
                }
            }
        }
        else if (p == 3) {
            for (int i = 0; i < a; i++){
                cout << salones[i].getsalon();
            }
        }
    } while (p >= 1 && p <= 3);
}