/*3. Escribe ahora la clase TutorialElectrónico que sea una subclase de la clase
MaterialDeLectura y además de los atributos que hereda tenga como atributos:
• url
• fecha de última actualización (guarda este dato como un string)
Debe tener también constructor default y con parámetros, métodos de acceso y modificación y
la redefinición del método muestra.*/
class TutorialElectronico : public MaterialDeLectura {
    public: 
        TutorialElectronico();
        TutorialElectronico(string titulo, string autor, string Url, string fecha);
        string getUrl(){return url;}
        string getFecha(){return fechaLastUpdate;}
        void setFecha(string fecha){fechaLastUpdate = fecha;}
        void setUrl(string Url){url = Url;}
        void muestra();
    private:
        string url, fechaLastUpdate;
};
TutorialElectronico::TutorialElectronico():MaterialDeLectura(){
    Titulo = "N/A"; Autor = "N/A";
    url = "N/A"; fechaLastUpdate = "N/A";
}
TutorialElectronico::TutorialElectronico(string titulo, string autor, string Url, string fecha):MaterialDeLectura(titulo, autor){
    Titulo = titulo; Autor = autor;
    url = Url; fechaLastUpdate = fecha;
}
void TutorialElectronico::muestra(){
    cout << "------------------------------------------------" << "\n";
    cout << Autor << ". (" << fechaLastUpdate << "). " << Titulo << ". " << url << "\n";
    cout << "------------------------------------------------" << "\n";
    //Nombre del autor. [Nombre de usuario en Youtube] (fecha). Título del video [Video]. Youtube. http://youtube.com/url-del-video
}