#include "Servicio.h"
class Aparato : public Servicio {
    public: 
        Aparato():Servicio(){costoX15min = 0.0; conInstructor = false; descripcion = "N/A";}
        Aparato(string Clave, int TiempoMax, char Tipo, double Costo, bool ConInstructor, string _Descripcion);
        void setCostoX15min(double Costo){costoX15min = Costo;}
        void setInstructor(bool ConInstructor){conInstructor = ConInstructor;}
        void setDescripcion(string Descripcion){descripcion = Descripcion;}
        double getCostoX15min(){return costoX15min;}
        bool getConInstructor(){return conInstructor;}
        string getDescripcion(){return descripcion;}
        void muestra();
        double calculaCosto(int tiempo){return tiempo * costoX15min;}
    private:
        double costoX15min;
        bool conInstructor;
        string descripcion;
}; 
Aparato::Aparato(string Clave, int TiempoMax, char Tipo, double Costo, bool ConInstructor, string _Descripcion):Servicio(Clave, TiempoMax, Tipo){
    clave = Clave; tiempoMax = TiempoMax; tipo  = Tipo;
    costoX15min = Costo; conInstructor = ConInstructor; descripcion = _Descripcion;
}
void Aparato::muestra(){
    cout << "Clave del Aparato: " << clave << "\n";
    cout << "Tiempo maximo de uso: " << tiempoMax << "min\n";
    switch (tipo){
        case 'C':
            cout << "De tipo: Caminadora\n";
            break;
        case 'E':
            cout << "De tipo: Escaladora\n";
            break;
        case 'B':
            cout << "De tipo: Bicicleta\n";
            break;
        default:
            cout << "De tipo: N/A\n";
    }
    cout << "Costo por 15 minutos: " << costoX15min << "$\n";
    (conInstructor) ? cout << "Con instructor: Sí\n" : cout << "Con instructor: No\n";
    cout << "Descripción: " << descripcion << "\n";
}