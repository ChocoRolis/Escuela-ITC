//Angel Uriel Muñoz Moreno #604386

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m = 0, n = 0;

    while (true)
    {
        cin >> m >> n;
        if (m == 0 && n == 0)
            break;

        vector<int> hosp1(m);
        vector<int> hosp2(n);

        for (int i = 0; i < m; i++) {
            cin >> hosp1[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> hosp2[i];
        }

        //ordenar los vectores para poder hacer busqueda 
        sort(hosp1.begin(), hosp1.end());
        sort(hosp2.begin(), hosp2.end());

        vector<int> repetidos; 
        vector<int> noRepetidos; //lista de los que no se repiten

        for (int i = 0; i < m; i++) {
            if (binary_search(hosp2.begin(), hosp2.end(), hosp1[i])) {
                if (repetidos.empty() || hosp1[i] != repetidos.back()) {
                    repetidos.push_back(hosp1[i]);
                }
            }
        }
 

        for (int i = 0; i < m - 1; i++)
        {
            if (hosp1[i] == hosp1[i + 1] && (repetidos.empty() || hosp1[i] != repetidos.back()))
            {
                repetidos.push_back(hosp1[i]);
            }
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (hosp2[i] == hosp2[i + 1] && (repetidos.empty() || hosp2[i] != repetidos.back()))
            {
                repetidos.push_back(hosp2[i]);
            }
        }
        
        sort(repetidos.begin(), repetidos.end());
        repetidos.erase(unique(repetidos.begin(), repetidos.end()), repetidos.end());

        for (int i = 0; i < m; i++) {
            if (!binary_search(repetidos.begin(), repetidos.end(), hosp1[i])) {
                noRepetidos.push_back(hosp1[i]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (!binary_search(repetidos.begin(), repetidos.end(), hosp2[i])) {
                noRepetidos.push_back(hosp2[i]);
            }
        }
        
        
        

        if (repetidos.empty()) { //si no hay repetidos la carita
            cout << ":)" << endl;
        } else {
            for (int i = 0; i < repetidos.size(); i++) {
                cout << repetidos[i] << " ";
            }
            cout << endl;
        }

        

        cout << noRepetidos.size() << endl; //mostrar cantidad de no repetidos
    }
            
        return 0;
}
