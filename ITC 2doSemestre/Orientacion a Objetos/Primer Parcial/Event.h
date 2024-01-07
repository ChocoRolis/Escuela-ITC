#include <string>
#include "Reloj.h"

class Evento{
  public: //metodo de acceso publico
    Evento();
    Evento(Reloj horaE, int duracion, string asunto);
    void setHoraInicio(Reloj horaE);
    void setDuracion(int dura);
    void setAsunto(string asuntoP);
    Reloj getHoraInicio();
    int getDuracion();
    string getAsunto();

  private: //metodo de acceso privado
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
Evento::Evento(Reloj horaE, int duracionP, string asuntoP){
  horaInicio = horaE;
  duracion = duracionP;
  asunto = asuntoP;
}

void Evento::setHoraInicio(Reloj horaE){
  horaInicio = horaE;
  
}
void Evento::setDuracion(int dura){
  duracion = dura;
}
void Evento::setAsunto(string asuntoP){
  asunto = asuntoP;
}

Reloj Evento::getHoraInicio(){
  return horaInicio;
}

int Evento::getDuracion(){
  return duracion;
}

string Evento::getAsunto(){
  return asunto;
}