#include <iostream>
#include <string>
using namespace std;

class Persona{
    public:
        persona();
        persona(string nombreP, string telP);
        void setNombre(string nombreP);
        void setTel(string telP);
        string getNombre();
        string getTel();
    private:
        string nombre;
        string tel;
};
Persona::persona(){
    nombre = " ";
    tel = " ";
}
Persona::persona(string nombreP, string telP){
    nombre = nombreP;
    tel = telP;
}
void Persona::setNombre(string nombreP){
    nombre = nombreP;
}
void Persona::setTel(string telP){
    tel = telP;
}
string getNombre(){
    return nombre;
}
string getTel(){
    return tel;
}