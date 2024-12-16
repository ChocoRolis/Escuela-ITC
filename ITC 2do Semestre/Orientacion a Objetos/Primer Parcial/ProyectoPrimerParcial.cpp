#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    ifstream entrada;
    ofstream salida;
    string archivo;
    cout << "-------------------------------------------"<< "\n";
    cout << "  Bienvenido al documentador de programas" << "\n";
    cout << "-------------------------------------------"<< "\n";
    cout << "\n";
    cout << "Escriba el nombre del programa C++ que desee documentar (sin extension): ";
    cin >> archivo;
    salida.open(archivo + ".html");
    salida << "<!DOCTYPE html>" << "\n" << "<html>" << "\n" << "<head>" << "\n" << "<title>" << "\n";
    salida << "Documentacion del archivo: " << archivo << "\n";
    salida << "</title>" << "\n" << "</head>"<< "\n" << "<body>" << "\n";
    archivo = archivo + ".cpp";
    entrada.open(archivo);
    while (!entrada.eof()){
        getline(entrada, archivo);
        if (archivo[0] == '@'){
            if (archivo.substr(1,8) == "progName"){
                archivo.erase(0,9);
                salida << "<h2>" << "\n" << "Programa: " << archivo << "<br>"<< "\n" << "</h2>"<< "\n";
            }
            if (archivo.substr(1,6) == "author"){
                archivo.erase(0,7);
                salida << "<strong> Autor: </strong> " << archivo << "<br>\n";
            }
            if (archivo.substr(1,4) == "date"){
                archivo.erase(0,5);
                salida << "<strong> Fecha: </strong> " << archivo << "<br>\n";
            }
            if (archivo.substr(1,8) == "funcName"){
                archivo.erase(0,9);
                salida << "<h3>" << "\n" << "<hr><br> Funcion " << archivo<< "<br>" << "\n"<< "</h3>";
            }
            if (archivo.substr(1,4) == "desc"){
                archivo.erase(0,5);
                salida << "<strong> Descripcion: </strong> " << archivo << "<br>\n";
            }
            if (archivo.substr(1,5) == "param"){
                archivo.erase(0,6);
                 salida << "<strong> Parametros: </strong> " << archivo << "<br>\n";
            }
            if (archivo.substr(1,6) == "return"){
                archivo.erase(0,7);
                salida << "<strong> Valor de retorno: </strong> " << archivo << "<br>\n";
            }
        }
        
    }
    salida << "</body>\n</html>";
}