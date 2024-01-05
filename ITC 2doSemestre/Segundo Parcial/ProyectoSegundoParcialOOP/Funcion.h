#include "Hora.h"
class Funcion{
    public:
        Funcion();
        void funcion(string CveFuncion, int Sala, int NumPeli, Hora horA);
        string getCve();
        int getSala();
        int getNumPeli();
        Hora getHora();
        void setCve(string CveFuncion);
        void setSala(int Sala);
        void setNumPeli(int NumPeli);
        void setHora(Hora horA);
        void muestraFuncion();
    private:
        string cveFuncion;
        int sala, numPeli;
        Hora hora;
};
Funcion::Funcion(){
    // Constructor default para valores de Funcion
    cveFuncion = "00000";
    sala = 0;
    numPeli = 0;
}
void Funcion::funcion(string CveFuncion, int Sala, int NumPeli, Hora horA){
    // Constructor general en el que se usan los datos de entrada para cambiar las variables de Funcion
    cveFuncion = CveFuncion;
    sala = Sala;
    numPeli = NumPeli;
    hora = horA;
}
string Funcion::getCve(){
    // Regresa cveFuncion como string
    return cveFuncion;
}
int Funcion::getSala(){
    // Regresa sala como int
    return sala;
}
int Funcion::getNumPeli(){
    // Regresa numPeli como int
    return numPeli;
}
Hora Funcion::getHora(){
    // Regresa hora como objeto de la clase "Hora"
    return hora;
}
void Funcion::setCve(string CveFuncion){
    // Aplica valor de entrada string a cveFuncion
    cveFuncion = CveFuncion;
}
void Funcion::setSala(int Sala){
    // Aplica valor de entrada int a sala
    sala = Sala;
}
void Funcion::setNumPeli(int NumPeli){
    // Aplica valor de entrada int a numPeli
    numPeli = NumPeli;
}
void Funcion::setHora(Hora horA){
    // Aplica valor de entrada (objeto) Hora a hora
    hora = horA;
}
void Funcion::muestraFuncion(){
    // Se despliegan los diferentes atributos en orden 
    // Se usa el metodo muestraHora de la clase Hora para desplegar la hora pero debido a que es una funcion void se separa del cout sin poner endl
    cout << "La funcion de numero " << numPeli << " con CVE de funcion " << cveFuncion << " se estrena en la sala " << sala << " a la hora ";
    hora.muestraHora();
}