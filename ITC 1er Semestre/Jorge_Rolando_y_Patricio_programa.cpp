#include <iostream>
#include <string>
using namespace std;
void pausa();
int main () {
   string materia_1="8:00am Diseno de interfaces  2408", materia_2="10:00 am Fisica 2  1408", materia_3= " 11:30 am Matematicas  1305", materia_4= " 10:00 am Programacion  3305", materia_5= "11:30 am Bienestar  1408", materia_6="1:00 pm Meta  1203", materia_7="8:30 am Etica  1307"; 
   int d;
    bool bandera=false;
    char tecla;


    do{
         cout<<"\n--------------";
         cout<<"\nHorario de la semana";
         cout<<"\n--------------";
         cout<<"\n Lunes (1)";
         cout<<"\n Martes (2)";
         cout<<"\n Miercoles (3)";
         cout<<"\n Jueves (4)";
         cout<<"\n Viernes (5)";
         cout<<"\n Salir (0)";
         cout<<"\n--------------";
         cout<<"\n Que dia quiere ver de su horario de clases?";
         cin>>d;
         
         switch(d){
            
            case 1:
            
               cout<<"\nLunes "<<materia_1;
               cout<<"\nLunes "<<materia_2;
               cout<<"\nLunes "<<materia_3;
               pausa();
               break;
            case 2: 
            
               cout<<"\nMartes "<<materia_4;
               cout<<"\nMartes "<<materia_5;
               cout<<"\nMartes "<<materia_6;
               pausa();
               break;
            
            case 3:
            
               cout<<"\nMiercoles "<<materia_7;
               cout<<"\nMiercoles "<<materia_3;
               pausa();
               break;
          
            case 4:
           
                cout<<"\nJueves "<<materia_1;
                cout<<"\nJueves "<<materia_2;
                cout<<"\nJueves "<<materia_3;
                pausa();
                break;
            case 5: 
         
                cout<<"\nViernes "<<materia_4;
                cout<<"\nViernes "<<materia_5;
                cout<<"\nViernes "<<materia_6;
                pausa();
                break;
            case 0:
           
               bandera=true;
               cout<<"\nRegresa pronto";
          
            break;
            
            default:
				system("cls");
				cout << "Opcion no valida.\a\n";
				pausa();
				break;
        }
      
    }  while (bandera!=true);

    return 0;   
}
void pausa()
{
    cout << "\nPulsa una tecla para continuar...";
    getwchar();
    getwchar();
}


