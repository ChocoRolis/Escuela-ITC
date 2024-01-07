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
    int multi[0][tCol];
    cout<<"======================"<<endl;

    for (ren=0; ren<tRen;ren++){
        multi[0][ren] = 1;
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

    for (ren=0; ren<tRen;ren++){
        for (col=0;col<tCol;col++){
            multi[0][ren] = multi[0][ren] * arreglo[ren][col];
        }
        cout << multi[0][ren] << " ";
    }

    cout<<" --"<<endl;
    cout<<"======================"<<endl;
    return 0;
}