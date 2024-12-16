/*2. Escribe ahora la clase Libro que sea una subclase de la clase MaterialDeLectura y que
además de los atributos que hereda tenga como atributos:
• Editorial
• Número de páginas
Debe tener constructor default y con parámetros, métodos de acceso y modificación para sus
atributos y la redefinición del método muestra.*/
#include "MaterialDeLectura.h"
class Libro : public MaterialDeLectura {
    public:
        Libro();
        Libro(string titulo, string autor, string editorial, int numPaginas);
        string getEditorial(){return Editorial;}
        int getNumPaginas(){return NumPaginas;}
        void setEditorial(string editorial){Editorial = editorial;}
        void setNumPaginas(int numpaginas){NumPaginas = numpaginas;}
        void muestra();
    private:
        string Editorial;
        int NumPaginas;
};
Libro::Libro():MaterialDeLectura(){
    Titulo = "N/A"; Autor = "N/A";
    NumPaginas = 0; Editorial = "N/A";
}
Libro::Libro(string titulo, string autor, string editorial, int numPaginas):MaterialDeLectura(titulo, autor){
    Titulo = titulo; Autor = autor;
    NumPaginas = numPaginas; Editorial = editorial;
}
void Libro::muestra(){
    cout << "------------------------------------------------" << "\n";
    cout << Autor << ". " << Titulo << " (No. paginas: " << NumPaginas << "). " << Editorial << "\n";
    cout << "------------------------------------------------" << "\n";
}