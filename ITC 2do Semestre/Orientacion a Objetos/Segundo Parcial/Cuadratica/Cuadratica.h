class Cuadratica{
    public:
        Cuadratica();
        Cuadratica(int iA, int iB, int iC);
        void muestra();
        Cuadratica operator+(Cuadratica);
        Cuadratica operator*(int);
        bool operator==(Cuadratica);
        friend Cuadratica operator-(Cuadratica,Cuadratica);
        friend Cuadratica operator+=(Cuadratica, Cuadratica);
        friend Cuadratica operator++(Cuadratica);
    private:
        int iCoefA, iCoefB, iCoefC;
};

Cuadratica::Cuadratica(){
iCoefA = 1;
iCoefB = 1;
iCoefC = 1;
}
Cuadratica::Cuadratica(int iA, int iB, int iC){
iCoefA = iA;
iCoefB = iB;
iCoefC = iC;
}
void Cuadratica::muestra(){
    if (iCoefA != 0){
        cout << iCoefA;
        cout << "x^2 ";
    }   

    if (iCoefB != 0){
        if (iCoefB > 0){
            cout << " + ";
            cout << iCoefB;
            cout << "x ";
        }
    }

    if (iCoefC != 0){
        if (iCoefC > 0){
            cout << " + ";
            cout << iCoefC << endl;
        } 
    }
}
Cuadratica operator-(Cuadratica c1, Cuadratica c2){
    Cuadratica c3;
    c3.iCoefA = c1.iCoefA - c2.iCoefA;
    c3.iCoefB = c1.iCoefB - c2.iCoefB;
    c3.iCoefC = c1.iCoefC - c2.iCoefC;
    return c3;
}
Cuadratica operator+=(Cuadratica c1, Cuadratica c2){
    c1.iCoefA = c1.iCoefA - c2.iCoefA;
    c1.iCoefB = c1.iCoefB - c2.iCoefB;
    c1.iCoefC = c1.iCoefC - c2.iCoefC;
    return c1;
}

Cuadratica operator++(Cuadratica c1){
    c1.iCoefC = c1.iCoefC + 1;
    return c1;
}
Cuadratica Cuadratica::operator+(Cuadratica c1){
    Cuadratica c3; 
    c3.iCoefA = iCoefA + c1.iCoefA;
    c3.iCoefB = iCoefB + c1.iCoefB;
    c3.iCoefC = iCoefC + c1.iCoefC;
    return c3;
}
Cuadratica Cuadratica::operator*(int valor){
    iCoefA = iCoefA * valor;
    iCoefB = iCoefB * valor;
    iCoefC = iCoefC * valor;
    return *this;
}
bool Cuadratica::operator==(Cuadratica c1){
    if ((iCoefA == c1.iCoefA && iCoefB == c1.iCoefB) && iCoefC == c1.iCoefC){
        return true;
    }
    else {return false;}
}