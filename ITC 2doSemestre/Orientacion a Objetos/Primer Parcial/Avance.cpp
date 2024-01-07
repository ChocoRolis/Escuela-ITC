/**
@progName ISBNCalculadora
@author Rolando Rivas
@date 20/Ene/2023
*/
#include <iostream>
#include <string>
using namespace std;

/**
@funcName residuo
@desc Calcula el residuo de una division entre 11 a partir de una sumatoria de 8 enteros
@param string Num. Debe ser una cadena de 8 numeros enteros positivos 
@return Regresa el valor del residuo n
*/

int residuo(string Num) {
    int s = 0, i, n;
    for (i = 0; i<8; i++){
        n = (int) Num[i];
        n = n - 48;
        s = s + (i * n);
    }
    n = s % 11;
    return n;
}

/**
@funcName main
@desc Pide al usuario la cadena de 8 digitos, la registra en una variable num 
@param Char Y (Si este cambia el bucle que hace las operaciones finaliza). Int r (Es el residuo resultante de la funcion "residuo"). string Num (Es la cadena de digitos que el usuario dio de entrada y permitira hacer el nuevo ISBN)
@return
*/

//si

int main(){
    char Char = 'Y', h;
    int r;
    string num;
    while (Char == 'Y'){
        cout << "Teclea el numero de 9 digitos" << endl;
        cin.ignore();
        getline(cin, num);
        r = residuo(num);
        if (r < 10){
            h = (char) r;
            num += (h + 48);
        }
        else if (r > 10) {
            num += "X";
        }
        cout << "Tu nuevo ISBN es " << num << endl;
        cout << "Quieres repetir el proceso? (Y/n)";
        cin >> Char;        
    }
}
