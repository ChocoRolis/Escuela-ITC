#include <iostream>
#include <string>
using namespace std;

const string BLACK = "%%%%%%%%"; // Define una línea de un cuadro negro
const string WHITE = "        "; // Define una línea de un cuadro blanco
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