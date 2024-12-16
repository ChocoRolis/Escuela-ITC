class Fraccion{
    public:
        void fraccion();
        void setDen(int den);
        double calcVreal();
        int getNum();
        int getDen();
    private:
        int Num, Den; 
};

void Fraccion::fraccion(){
    Num = 1;
    Den = 2;
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
double calcVreal(){
    return Num / Den;
}