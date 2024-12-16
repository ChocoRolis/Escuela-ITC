using namespace std;
#include <iostream>
#include <string.h>
#include "Event.h"

int main() {
  Reloj horaE;
  int hora, min, cont = 0;
  Evento arEvento[10];
  int duracion;
  string asunto;
  char opcion = 's';
  do{
    cout<<"Dame hora: ";
    cin >> hora;
    cout<<"Dame minutos: ";
    cin >> min;
    horaE.setHora(hora);
    horaE.setMin(min);
    arEvento[cont].setHoraInicio(horaE);
    cout << "Dame la duracion: ";
    cin >> duracion;
    arEvento[cont].setDuracion(duracion);
    cout << "Dame el asunto: ";
    cin >> asunto;
    arEvento[cont].setAsunto(asunto);
    cout  << "Quiere otro evento? s/n ";
    cin >> opcion;
    cont ++;
    
  }while(opcion =='s');
  for (int i = 0; i<cont; i++){
    //Reloj paso;
    cout << "hora inicio del evento [" << i+1 <<"] ";  
    arEvento[i].getHoraInicio().muestra();
    cout<< " Duracion: " << arEvento[i].getDuracion()<<endl;
    arEvento[i].getDuracion();
    cout<< " Asunto: "<<arEvento[i].getAsunto()<<endl;
    
  }
  
  return 0;
}