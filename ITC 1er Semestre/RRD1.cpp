#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main() {
    system ("cls");
    int i,num;
    int A[100];
    srand (time(NULL));
    cout << "---- ---- ---- " << endl;

    do {
        cout << "Dime cuantos numeros quieres generar (>0 y <100)  :"; cin>> num;
    }
    while (num <= 0 || num >= 100);

    for (i=0; i< num; i++){
        A[1] = rand()%11;
        cout << A[1]<<endl;
    }
    
    getch();
    return 0;
}