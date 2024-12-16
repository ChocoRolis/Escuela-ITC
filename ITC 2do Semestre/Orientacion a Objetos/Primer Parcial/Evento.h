#include "Reloj.h"
class Evento{
    public:
        Evento();
        evento(Reloj horaE, int duracionP, string asuntoP);
        void sethorainicio(Reloj horaE);
        void setduracion(int duracionP);
        void setasunto(string asunto)P;
        Reloj gethorainicio();
        int getduracion();
        string getasunto();
    private:
        Reloj horaInicio;
        int duracion;
        string asunto;

};
Evento::Evento(){
    Reloj paso;
    paso.setHora(0);
    paso.setMin(0);
    horaInicio = paso;
    duracion = 0;
    asunto = "";

}
Evento::evento(Reloj horaE, int duracionP, string asuntoP){
    horaInicio = horaE;
    duracion = duracionP;
    asunto = asuntoP;
}
void Evento::sethorainicio(Reloj horaE){
    horaInicio = horaE;
}
void Evento::setasunto(string asuntoP){
    asunto = asuntoP;
}
void Evento::setduracion(int duracionP){
    duracion = duracionP;
}
Reloj Evento::getduracion(){
    return duracion;
}
Reloj Evento::getasunto(){
    return asunto;
}