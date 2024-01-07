#include <iostream>
#include <time.h>
using namespace std;

int main(){
    srand(time(NULL));

    int tRen, tCol, ren, col, resp;
    resp = 1;

    do {
        cout<<"Cuantos renglones y columnas quiere que tenga su arreglo:";
        cin>>tRen;
    } while (tRen < 0);
    tCol = tRen;

    int arreglo[tRen][tCol];  

    cout<<"======================"<<endl;

    for(ren=0; ren<tRen;ren++)  
        {for (col=0;col<tCol;col++)  
            {
                arreglo[ren][col]=0+rand()%(10);
                cout<<arreglo[ren][col]<<" ";
            }   
            cout<<" --"<<endl;
        }   

    cout << "======================" << endl;
    col = 0;
    for (ren=0; ren<tRen;ren++){
        resp = resp * arreglo[ren][col];
        col = col + 1;
    }
    cout<<resp<<endl;
    cout<<" --"<<endl;
    cout<<"======================"<<endl;
    return 0;
}