class Complejo{
public:
void construir(double A, double BI);
Complejo();
void seta(double n);
void setbi(double n);
double geta();
double getbi();
double sumaC(double A, double BI);
double restaC(double A, double BI);
friend Complejo operator+(Complejo c1, Complejo c2);
friend Complejo operator*(Complejo c1, Complejo c2);
friend bool operator==(Complejo c1, Complejo c2);

private:
double a, bi;
};
void Complejo::construir(double A, double BI){
a = A;
bi = BI;
}
Complejo::Complejo(){
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
Complejo Complejo::operator+(Complejo c1, Complejo c2){
    Complejo c3;
    double A, Bi;
    A = c1.geta() + c2.getbi();
    Bi = c1.getbi() + c2 .getbi();
    c3.construir(c1, c2);
}
Complejo Complejo:operator*(Complejo c1, Complejo c2){
    Complejo c3;
    double A, Bi;
    A = c1.geta() * c2.getbi();
    Bi = c1.getbi() * c2 .getbi();
    c3.construir(c1, c2);
}
bool Complejo::operator==(Complejo c1, Complejo c2){
    if (c1.geta() == c2.geta() && c1.getbi() == c2.getbi()){
        return true;
    }
    return false;
}