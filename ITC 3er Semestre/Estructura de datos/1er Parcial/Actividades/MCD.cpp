#include <iostream>
using namespace std;

int mcd(int a, int b){
    if (b == 0){
        return a;
    }
    else{
        return mcd(b, a % b);
    }
}

int main(){
    int num1, num2;

    cout << "Primer numero: "; cin >> num1;
    cout << "Segundo numero: "; cin >> num2;
    cout << "El Maximo Comun Divisor es: " << mcd(num1, num2);
}