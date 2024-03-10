//Rolando Rivas #594276
//Angel Muñoz #604386
//Tarea 4
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct chamba {
    int notif;
    int trabajo;
};

bool comparar(chamba& a, chamba& b){
    return a.trabajo > b.trabajo; 
}

int main(){
    int n = 0, tiempo = 0, aviso = 0;
    
    
    while(true){ 

        cin >> n;
        vector<chamba> proyecto(n);

        if (n == 0) break; //hasta que n sea 0 se dan casos de prueba
        
        for (int i = 0; i < n; i++)
        {
            cin >> proyecto[i].notif >> proyecto[i].trabajo; 
            //structuras god al rescate para hacer pares pq me da hueva hacer un vector de pares
        }

        sort(proyecto.begin(), proyecto.end(), comparar); 
        //ordenar segun tiempo de trabajo 

        for (int i = 0; i < n; i++)
        {
            aviso += proyecto[i].notif; 
            //sumar tiempo de notificacion requerido
            tiempo = max(tiempo, aviso + proyecto[i].trabajo); 
            //checar entre total de tiempo de notificar + trabajo actual vs tiempo anterior
        }
        
        cout << tiempo << endl;

        for (int i = 0; i < n; i++)
        {
            cout << proyecto[i].notif << " " << proyecto[i].trabajo << endl;
        }

        // Limpiar todo para el siguiente caso
        proyecto.clear(); 
        aviso = 0;
        tiempo = 0;

    }    

            return 0;
            
}

//Solucion previa era registrando en un vector y actualizar valores previos con el notif nuevo pero no era necesario pues no pide cuando termina cada uno
//Entonces bajamos de O(n^2) a O(nlogn) por el sort y solo checamos el tiempo maximo 
