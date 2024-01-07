#include "Persona.h"

class Taxi{
    public:
        Taxi();
        void setResp(Persona respP);
        void setIdent(int indentP);
        Persona getResp();
        int getIdent();
    private:
        Persona resp;
        int ident;
};
Taxi::Taxi(){
    Persona paso;
    resp = paso;
    ident = 0;
}
void Taxi::setResp(Persona respP){
    resp = respP;
}
void Taxi::setIdent(int indentP){
    ident = indentP;
}
Persona Taxi::getResp(){
    return resp;
}
int Taxi::getIdent(){
    return ident;
}