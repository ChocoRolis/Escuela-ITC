#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool esEntero(string entrada)
{
    for (int i = 0; i < entrada.size(); i++)
    {
        if ( (int) entrada[i] < 48 || (int) entrada[i] > 57 )
        {
            return false;
        }
    }
    return true;
}

int string_a_int(string num)
{
    int ValorInt = 0, tempo = 1;
    for (int i = 0; i < num.size(); i++)
    {
        for (int a = i+1; a < num.size(); a++)
        {
            tempo = tempo * 10;
        }
        ValorInt += ((int) num[i] - 48) * tempo;
        tempo = 1;
    }
    return ValorInt;
}

int main()
{
    long int num = 0, n;
    string input;
    
    cout << "Este programa es un algoritmo que calcula la diferencia entre el cuadrado de la suma de los numeros del 1 a n y la suma de los cuadrados del 1 a n\n" ;
    cout << "Introduzca un numero n entero no negativo: ";
    cin >> input;
    
    while (!esEntero(input))
    {
        cout << "Error, no introdujo un número entero\n";
        cin >> input;
    }
    
    n = string_a_int(input);
   
    num = pow( n * ( n + 1 ) / 2, 2 ) - ( n * ( n + 1 ) * ( 2 * n + 1 ) ) / 6;
    
    cout << num << endl;
}

/*
PRUEBA 1:
    Ambiente: Laptop Dell, Windows 10, GDB online
    Datos entrada: 1000
    Resultado esperado: 250166416500
    Resultado obtenido: 250166416500

PRUEBA 2:
    Ambiente: Laptop Dell, Windows 10, GDB online
    Datos entrada: asdf
    Resultado esperado: "Error, no introdujo un numero entero" 
    Resultado obtenido: "Error, no introdujo un numero entero" 
*/