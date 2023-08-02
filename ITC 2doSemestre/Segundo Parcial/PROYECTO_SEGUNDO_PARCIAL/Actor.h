class Actor{
    public:
        Actor();
        void actor(string Nombre, int Id);
        void setNombre(string Nombre);
        void setId(int Id);
        string getNombre();
        int getId();
        void muestraActor();
    private:
        string nombre;
        int id;
};
Actor::Actor(){
    // Constructor default para valores de Actor
    nombre = "Fulano";
    id = 0;
}
void Actor::actor(string Nombre, int Id){
    // Constructor general en el que se usan los datos de entrada para cambiar las variables de Funcion
    nombre = Nombre;
    id = Id;
}
void Actor::setNombre(string Nombre){
    // Aplica valor de entrada string a nombre
    nombre = Nombre;
}
void Actor::setId(int Id){
    // Aplica valor de entrada int a id
    id = Id;
}
string Actor::getNombre(){
    // Regresa nombre
    return nombre;
}
int Actor::getId(){
    // Regresa id
    return id;
}
void Actor::muestraActor(){
    // Despliega el nombre con su respectivo id
    cout << nombre << " con Id de " << id << "\n";
}