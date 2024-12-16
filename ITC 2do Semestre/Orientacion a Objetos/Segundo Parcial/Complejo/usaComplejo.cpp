#include <iostream> 
using namespace std;
#include "Complejo.h"
int main(){
    Complejo C1, C2, C3;
    bool booleano;
    C1.construir(10.0, 8.0);
    C2.construir(10.0, 8.0);
    C3 = C1 + C2;
    cout << C3.geta() << " + " << C3.getbi() << endl;
    C3 = C1 * C2;
    cout << C3.geta() << " + " << C3.getbi() << endl;
    booleano = C1 == C2;
    cout << booleano << endl;
}