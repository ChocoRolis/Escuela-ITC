/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;
//cambiar el valor de las variables para desplegar * en el blanco en lugar del negro
const string BLACK = "********"; // Define una línea de un cuadro negro
const string WHITE = "........"; // Define una línea de un cuadro blanco
int main ()
{
 string whiteRow; // Un renglón que comienza con un cuadro blanco
 string blackRow; // Un renglón que comienza con un cuadro negro
 // Crear un renglón blanco-negro al concatenar las cadenas básicas
 whiteRow = WHITE + BLACK + WHITE + BLACK +
 WHITE + BLACK + WHITE + BLACK;
 // Crear un renglón negro-blanco al concatenar las cadenas básicas
 blackRow = BLACK + WHITE + BLACK + WHITE +
 BLACK + WHITE + BLACK + WHITE;

 // Imprimir cinco renglones blanco-negro
 cout << whiteRow << endl;
 cout << whiteRow << endl;
 cout << whiteRow << endl;
 cout << whiteRow << endl;
 cout << whiteRow << endl;
 // Imprimir cinco renglones negro-blanco
 cout << blackRow << endl;
 cout << blackRow << endl;
 cout << blackRow << endl;
 cout << blackRow << endl;
 cout << blackRow << endl;
 // Imprimir cinco renglones blanco-negro
 cout << whiteRow << endl;
 cout << whiteRow << endl;
 cout << whiteRow << endl;
 cout << whiteRow << endl;
 cout << whiteRow << endl;
 // Imprimir cinco renglones negro-blanco
 cout << blackRow << endl;
 cout << blackRow << endl;
 cout << blackRow << endl;
 cout << blackRow << endl;
 cout << blackRow << endl;
 // Imprimir cinco renglones blanco-negro
 cout << whiteRow << endl;
 cout << whiteRow << endl;
 cout << whiteRow << endl;
 cout << whiteRow << endl;
 cout << whiteRow << endl;
 // Imprimir cinco renglones negro-blanco
 cout << blackRow << endl;
 cout << blackRow << endl;
 cout << blackRow << endl;
 cout << blackRow << endl;
 cout << blackRow << endl;
 // Imprimir cinco renglones blanco-negro
 cout << whiteRow << endl;
 cout << whiteRow << endl;
 cout << whiteRow << endl;
 cout << whiteRow << endl;
 cout << whiteRow << endl;
 // Imprimir cinco renglones negro-blanco
 cout << blackRow << endl;
 cout << blackRow << endl;
 cout << blackRow << endl;
 cout << blackRow << endl;
 cout << blackRow << endl;
 return 0;
}
