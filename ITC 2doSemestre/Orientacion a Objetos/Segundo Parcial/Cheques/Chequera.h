#include "CtaBanc.h"
class Chequera:public CtaBanc{
    public:
        Chequera():CtaBanc(){Comision = 0.06;};
        Chequera(double comision, int n, double s):CtaBanc(n, s){Comision = comision; numCuenta = n; saldo = s;};
        void setComision(double comision){Comision = comision;}
        double getComision(){return Comision;}
        bool retira(double cant); 
        void mostrar();
    private:
        double Comision;
};
bool Chequera::retira(double cant){
    if (saldo >= cant){
        saldo -= cant + (cant*Comision);
	    return true;
    }
    else{
	    return false;
    }
}
void Chequera::mostrar(){
	cout<<"\nTu cuenta "<<numCuenta<< " tiene un saldo: "<<saldo<<endl;
    cout<<"Y su comisión de retiro es del %" << Comision*100 <<endl;
}