#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main(){
    system ("cls");
    int i,num,c;
    int A[10];
    srand (time(NULL));
    c = 0;
    cout << "---- ---- ---- " << endl;

    do {
        cout << "Dime cuantos numeros quieres generar (>0 y <10) : "; cin>> num;
    }
    while (num <= 0 || num >= 10);

    for (i=0; i< num; i++){
        A[i] = rand()%10;
        cout << A[i] << endl;
    }

    for (i=0 ; i<num ; i++){
        if (c == 2){
            cout << A[i] << endl;
            c = 0;
        }
        else {
            cout << A[i];
            c = c + 1;
        }
    }

    getch();
    return 0;
}