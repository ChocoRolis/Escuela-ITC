#include <iostream>
#include <time.h>
using namespace std;

int main(){
    srand(time(NULL));

    int tRen, tCol, ren, col;

    do {
        cout<<"Cuantos renglones quiere que tenga su arreglo:";
        cin>>tRen;
    } while (tRen < 0);

    do {
        cout<<"Cuantos columnas quiere que tenga su arreglo:";
        cin>>tCol;
    } while (tCol < 0);
   
    int arreglo[tRen][tCol];  
    int suma[0][tCol];
    cout<<"======================"<<endl;

    for (col=0;col<tCol;col++){
        suma[0][col] = 0;
    }

    for(ren=0; ren<tRen;ren++)  
        {for (col=0;col<tCol;col++)  
            {
                arreglo[ren][col]=0+rand()%(10);
                cout<<arreglo[ren][col]<<" ";
            }   
            cout<<" --"<<endl;
        }   
    cout << "======================" << endl;
    for (col=0;col<tCol;col++){
        for (ren=0; ren<tRen;ren++){
            suma[0][col] = suma[0][col] + arreglo[ren][col];
        }
        cout << suma[0][col] << " ";
    }
    cout<<" --"<<endl;
    cout<<"======================"<<endl;
    return 0;
}
