#include <iostream>
#include <vector>
#include <utility>
using namespace std;

bool is_possible(vector<int>& ingredients, vector< vector< pair<int,int> > >& dishes, int cant_dishes)
{
    bool possible = true;
    int dish_to_process;
    for (int i = 0; i < cant_dishes; ++i)
    {
        cin >> dish_to_process;

        for (int j = 0; j < dishes[ dish_to_process - 1 ].size(); ++j)
        {
            if (ingredients[ dishes[dish_to_process - 1][j].first - 1 ]  <  dishes[dish_to_process - 1][j].second)
            {
                possible = false;
                break;
            }

            ingredients[ dishes[dish_to_process - 1][j].first - 1 ] -= dishes[dish_to_process - 1][j].second;
        }
    }

    return possible;
}

int main()
{
    int n, m, o;
    int orders_made = 0;

    cin >> n >> m >> o;
    
    vector<int> ingredients(n);
    vector< vector< pair<int,int> > > dishes( m );
    
    // cantidad de cada ingrediente
    for (int i = 0; i < n; ++i)
    {
        cin >> ingredients[ i ];
    }

    // por cada platillo
    for (int i = 0; i < m; ++i)
    {
        int cant_ingredients, first, second;
        cin >> cant_ingredients;
        
        // guardar sus ingredientes y su cantidad
        for (int j = 0; j < cant_ingredients; ++j)
        {
            cin >> first;
            cin >> second;

            dishes[i].push_back( make_pair(first, second) );
        }
    }

    // por cada orden
    for (int i = 0; i < o; ++i)
    {
        int cant_dishes;
        cin >> cant_dishes;
        
        if (is_possible(ingredients, dishes, cant_dishes))
        {
            ++orders_made;
        }            
    }    

    cout << orders_made << endl;
}
