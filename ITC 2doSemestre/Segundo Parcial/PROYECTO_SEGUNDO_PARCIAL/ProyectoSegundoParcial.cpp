#include <iostream>
#include <string>
#include <fstream>
using std::cout;
using std::cin;
using std::string;
#include "Funcion.h"
#include "Actor.h"
#include "Pelicula.h"

int string_a_int(string num){
    int ValorInt = 0, tempo = 1;
    for (int i = 0; i < num.size(); i++){
        for (int a = i+1; a < num.size(); a++){
            tempo = tempo * 10;
        }
        ValorInt += ((int) num[i] - 48) * tempo;
        tempo = 1;
    }
    return ValorInt;
}

int main(){
    
    Actor arrActor[20];
    Funcion arrFuncion[20];
    Pelicula arrPelicula[20];
    Hora arrHora[20];
    std::ifstream entrada;
    string renglon, actorId, actorNom, temp, cve;
    int contador = 0, contador2 = 1, contador3 = 0, sala, Pelinum, MM, HH, id;
    char cancelacion;
    bool bandera = false;

    entrada.open("Actores.txt");

    while (std::getline(entrada, renglon)){
        actorId = renglon.substr(0,2);
        actorNom = renglon.erase(0,2);
        arrActor[contador].actor(actorNom, string_a_int(actorId));
        contador++;
    }

    contador = 0;

    entrada.ignore();
    entrada.close();
    entrada.open("Peliculas.txt");

    while (std::getline(entrada, renglon)){
        arrPelicula[contador].setNumPeli(string_a_int(renglon.substr(0,3)));
        arrPelicula[contador].setAnio(string_a_int(renglon.substr(4,4)));
        arrPelicula[contador].setDuracion(string_a_int(renglon.substr(9,3)));

        renglon.erase(0,13);
        temp = renglon[0];

        do {
            temp += renglon[contador2];
            contador2++;
        } while (renglon[contador2] != ' ');

        arrPelicula[contador].setGenero(temp);
        renglon.erase(0,(temp.length() + 1));
        temp.erase();
        contador2 = string_a_int(renglon.substr(0,1));

        for (int i = 0; i < contador2; i++){
            arrPelicula[contador].agregarActor(string_a_int(renglon.substr((2+3*i),2)));
            contador3 = 2 + 3*(i+1);
        }      

        renglon.erase(0,contador3);
        arrPelicula[contador].setTitulo(renglon);
        contador2 = 1;
        contador++;
    }
    
    entrada.close();
    
    cout << "Antes de empezar, se requiere que usted como usuario coloque los datos para cada una de las funciones.\nCuantas funciones desea registrar? ";
    cin >> contador2;

    for (int i = 0; i < contador2; i++){
        cout << "Teclee la clave de Función de la funcion no." << i+1 << " ";
        cin >> cve;
        cout << "Teclee el número de película de la funcion no." << i+1 << " ";
        cin >> Pelinum;
        cout << "Teclee la sala de la funcion no." << i+1 << " ";
        cin >> sala;
        cout << "Teclee la hora y despues el minuto de la funcion no." << i+1 << "\n";
        cin >> HH;
        cin >> MM;
        arrHora[i].hora(MM,HH);
        arrFuncion[i].funcion(cve,sala,Pelinum,arrHora[i]);
        cout << "Desea continuar (Y/n)? ";
        cin >> cancelacion;
        if (cancelacion == 'n'){contador2 = i+1; break;}
    }

    do {
        cout << "Para seleccionar una opcion teclee su número correspondiente, cualquier otro será un error\n";
        cout << "-------------------------------------------------\n";
        cout << "            MENU\n";
        cout << "-------------------------------------------------\n";
        cout << "1. Consultar todos los actores de la lista\n";
        cout << "2. Consultar todas las peliculas de la lista\n";
        cout << "3. Consultar todas las funciones de la lista\n";
        cout << "4. Consultar funciones por hora\n";
        cout << "5. Consultar por clave de funcion (Cve)\n";
        cout << "6. Consultar lista de peliculas por actor\n";
        cout << "7. Terminar programa\n";
        cout << "-------------------------------------------------\n";
        cout << "     Seleccione opción: ";
        cin >> contador3;
        cout << "\n";
        switch (contador3) {
            case 1:
                cout << "///////////////////////////////\n";
                for (int i = 0; i < 20; i++) {
                    arrActor[i].muestraActor();
                }
                cout << "///////////////////////////////\n";
                break;
            case 2:
                cout << "///////////////////////////////\n";
                for (int i = 0; i < contador; i++){
                    cout << "===================================\n";
                    cout << "Pelicula No." << i+1 << "\n";
                    cout << "Título: " << arrPelicula[i].getTitulo() << "\n";
                    cout << "Del " << arrPelicula[i].getAnio() << "\n";
                    cout << "Duración: " << arrPelicula[i].getDuracion() << " min\n";
                    cout << "Género: " << arrPelicula[i].getGenero() << "\n";
                    cout << "Actores:\n";
                    for (int k = 1; k < 11; k++){
                        for (int j = 0; j < 20; j++){
                            if (arrPelicula[i].getlistaActores(k) == arrActor[j].getId()){
                                cout << "\t" << arrActor[j].getNombre() << "\n";
                            }
                        }
                    }
                    cout << "====================================\n";
                }
                cout << "///////////////////////////////\n";
                break;
            case 3:
                cout << "///////////////////////////////\n";
                for (int i = 0; i < contador2; i++){
                    cout << "====================================\n";
                    cout << "Función No. " << i+1 << "\n";
                    cout << "Clave de función: " << arrFuncion[i].getCve() << "\n";
                    cout << "Título: ";
                    for (int a = 0; a < contador; a++){
                        if (arrFuncion[i].getNumPeli() == arrPelicula[a].getNumPeli()){
                            cout << arrPelicula[a].getTitulo() << "\n";
                        }
                    }
                    cout << "Sala: " << arrFuncion[i].getSala() << "\n";
                    cout << "Hora: ";
                    arrFuncion[i].getHora().muestraHora();
                    cout << "\n====================================\n";
                }
                cout << "///////////////////////////////\n";
                break;
            case 4:
                cout << "///////////////////////////////\n";
                do {
                    cout << "Teclea la hora (reloj de 24 horas) ";
                    cin >> HH;
    	            cout << "Teclea el minuto (de 0 a 59) ";
                    cin >> MM;
                    if ((HH < 0 || HH > 23) || (MM < 0 || MM > 59)){ 
                        printf("Los datos que ingresó son invalidos, intente de nuevo...");
                    }
                } while ((HH < 0 || HH > 23) || (MM < 0 || MM > 59));
                for (int i = 0; i < contador2; i++){
                    if (HH == arrFuncion[i].getHora().getHora()){
                        if (MM == arrFuncion[i].getHora().getMin()){
                            cout << "======================================\n";
                            for (int a = 0; a < contador; a++){
                                if (arrFuncion[i].getNumPeli() == arrPelicula[a].getNumPeli()){
                                cout << arrPelicula[a].getTitulo() << "\n";
                                }
                            }
                            cout << "Sala: " << arrFuncion[i].getSala();
                            cout << "\n======================================\n";
                        }
                    }
                }
                cout << "////////////////////////////////\n";
                break;
            case 5:
                cout << "////////////////////////////////\n";
                cout << "Teclee la clave de Función: ";
                cin >> cve;
                for (int i = 0; i < contador2; i++){
                    if (cve == arrFuncion[i].getCve()){
                        cout << "Sala: ";
                        for (int a = 0; a < contador; a++){
                            if (arrFuncion[i].getNumPeli() == arrPelicula[a].getNumPeli()){
                                cout << "Título: " << arrPelicula[a].getTitulo() << "\n";
                                cout << "Duración: " << arrPelicula[a].getDuracion() << "\n";
                                cout << "Género: " << arrPelicula[a].getGenero() << "\n";
                                cout << "Con los actores: \n";
                                for (int k = 1; k < 11; k++){
                                    for (int j = 0; j < 20; j++){
                                        if (arrPelicula[i].getlistaActores(k) == arrActor[j].getId()){
                                            cout << "\t" << arrActor[j].getNombre() << "\n";
                                        }
                                    }
                                }                
                            }
                        }
                        cout << "Hora: ";
                        arrFuncion[i].getHora().muestraHora();
                        cout << "\n";
                    }
                }
                cout << "////////////////////////////////\n";
                break;
            case 6:
                cout << "////////////////////////////////\n";
                cout << "Teclee el id del actor que desee buscar ";
                cin >> id;
                for (int i = 0; i < 20; i++){
                    if (id == arrActor[i].getId()){bandera = true;}
                }
                if (bandera == false) {cout << "No existe id\n"; break;}
                for (int a = 0; a < contador; a++){
                    for (int k = 1; k < 11; k++){
                        if (id == arrPelicula[a].getlistaActores(k)){
                            cout << "=============================\n";
                            cout << "Título: " << arrPelicula[a].getTitulo() << "\n";
                            cout << "Anio: " << arrPelicula[a].getAnio() << "\n";
                            cout << "=============================\n";
                        }
                    }
                }
                cout << "////////////////////////////////\n";
                break;
            case 7:
                cout << "////////////////////////////////\n";
                cout << "Que tenga un buen día";
                break;
            default:
                cout <<"Seleccionó una opción que no existe, vuelva a intentarlo";
        }
    } while (contador3 != 7);

    printf("\n\nDoy mi palabra que he realizado esta actividad con integridad académica. - Rolando Rivas 594276");    
    return 0;
}