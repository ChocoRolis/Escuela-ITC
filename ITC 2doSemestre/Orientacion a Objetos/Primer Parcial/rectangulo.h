class Rectangulo {  
    public:
        double calcArea( );
        void setLargo(double la);  
        void setAncho(double an);
        double getAncho();
        double getLargo();
    private:
        double largo, ancho;
};
double Rectangulo :: calcArea( ) {  
    return largo * ancho;
}
void Rectangulo :: setLargo(double la) {  
    largo = la;
}
void Rectangulo :: setAncho(double an) {  
    ancho = an;
}
double Rectangulo :: getLargo() {  
    return largo;
}
double Rectangulo :: getAncho() {  
    return ancho;
}