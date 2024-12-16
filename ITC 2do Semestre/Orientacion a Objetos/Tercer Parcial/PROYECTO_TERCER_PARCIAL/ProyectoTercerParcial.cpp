#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using std::cout;
using std::string;
#include "Aparato.h"
#include "Cancha.h"
#include "Reserva.h"

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
    clock_t start, end;
    double execution_time;
    start = clock();
    
    std::ifstream entrada;
    std::ofstream salida;
    Servicio *arrServicio[20];
    Aparato arrAparato[20];
    Cancha arrCancha[20];
    Reserva arrReserva[50];
    string renglon, temp, CveServicio, Descripcion, tiempoMax, CostoX15min, Seleccion;
    Hora horaReservacion;
    int contador1 = 0, contador2 = 0, contador3 = 1, contador4 = 0, horas, minutos,
    tiempoenMinutos, IDcliente, &opcion = contador3, numArreglo;
    char TipoServ, instructor;
    bool ConInstructor;

    entrada.open("Servicios.txt");

    while (std::getline(entrada, renglon)){
        temp = renglon.substr(0,1);
        if (temp == "C" || temp == "E" || temp == "B"){
            CveServicio = renglon.substr(0,5);
            arrAparato[contador1].setClave(CveServicio);
            
            renglon.erase(0,6);
            
            temp = renglon[0];
            do{
                temp += renglon[contador3];
                contador3++;
            } while (renglon[contador3] != ' ');
            contador3 = 1;
            arrAparato[contador1].setTiempoMax(string_a_int(temp));
            renglon.erase(0, temp.size() + 1);

            arrAparato[contador1].setTipo(renglon[0]);
            
            temp = renglon[2]; 
            do{
                temp += renglon[2 + contador3];
                contador3++;
            } while (renglon[2 + contador3] != ' ');
            contador3 = 1;
            arrAparato[contador1].setCostoX15min(string_a_int(temp));
            renglon.erase(0, 3 + temp.size());

            (renglon[0] == 'T') ? arrAparato[contador1].setInstructor(true) : arrAparato[contador1].setInstructor(false);

            renglon.erase(0,2);
            arrAparato[contador1].setDescripcion(renglon);
            
            arrServicio[contador4] = &arrAparato[contador1];

            contador1++;
            contador4++;
        }
        else if (temp == "T" || temp == "F" || temp == "V"){
            CveServicio = renglon.substr(0,5);
            arrCancha[contador2].setClave(CveServicio);
            
            renglon.erase(0,6);
                
            temp = renglon[0];
            do{
                temp += renglon[contador3];
                contador3++;
            } while (renglon[contador3] != ' ');
            contador3 = 1;
            arrCancha[contador2].setTiempoMax(string_a_int(temp));
            renglon.erase(0, temp.size() + 1);

            arrCancha[contador2].setTipo(renglon[0]);

            temp = renglon[2];
            do{
                temp += renglon[contador3 + 2];
                contador3++;
            } while (renglon[contador3 + 2] != ' ');
            contador3 = 1;
            arrCancha[contador2].setCostoXHr(string_a_int(temp));

            renglon.erase(0, 3 + temp.size());
            
            temp = renglon[0];
            
            while (renglon[contador3] != ' '){
                temp += renglon[contador3];
                contador3++;
            }
            contador3 = 1;
            arrCancha[contador2].setCantMaxPers(string_a_int(temp));
            
            renglon.erase(0, 1 + temp.size()); 
            arrCancha[contador2].setDeporte(renglon);
        
            arrServicio[contador4] = &arrCancha[contador2];

            contador2++;
            contador4++;
        }
    }
    entrada.close();
    contador1 = 0;

    entrada.open("Reserva.txt");

    while (entrada >> CveServicio >> horas >> minutos >> tiempoenMinutos >> IDcliente){
        arrReserva[contador1].setClaveServicio(CveServicio);
        arrReserva[contador1].setDuracion(tiempoenMinutos);
        arrReserva[contador1].setIdCliente(IDcliente);
        Hora horaInicio(minutos, horas);
        arrReserva[contador1].setHoraInicio(horaInicio);
        contador1++;
    }

    entrada.close();

    do {
        cout << "Para seleccionar una opcion teclee su número correspondiente, cualquier otro será un error\n";
        cout << "-------------------------------------------------\n";
        cout << "|           MENU                                |\n";
        cout << "-------------------------------------------------\n";
        cout << "1. Consultar lista de Servicios\n";
        cout << "2. Consultar lista de Reservaciones\n";
        cout << "3. Consultar reservaciones de un servicio dado\n";
        cout << "4. Consultar reservaciones de una hora especifica\n";
        cout << "5. Hacer una reservación\n";
        cout << "6. Terminar programa\n";
        cout << "-------------------------------------------------\n";
        cout << "     Seleccione opción: ";
        std::cin >> Seleccion;
        cout << "\n";
        bool bandera1 = false;
        contador2 = string_a_int(Seleccion);

        switch (contador2) {
            case 1:
                for (int i = 0; i < contador4; i++){
                    cout << "\n=================================\n";
                    arrServicio[i]->muestra();
                    cout << "=================================\n";
                }
                break;
            case 2:
                for (int i = 0; i < contador1; i++){
                    cout << "\n=================================\n";
                    cout << "Reservación no." << i+1 << "\n";
                    cout << "Clave del servicio: " << arrReserva[i].getClaveServicio() << "\n";
                    cout << "Id del cliente: " << arrReserva[i].getIdCliente() << "\n";
                    cout << "Hora de inicio: " << arrReserva[i].getHoraInicio() << "\n";
                    cout << "Hora de terminación: " << arrReserva[i].calculaHoraFinReservacion() << "\n";
                    cout << "Duracion: " << arrReserva[i].getDuracion() << "min\n";
                    cout << "-----------------------------------\n";
                    cout << "Servicio de la reserva\n";
                    for (int a = 0; a < contador4; a++){
                        
                        if (arrReserva[i].getClaveServicio() == arrServicio[a]->getClave()){
                            arrServicio[a]->muestra();
                            cout << "-----------------------------------\n";
                            cout << "Costo: " << arrServicio[a]->calculaCosto(arrReserva[i].getDuracion()) << "\n";
                        }
                    }
                    cout << "===================================\n";
                }
                break;
            case 3:
                cout << "///////////////////////////////////////////////\n";
                cout << "Lista de servicios disponibles:\n";
                for (int i = 0; i < contador4; i++){
                    cout << "=================================\n";
                    cout << arrServicio[i]->getClave() << "\n";
                }
                cout << "\n-----------------------------------\nInserte la clave del servicio que desea buscar: "; std::cin >> CveServicio;
                for (int i = 0; i < contador4; i++){
                    if (CveServicio == arrServicio[i]->getClave()){
                        cout << "=================================\n";
                        arrServicio[i]->muestra();
                        cout << "Reservaciones: \n";
                        for (int a = 0; a < contador1; a++){
                            if (arrServicio[i]->getClave() == arrReserva[a].getClaveServicio()){
                                cout << "--------------------------------\n";
                                cout << "De " << arrReserva[a].getHoraInicio() << "\n";
                                cout << "A " << arrReserva[a].calculaHoraFinReservacion() << "\n"; 
                            }
                        }
                    }
                }
                cout << "///////////////////////////////////////////////\n";
                break;
            case 4: 
                cout << "/////////////////////////////////////////////////////////////////////\n";
                cout << "Inserte la hora y luego el minuto de la reservacion que desea buscar: \n"; std::cin >> horaReservacion;
                for (int i = 0; i < contador1; i++){
                    if (horaReservacion == arrReserva[i].getHoraInicio()){
                        for (int a = 0; a < contador4; a++){
                            if (arrReserva[i].getClaveServicio() == arrServicio[a]->getClave()){
                                cout << "=================================\n";
                                arrServicio[a]->muestra();
                                cout << "=================================\n";
                            }
                        }
                    }
                }
                break;
            case 5:

        /*Además el programa mostrará el costo de rentar ese servicio por el tiempo
        reservado.*/
                
                cout << "/////////////////////////////////\n";
                cout << "Lista de servicios disponibles:\n";
                for (int i = 0; i < contador4; i++){
                    cout << "=================================\n";
                    cout << arrServicio[i]->getClave() << "\n";
                }

                while (bandera1 == false){
                    cout << "-----------------------------------------------------------\n";
                    cout << "Teclee la clave del servicio que desea rentar (Que exista): "; 
                    std::cin >> CveServicio;
                    for (int i = 0; i < contador4; i++){
                        if (CveServicio == arrServicio[i]->getClave()){
                            bandera1 = true;
                            numArreglo = i;
                        }
                    }
                }

                do {
                    cout << "Inserte su id de cliente (tres digitos): ";
                    std::cin >> IDcliente;
                } while ((IDcliente / 100) > 10 || (IDcliente / 100) < 1);
                
                bandera1 = false;
                while (true){
                    cout << "--------------------------------------------------------------\n";
                    cout << "Inserte la duracion (en minutos) que desea rentar el servicio: ";
                    std::cin >> tiempoenMinutos;
                    if (tiempoenMinutos > arrServicio[numArreglo]->getTiempoMax()){
                        cout << "Sobrepasaste el limite de tiempo de la reserva el cual es: " << arrServicio[numArreglo]->getTiempoMax() << "\n";
                        Opcion:
                        cout << "(Inserte el numero correspondiente)\n1.Insertar una cantidad de tiempo menor\n2.Cancelar reservacion\n"; 
                        std::cin >> opcion;
                    }
                    else{break;}
                    
                    if (opcion == 2){bandera1 = true; break;}
                    
                    else if (opcion != 1 && opcion != 2){
                        cout << "-------------------------\nPor favor seleccione uno de los numeros, vuelva a intentar\n"; 
                        goto Opcion;
                    }
                }
                if (bandera1 == true){goto Salida;}

                cout << "Lista actual de horas ocupadas: \n";
                for (int i = 0; i < contador1; i++){
                    if (CveServicio == arrReserva[i].getClaveServicio()){
                        cout << "=================\n";
                        cout << "De: " << arrReserva[i].getHoraInicio() << "\n";
                        cout << "A: " << arrReserva[i].calculaHoraFinReservacion() << "\n";
                    }
                }

                cout << "---------------------------------------------------------------------\n";
                cout << "Inserte la hora y luego el minuto de la reservacion que desea buscar:\n"; 
                std::cin >> horaReservacion;

                for (int i = 0; i < contador1; i++){
                    if (CveServicio == arrReserva[i].getClaveServicio()){
                        if (horaReservacion >= arrReserva[i].calculaHoraFinReservacion() || (horaReservacion + tiempoenMinutos) <= arrReserva[i].getHoraInicio()){
                            continue;
                        }
                        else {
                            cout << "La hora y el tiempo reservado se solapa con otras reservaciones. Intente otra vez\n";
                        }
                    }
                }

                cout << "---------------\n";
                cout << "Costo: " << arrServicio[numArreglo]->calculaCosto(tiempoenMinutos) << "\n";
                
                arrReserva[contador1 + 1].setClaveServicio(CveServicio);
                arrReserva[contador1 + 1].setDuracion(tiempoenMinutos);
                arrReserva[contador1 + 1].setHoraInicio(horaReservacion);
                arrReserva[contador1 + 1].setIdCliente(IDcliente);
    	        contador1++;
                
                salida.open("Reserva.txt", std::fstream::app);
                salida << "\n" << arrReserva[contador1].getClaveServicio() << " ";

                if (arrReserva[contador1].getHoraInicio().getHora() < 10){
                    salida << '0' << arrReserva[contador1].getHoraInicio().getHora() << " ";
                }
                else {salida << arrReserva[contador1].getHoraInicio().getHora() << " ";}

                if (arrReserva[contador1].getHoraInicio().getMin() < 10){
                    salida << '0' << arrReserva[contador1].getHoraInicio().getMin() << " ";
                }
                else {salida << arrReserva[contador1].getHoraInicio().getMin() << " ";}

                salida << arrReserva[contador1].getDuracion() << " " << arrReserva[contador1].getIdCliente();
                salida.close();
                
                Salida: 
                break;
            case 6: 
                cout << "//////////////////////\n";
                cout << "Que tenga un buen día";
                break;
            default:
                cout <<"Seleccionó una opción que no existe, vuelva a intentarlo\n";
        }
    } while (contador2 != 6);
}