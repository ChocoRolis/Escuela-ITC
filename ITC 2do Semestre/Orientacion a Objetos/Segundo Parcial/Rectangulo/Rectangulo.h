class Rectangulo{ 
    public:
        Rectangulo();
        Rectangulo(int la, int al); 
        void dibuja();
        void setLargo(int la);
        void setAlto(int al);
    protected:
        int largo, alto;
}; 
Rectangulo::Rectangulo(){
    largo = 2;
    alto = 2;
}
Rectangulo::Rectangulo(int la, int al){
    largo = la;
    alto = al;
}
void Rectangulo::dibuja(){ 
    for (int r = 1; r <= alto; r++){
        // dibujo completo el primero y el ultimo renglon
        if (r == 1 || r == alto) {
            for (int c = 1; c <= largo; c++){
            cout<<"*";
            cout<<endl;
            }
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
void Rectangulo::setAlto(int al){
    alto = al;
}
void Rectangulo::setLargo(int la){
    largo = la;
}