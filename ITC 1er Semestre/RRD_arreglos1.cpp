#include <iostream>
#include <time.h>
using namespace std;
/*
Preguntar al usuario cuantos renglones y columnas tendra el arreglo
llenarlo de numeros aleatorios (0-9) imprimir el arreglo
Enontrar el numero mas pequeÃ±o, el numero mas grande, la suma de todos 
los elementos y el promedio de todos los elementos
*/

int main(){
    srand(time(NULL));

    int tRen, tCol, ren, col, suma=0, mayor=-1,menor=10, posRmenor, posCmenor;
    int posRmayor, posCmayor;

    do {
        cout<<"Cuantos renglones quiere que tenga su arreglo:";
        cin>>tRen;
    } while (tRen < 0);

    do {
        cout<<"Cuantos columnas quiere que tenga su arreglo:";
        cin>>tCol;
    } while (tCol < 0);
   
    int arreglo[tRen][tCol];   // creo el arreglo

    cout<<"======================"<<endl;

    for(ren=0; ren<tRen;ren++)  // variar ren para recorrer renglones
        {for (col=0;col<tCol;col++)  // vario col para recorrer columnas
            {
                arreglo[ren][col]=0+rand()%(10);
                suma=suma+arreglo[ren][col];

                if (arreglo[ren][col]<menor)  // si el valor que acabo de guardar en mi 
                    {menor=arreglo[ren][col];  // arreglo es menor a menor, guardo el valor
                    posRmenor=ren;            // guardo las coordenadas
                    posCmenor=col;                
                    }

                if (arreglo[ren][col]>mayor)
                    {mayor=arreglo[ren][col];
                     posRmayor=ren;
                     posCmayor=col;
                    }

                cout<<arreglo[ren][col]<<" ";
            }   // cierro el ciclo de columnas
            cout<<" --"<<endl;
        }   //cierro el ciclo de renglones
    cout<<"======================"<<endl;
    cout<<"la suma de los elementos de mi arreglo es "<<suma<<endl;
    cout<<"El valor menor de mi arreglo es "<<menor<<" y su posicion es ["<<posRmenor<<"]["<<posCmenor<<"]"<<endl;
    cout<<"El valor mayor de mi arreglo es "<<mayor<<" y su posicion es ["<<posRmayor<<"]["<<posCmayor<<"]"<<endl;
    cout<<"El promedio de los elementos de mi arreglo es "<<suma/(tCol*tRen)<<endl;
    return 0;
}
