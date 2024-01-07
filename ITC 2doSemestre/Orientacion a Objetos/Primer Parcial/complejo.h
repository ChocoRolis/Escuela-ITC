class Complejo{
    public:
        void construir(double A, double BI);
        construirD();
        void seta(double n);
        void setbi(double n);
        double geta();
        double getbi();
        double sumaC(double A, double BI);
        double restaC(double A, double BI);
    private:
        double a, bi;
};
void Complejo::construir(double A, double BI){
    a = A;
    bi = BI;
}
Complejo::construirD(){
    a = 0.0;
    bi = 0.0;
}
void Complejo::seta(double n){
    a = n;
}
void Complejo::setbi(double n){
    bi = n;
}
double Complejo::geta(){
    return a;
}
double Complejo::getbi(){
    return bi;
}
double Complejo::sumaC(double A, double BI){
    a = a + A;
    bi = bi + BI;
}
double Complejo::restaC(double A, double BI){
    a = a - A;
    bi = bi - BI;
}