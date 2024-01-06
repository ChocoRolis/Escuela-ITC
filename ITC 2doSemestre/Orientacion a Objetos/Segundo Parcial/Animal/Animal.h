#include <string>
class Animal{
    public:
        Animal(string nom, int anio);
        int calculaEdad();
        virtual void habla() = 0; //Nota que son funciones virtual pura.
        virtual void muestra() = 0; // ENTONCES la clase es abstracta.
    protected:
        string sNombre;
        int iAnioNacim;
};
Animal::Animal(string nom, int anio){
    sNombre = nom;
    iAnioNacim = anio;
}
int Animal::calculaEdad(){
    return 2019 - iAnioNacim;
}