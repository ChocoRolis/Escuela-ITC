/*La clase Hora además, debe utilizar sobrecarga de los siguientes operadores:
o >=, <=, == que se usarán para comparar horas .
o + que servirá para sumarle a un objeto hora una cantidad de minutos.
o >> y << para utilizar objetos de tipo Hora con cin y cout.*/
class Hora{
    friend std::istream& operator>>(std::istream &is, Hora &dato);
    friend std::ostream& operator<<(std::ostream &os, Hora dato);
    public:
        Hora();
        Hora(int min, int hora);
        void setHora(int hora);
        void setMin(int min);
        int getHora();
        int getMin();
        Hora operator+(int minu);
        bool operator<=(Hora horaB);
        bool operator>=(Hora horaB);
        bool operator==(Hora horaB);
    private:
        int mm, hh;
};
Hora::Hora(){
    // Constructor deafult para los valores de la hora
    mm = 0;
    hh = 0;
}
Hora::Hora(int min, int hora){
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
Hora Hora::operator+(int minu){
    if (mm + minu >= 60){
        int a = minu / 60;
        hh += a;
        mm = minu - (a * 60);
    }
    else {
        mm += minu;
    }
    return *this;
}
bool Hora::operator<=(Hora horaB){
    if (hh < horaB.getHora()){return true;}
    else if (hh == horaB.getHora()){
        if (mm <= horaB.getMin()) {return true;}
        else {return false;}
    }
    else if (hh > horaB.getHora()){return false;}
}
bool Hora::operator>=(Hora horaB){
    if (hh < horaB.getHora()){return false;}
    else if (hh == horaB.getHora()){
        if (mm >= horaB.getMin()){return true;}
        else {return false;}
    }
    else if (hh > horaB.getHora()){return true;}
}
bool Hora::operator==(Hora horaB){
    if ((hh == horaB.getHora()) && (mm == horaB.getMin())){return true;}
    else {return false;}
}
std::istream& operator>>(std::istream &is, Hora &dato){
    is >> dato.hh;
    is >> dato.mm;
    return is;
}
std::ostream& operator<<(std::ostream &os, Hora dato){
    if (dato.hh < 10){
        if (dato.mm < 10){
            os << '0' << dato.hh << ':' << '0' << dato.mm;
        }
        else {
            os << '0' << dato.hh << ':' << dato.mm;
        }
    }
    else {
        if (dato.mm < 10){
            os << dato.hh << ':' << '0' << dato.mm;
        }
        else {
            os << dato.hh << ':' << dato.mm;
        }
    }
    return os;
}