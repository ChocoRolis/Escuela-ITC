#include "Computadora.h"
class Salon{
    public:
        Salon();
        void salon(int salonA, Computadora compuA);
        int getsalon();
        Computadora getcompu();
        void setsalon(int salonA);
        void setcompu(Computadora compuA);
    private:
        int saloN;
        Computadora compu;
};
Salon::Salon(){
    saloN = 1101;
    compu.Build();
}
void Salon::salon(int salonA, Computadora compuA){
    saloN = salonA;
    compu.setMarca(compuA.getMarca());
    compu.setSO(compuA.getSO());
    compu.setRAM(compuA.getRAM());
}
int Salon::getsalon(){
    return saloN;
}
Computadora Salon::getcompu(){
    return compu;
}
void Salon::setsalon(int salonA){
    saloN = salonA;
}
void Salon::setcompu(Computadora compuA){
    compu.setMarca(compuA.getMarca());
    compu.setSO(compuA.getSO());
    compu.setRAM(compuA.getRAM());
}