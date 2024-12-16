/*1. Escribe la clase MaterialDeLectura que tenga como atributos:
• Título
• Autor
Debe tener también constructor default y con parámetros, métodos de acceso y de
modificación para sus atributos y un método virtual llamado muestra.*/
class MaterialDeLectura {
    public:
        MaterialDeLectura(){Titulo = "N/A"; Autor = "N/A";}
        MaterialDeLectura(string titulo, string autor){Titulo = titulo; Autor = autor;}
        string getTitulo(){return Titulo;}
        string getAutor(){return Autor;}
        void setTitulo(string titulo){Titulo = titulo;}
        void setAutor(string autor){Autor = autor;}
        virtual void muestra();
    protected:
        string Titulo, Autor;
};
void MaterialDeLectura::muestra(){
    cout << "------------------------------------------------" << "\n";
    cout << "Libro: '" << Titulo << "' con el autor '" << Autor << "'\n";
    cout << "------------------------------------------------" << "\n";
}