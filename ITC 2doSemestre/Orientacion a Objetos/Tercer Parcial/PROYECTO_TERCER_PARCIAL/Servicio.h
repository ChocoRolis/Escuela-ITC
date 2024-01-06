class Servicio {
    public:
        Servicio(){clave = "N/A"; tiempoMax = 0; tipo = ' ';}
        Servicio(string Clave, int TiempoMax, char Tipo){clave = Clave; tiempoMax = TiempoMax; tipo  = Tipo;}
        void setClave(string Clave){clave = Clave;}
        void setTiempoMax(int TiempoMax){tiempoMax = TiempoMax;}
        void setTipo(char Tipo){tipo  = Tipo;}
        string getClave(){return clave;}
        int getTiempoMax(){return tiempoMax;} 
        char getTipo(){return tipo;}
        virtual void muestra() = 0;
        virtual double calculaCosto(int tiempo) = 0;
    protected:
        string clave;
        int tiempoMax;
        char tipo;    
};
