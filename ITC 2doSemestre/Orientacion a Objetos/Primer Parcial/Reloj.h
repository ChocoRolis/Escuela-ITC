class Reloj {  
    public:
    void setHora(int horaP);
    void setMin(int minP);
    int getHora();
    int getMin();
    void muestra();
    private:
        int hora, min;
};

void Reloj::setHora(int horaP){
    hora = horaP;
}
void Reloj::setMin(int minP){
    min = minP;
}
int Reloj::getHora(){
    return hora;
}
int Reloj::getMin(){
    return min;
}
void Reloj::muestra(){
    if (hora < 10){
        cout << "0" << hora << ":";
    } else {
        cout << hora << ":";
    }

    if (min < 10){
        cout << "0" << min << endl;
    } else {
        cout << min << endl;
    }
}