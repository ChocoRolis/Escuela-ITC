class Pelicula{
    public:
        Pelicula();
        void setNumPeli(int NumPeli);
        void setTitulo(string Titulo);
        void setAnio(int Anio);
        void setDuracion(int Duracion);
        void setGenero(string Genero);
        int getNumPeli();
        int getAnio();
        int getDuracion();
        string getGenero();
        string getTitulo();
        int getlistaActores(int NumActor);
        bool agregarActor(int Id);
        int getcantidadActores();
    private:
        int numPeli, anio, duracion, cantidadActores = 0, listaActores[10];
        string titulo, genero;
};
Pelicula::Pelicula(){
    // Constructor default para valores de Actor
    numPeli = 0;
    anio = 2023;
    duracion = 90;
    titulo = "Pelicula A";
    genero = "Largometraje";
}
void Pelicula::setNumPeli(int NumPeli){
    // Aplica valor de entrada int a numPeli
    numPeli = NumPeli;
}
void Pelicula::setTitulo(string Titulo){
    // Aplica valor de entrada string a titulo
    titulo = Titulo;
}
void Pelicula::setAnio(int Anio){
    // Aplica valor de entrada int a anio
    anio = Anio;
}
void Pelicula::setDuracion(int Duracion){
    // Aplica valor de entrada int a duracion
    duracion = Duracion;
}
void Pelicula::setGenero(string Genero){
    // Aplica valor de entrada string a genero
    genero = Genero;
}
int Pelicula::getNumPeli(){
    // Regresa numPeli
    return numPeli;
}
int Pelicula::getAnio(){
    // Regresa anio
    return anio;
}
int Pelicula::getDuracion(){
    // Regresa duracion
    return duracion;
}
string Pelicula::getGenero(){
    // Regresa genero
    return genero;
}
string Pelicula::getTitulo(){
    // Regresa titulo
    return titulo;
}
int Pelicula::getlistaActores(int NumActor){
    // Regresa el valor de id del arreglo listaActores basado en la entrada de un int
    // La entrada es el numero de Actor en la lista
    // Esta lista es un arreglo de 10 por lo que el numero de actor es el index del arreglo menos 1
    // En los arreglos de enteros las posiciones sin dato tienen un 0 por lo que si solicitan un Actor que no existe se les regresará un 0 indicando que no hay
    if (NumActor > 0){return listaActores[NumActor - 1];}
    return 0;
}
bool Pelicula::agregarActor(int Id){
    // Agrega el Id de un actor al arreglo listaActores y regresa un booleana indicando si se logró con exito
    // Debido a que no se podra agregar el dato si el arreglo esta lleno o si el dato esta duplicado se evalua cada posicion del arreglo con un for que se repite hasta 10 veces
    // Se evalua en cada posicion si el dato es un 0 (indicando que se agregará el Id en esa posicion, se aumenta 1 a cantidadActores y se regresa un true)
    // Se evalua si el dato esta repetido (en tal caso se regresa directamente un false)
    // Si el bucle acaba sin haber regresado ningun valor se regresa un false (indicando que el arreglo estaba lleno)
    for (int i=0;i<10;i++){
        if (listaActores[i] == 0){
            listaActores[i] = Id;
            cantidadActores++;
            return true;
        }
        if (listaActores[i] == Id){return false;}
    }
    return false;
}
int Pelicula::getcantidadActores(){
    // Regresa cantidadActores
    return cantidadActores;
}