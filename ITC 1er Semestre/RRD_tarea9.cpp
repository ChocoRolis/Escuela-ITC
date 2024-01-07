#include <iostream>
using namespace std;
//Crear un programa que le pida al usuario dos numeros reales diferentes y decir cual de los dos es el mayor y cual el menor.tres veces.
int main (){
    int n1,n2,i;
    for (i = 0 ; i<3 ; i++){
        // Se pide al usuario dos numeros
        cout << "Dame un numero ";
        cin >> n1;
        cout << "Dame otro numero ";
        cin >> n2;
        // Se crea una condicional que analiza los dos numeros para determinar cual es mayor o menor
        if (n1 > n2){
            cout << "El numero mayor es " << n1 << endl;
            cout << "El numero menor es " << n2 << endl;
        }
        else {
            cout << "El numero mayor es " << n2 << endl;
            cout << "El numero menor es " << n1 << endl;
        }
        // Una vez terminado el 
        system("pause");
    }
    return 0;
}