#include <iostream>
#include <vector>
#include <string>
using namespace std;

int char_a_int(char num) 
{
    return static_cast<int>(num - '0');
}

int main() 
{
    int casos;
    cin >> casos;

    int resultados[casos];
    
    for (int i = 0; i < casos; i++) resultados[i] = 0;

    for (int i = 0; i < casos; i++) 
    {
        int size_instrucciones;
        cin >> size_instrucciones;

        int instrucciones[size_instrucciones];
        cin.ignore();  

        for (int j = 0; j < size_instrucciones; j++) 
        {
            string arg;
            getline(cin, arg);

            if (arg[1] == 'D') 
            {
                resultados[i] += 1;
                instrucciones[j] = 1;
            } 
            else if (arg[1] == 'T') 
            {
                resultados[i] += -1;
                instrucciones[j] = -1;
            } 
            else if (arg[1] == 'G') 
            {
                int tmp = char_a_int(arg[10]);
                resultados[i] += instrucciones[tmp - 1];
                instrucciones[j] = instrucciones[tmp - 1];
            }
        }
    }

    for (int i = 0; i < casos; i++) 
    {
        cout << resultados[i] << endl;
    }

    return 0;
}
// Damos nuestra palabra que hemos hecho esta actividad con integridad academica.
