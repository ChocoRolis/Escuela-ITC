class Cancha : public Servicio {
    public:
        Cancha():Servicio(){costoXHr = 0.0; CantMaxPers = 0; deporte = "N/A";}
        Cancha(string Clave, int TiempoMax, char Tipo, double costo, int cantMaxPers, string Deporte);
        void setCostoXHr(double Costo){costoXHr = Costo;}
        void setCantMaxPers(int Cant){CantMaxPers = Cant;}
        void setDeporte(string Deporte){deporte = Deporte;}
        double getCostoXhr(){return costoXHr;}
        int getCantMaxPers(){return CantMaxPers;}
        string getDeporte(){return deporte;}
        void muestra();
        double calculaCosto(int horas){return horas * costoXHr;}
    private: 
        double costoXHr;
        int CantMaxPers;
        string deporte;
};
Cancha::Cancha(string Clave, int TiempoMax, char Tipo, double costo, int cantMaxPers, string Deporte):Servicio(Clave, TiempoMax, Tipo){
    clave = Clave; tiempoMax = TiempoMax; tipo  = Tipo;
    costoXHr = costo; CantMaxPers = cantMaxPers; deporte = Deporte;
}
void Cancha::muestra(){
    cout << "Clave del Aparato: " << clave << "\n";
    cout << "Tiempo maximo de uso: " << tiempoMax << "min\n";
    switch (tipo){
        case 'T':
            cout << "De tipo: Cancha Tenis\n";
            break;
        case 'F':
            cout << "De tipo: Cancha Fronton\n";
            break;
        case 'V':
            cout << "De tipo: Cancha Volley Ball\n";
            break;
        default:
            cout << "De tipo: N/A\n";
    }
    cout << "Costo por hora " << costoXHr << "\n";
    cout << "Capacidad maxima de personas: " << CantMaxPers << "\n";
    cout << "Deporte: " << deporte << "\n";
}