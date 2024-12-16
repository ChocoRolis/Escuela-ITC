class Fraccion{
    public:
        Fraccion();
        Fraccion(int den, int num);
        void setDen(int den);
        void setNum(int num);
        double calcVreal();
        int getNum();
        int getDen();
        Fraccion operator +(Fraccion f1);
    private:
        int Num, Den;
};
Fraccion::Fraccion(){
    Num = 1;
    Den = 2;
}
Fraccion::Fraccion(int den, int num){
    Den = den;
    Num = num;
}
void Fraccion::setNum(int num){
    Num = num;
}
void Fraccion::setDen(int den){
    Den = den;
}
int Fraccion::getNum(){
    return Num;
}
int Fraccion::getDen(){
    return Den;
}
double Fraccion::calcVreal(){
    return 1.0 * Num / Den;
}
Fraccion Fraccion::operator +(Fraccion f1){
    Fraccion f;
    int num1 = this->getNum() * f1.getDen();
    int num2 = f1.getNum() * this->getDen();
    int den = this->getDen() * f1.getDen();
    f.setDen(den);
    f.setNum(num1 + num2);
    return f;
}