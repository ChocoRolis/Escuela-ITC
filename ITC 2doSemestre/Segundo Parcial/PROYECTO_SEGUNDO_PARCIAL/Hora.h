class Hora{
    public:
        Hora();
        void hora(int min, int hora);
        void setHora(int hora);
        void setMin(int min);
        int getHora();
        int getMin();
        void muestraHora();
    private:
        int mm, hh;
};
Hora::Hora(){
    // Constructor deafult para los valores de la hora
    mm = 0;
    hh = 0;
}
void Hora::hora(int min, int hora){
    // Constructor general en el que se usan los datos de entrada para cambiar las variables de Hora
    mm = min;
    hh = hora;
}
void Hora::setHora(int hora){
    // Aplica valor de entrada int a hh
    hh = hora;
}
void Hora::setMin(int min){
    // Aplica valor de entrada int a mm
    mm = min;
}
int Hora::getHora(){
    // Regresa hh como int
    return hh;
}
int Hora::getMin(){
    // Regresa mm como int
    return mm;
}
void Hora::muestraHora(){
    // Despliega la hora en formato del reloj de 24 horas
    // Determina si la hora o minuto es menor a 10 para agregarle por detras un 0
    // Ejemplo: 09:01
    if (hh < 10){
        if (mm < 10){
            cout << '0' << hh << ':' << '0' << mm;
        }
        else {
            cout << '0' << hh << ':' << mm;
        }
    }
    else {
        if (mm < 10){
            cout << hh << ':' << '0' << mm;
        }
        else {
            cout << hh << ':' << mm;
        }
    }
}