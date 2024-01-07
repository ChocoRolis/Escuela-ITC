#include <iostream>
#include <string>
using namespace std;
// Usuario por defecto: uno1
// Constraseña por defecto: 1
int main() {
    int a,c,d;
    string u;
    cout << "Ingrese su usuario" << endl;
    cin >> u;
    if (u == "uno1") {
        cout << "Ingrese su contraseña ";
        cin >> a;
        c = 1;
        d = 1;
        while ((c < 3) && (a != 1)) { 
            if (a != 1){
                cout << "Intentelo otra vez" << endl;
                cin >> a;
                c = c + 1;
                d = d + 1;
            }
            else {
                c = c + 1;
            }
            if (a == 1) {
                d = 0;
            }
        }
        if (d >= 3){
            cout << "Tu cuenta ha sido bloqueada 24hr"<< endl;
            cout << "Usaste los " << c << " intentos" << endl;
        }
        else {
            cout << "¡Bienvenido!" << endl;
            cout << "Usaste " << c << " intentos" << endl;
        }
    }
    else {
        cout << "Usuario registrado incorrecto, intente de nuevo";
    }
    return 0;
}