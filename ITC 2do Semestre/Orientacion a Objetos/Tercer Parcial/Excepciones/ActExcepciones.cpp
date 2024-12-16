#include <iostream>
using namespace std;
int main()
{
   /*If we list all the natural numbers below 10 that are 
    multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
    Find the sum of all the multiples of 3 or 5 below 1000*/
    try {
        bool Arr[10] = {true, true,true,true,true,true,true,true,true,true};
        for (int i = 0; i < 11; i++){
            if (Arr[i] != true){ 
                throw -1;
                break;
            }
        }
    } catch (int e){
        if (e == -1){
            cout << "catch";
        }
    }  
}