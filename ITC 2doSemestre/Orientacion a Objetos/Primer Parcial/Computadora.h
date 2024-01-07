#include <string>
class Computadora {
    public:
        Build();
        void build(string aMarca, string aSO, int aRAM);
        string getMarca();
        string getSO();
        int getRAM();
        void setMarca(string aMarca);
        void setSO(string aSO);
        void setRAM(int aRAM);
    private:
        string Marca, SO;
        int RAM;
};
Computadora::Build(){
    Marca = "Dell";
    SO = "Windows";
    RAM = 16;
}
void Computadora::build(string aMarca, string aSO, int aRAM){
    Marca = aMarca;
    SO = aSO;
    RAM = aRAM;
}
string Computadora::getMarca(){
    return Marca;
}
string Computadora::getSO(){
    return SO;
}
int Computadora::getRAM(){
    return RAM;
}
void Computadora::setMarca(string aMarca){
    Marca = aMarca;
}
void Computadora::setSO(string aSO){
    SO = aSO;
}
void Computadora::setRAM(int aRAM){
    RAM = aRAM;
}