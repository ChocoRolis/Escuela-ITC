#include <iostream>
using namespace std;
#include "Animal.h"


// CLASE GATO
class Gato : public Animal{
    public:
        Gato(string nom, int anio):Animal(nom, anio){sNombre = nom; iAnioNacim = anio;}
        void habla();
        void muestra();
};
void Gato::habla(){
    cout << "MIAU";
}
void Gato::muestra(){
    cout << "Hola, soy un gato de nombre " << sNombre << " y tengo " << calculaEdad() << " años!\n";
}



// CLASE PERRO
class Perro : public Animal{
    public:
        Perro(string nom, int anio):Animal(nom, anio){sNombre = nom; iAnioNacim = anio;}
        void habla();
        void muestra();
};
void Perro::habla(){
    cout << "GUAU";
}
void Perro::muestra(){
    cout << "Hola, soy un perro de nombre " << sNombre << " y tengo " << calculaEdad() << " años!\n";
}


// MAIN 
int main(){
    Animal *arrAnimal[3];
    Gato gato1("Silvestre", 1947), gato2("Tom", 1940);
    Perro perro1("Fido", 2000);
    
    arrAnimal[0] = &gato1;
    arrAnimal[1] = &perro1;
    arrAnimal[2] = &gato2;

    for (int i = 0; i < 3; i++){
        arrAnimal[i]->muestra();
        arrAnimal[i]->habla();
        printf("\n");
    }
}