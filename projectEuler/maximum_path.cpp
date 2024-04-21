#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int llu;

int sumas[100][100] = {};

llu maximum_path_sum( vector<vector<int>> &arbol, int profundo, int ancho )
{
	if ( profundo == arbol.size() - 1 )
	{
		return arbol[ profundo ][ ancho ];
	}
	if ( sumas[ profundo ][ ancho ] != 0 )
	{
		return sumas[ profundo ][ ancho ];
	}

	llu path1 = arbol[ profundo ][ ancho ] + maximum_path_sum( arbol, profundo + 1, ancho );
	llu path2 = arbol[ profundo ][ ancho ] + maximum_path_sum( arbol, profundo + 1, ancho + 1 );
	
	sumas[ profundo ][ ancho ] = max( path1, path2);

	return max( path1, path2);
}

int main() {
	int lines, input;
	cin >> lines;

	vector<vector<int>> arbol(lines);	
	for (int i = 0; i < arbol.size(); ++i)
        {
        	for (int j = 0; j < i + 1; ++j)
                {
                    	cin >> input;
                    	arbol[i].push_back(input);
                }
        }

	cout << maximum_path_sum( arbol, 0, 0 ) << endl;
}
