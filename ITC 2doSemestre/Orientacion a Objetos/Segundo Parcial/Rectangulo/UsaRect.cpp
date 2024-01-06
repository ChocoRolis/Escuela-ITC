#include <iostream>
#include <string>
using namespace std;
#include "RectName.h"

int main(){ 
    Rectangulo r1, r2(10,4);
    RectName r3(9, 7, "roberto"), r4(12, 5, "ana"); 

    cout<<"\nEste es el rectangulo 1"<<endl;
    r1.dibuja();
    cout<<"\nEste es el rectangulo 2"<<endl;
    r2.dibuja();
    cout<<"\nEste es el rectangulo 3"<<endl;
    r3.dibuja();
    cout<<"\nEste es el rectangulo 4"<<endl;
    r4.dibuja();
}