#include "Rectangulo.h"
class RectName : public Rectangulo{
    public:
        RectName():Rectangulo(){nombre = "n/a";};
        RectName(int la, int al, string nom);
        void setNombre(string);
        string getNombre(){return nombre;}
        void dibuja();
    private:
        string nombre;
};
RectName::RectName(int la, int al, string nom):Rectangulo(la, al){
    nombre = nom;
    al = alto;
    la = largo;
}
void RectName::dibuja(){
    for (int r = 1; r <= alto; r++){
        // dibujo completo el primero y el ultimo renglon
        if (r == 1 || r == alto) {
            for (int c = 1; c <= largo; c++)
            cout<<"*";
            cout<<endl;
        }
        else{
            // dibujo solo los caracteres de los extremos en los renglones del medio
            cout<<"*";
            for (int c = 2; c < largo; c++){
                cout<<" ";
                cout<<"*"<<endl;
            }
        }
    }
}