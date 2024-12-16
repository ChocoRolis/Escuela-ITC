#include <iostream>
#include "Taxi.h"
using namespace std;

int main(){
    Taxi ataxi[100];
    int c = 0, ident;
    char o = 's';
    string n, t;
    Persona person;
    while (o == 's'){
        cout << "Numero identificador del taxi: " << c;
        cin >> ident;
        cout << "Dame la persona responsable del taxi: " << c;
        cin >> n;
        cout << "Dame el telefono del responsable del taxi: ";
        cin >> t;
        person.persona(n,t);
        ataxi[c].setResp(person);
        ataxi[c].setIdent(ident);
        c++;
        cout << "Agregar otro taxi (s/n)?";
        cin >> o;
    }
    o == 'n';
    do{
        cout << "a) Lista de taxis";
        cout << "b) Lista de taxis por responsable";
        cout << "c) Agregar otro taxi";
        cout << "n) Salir";
        cin >> o;
        switch(o){
            case 'a': 
                for (int i = 0; i <c; i++){
                    cout << "Para el taxi " << ataxi[i].getIdent() << " ";
                    cout << "Con el responsable " << ataxi[i].getResp().getNombre() << "\n";
                    cout << "Con telefono " << ataxi[i].getResp().getTel()<< "\n";cout << "Para el taxi " << ataxi[i].getIdent() << " "; 
                }
            case 'b': 
                cout << "Dame el nombre del responsable a cargo del taxi: \n";
                cin >> n;
                for (int i = 0; i<c; i++){
                    if (n == ataxi[i].getResp().getNombre()){
                        cout << "Para el taxi " << ataxi[i].getIdent() << " ";
                        cout << "Con el responsable " << ataxi[i].getResp().getNombre() << "\n";
                        cout << "Con telefono " << ataxi[i].getResp().getTel()<< "\n";
                    }
                }
                break;
            case 'c':
                cout << "Numero identificador del taxi: " << c;
                cin >> ident;
                cout << "Dame la persona responsable del taxi: " << c;
                cin >> n;
                cout << "Dame el telefono del responsable del taxi: ";
                cin >> t;
                person.persona(n,t);
                ataxi[c].setResp(person);
                ataxi[c].setIdent(ident);
                c++;
                break;
        }
    } while (o == 'n');
}