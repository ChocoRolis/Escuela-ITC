#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main() {
    system ("cls");
    int i,num,d;
    int A[100];
    srand (time(NULL));
    cout << "---- ---- ---- " << endl;

    do {
        cout << "Dime cuantos numeros quieres generar (>0 y <100)  :"; cin>> num;
    }
    while (num <= 0 || num >= 100);

    d = num - 1;
 
    for (i=0; i< num; i++){
        A[i] = rand()%11;
        cout << A[i]<<endl;
    }
    cout << "\n";
    for (i = 0; i < num ; i++){
        cout << A[d] << endl;
        d = d - 1;
    }
    getch();
    return 0;
}