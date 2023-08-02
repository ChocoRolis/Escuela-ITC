#include "Hora.h"
class Reserva {
    public:
        Reserva(){claveServicio = "N/A"; idCliente = 0; duracion = 0;}
        Reserva(string ClaveServicio, int IdCliente, int hora, int minuto, int Duracion);
        void setClaveServicio(string ClaveServicio){claveServicio = ClaveServicio;}
        void setIdCliente(int IdCliente){idCliente = IdCliente;}
        void setDuracion(int Duracion){duracion = Duracion;}
        void setHoraInicio(Hora HoraInicio){horaInicio = HoraInicio;}
        string getClaveServicio(){return claveServicio;}
        int getIdCliente(){return idCliente;}
        int getDuracion(){return duracion;}
        Hora getHoraInicio(){return horaInicio;}
        Hora calculaHoraFinReservacion();
    private:
        string claveServicio;
        int idCliente, duracion;
        Hora horaInicio;
};
Reserva::Reserva(string ClaveServicio, int IdCliente, int hora, int minuto, int Duracion){
    claveServicio = ClaveServicio;
    idCliente = IdCliente;
    horaInicio.setHora(hora);
    horaInicio.setMin(minuto);
    duracion = Duracion;
}
Hora Reserva::calculaHoraFinReservacion(){
    return horaInicio + duracion;
}
