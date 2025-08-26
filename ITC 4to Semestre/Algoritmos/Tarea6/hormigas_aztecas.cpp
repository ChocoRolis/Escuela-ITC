#include <bits/stdc++.h>
using namespace std;

// Rolando Rivas 594276
// Angel Muñoz 604386

void read_input( vector<vector<bool>> &ants, int height, int width )
{
	string line;
	
	for (int i = 1; i < height - 1; ++i)
	{
		cin >> line;
		
		for (int j = 1; j < width - 1; ++j)
		{
			if ( line[ j - 1 ] == '@' )
			{
				ants[ i ][ j ] = true;
			}
		}
	}
}

int transverse( vector<vector<bool>> &ants, int row, int col )
{
	ants[ row ][ col ] = false;

	for (int i = row - 1; i <= row + 1; ++i)
	{
		for (int j = col - 1; j <= col + 1; ++j)
		{
			if ( ants[ i ][ j ] == true)
			{
				return transverse( ants, i, j );
			}
		}
	}
	return 1;
}

void solve()
{
	int height, width; 

	cin >> height >> width;
	height += 2;
	width += 2;

	vector<vector<bool>> ants( height, vector<bool>(width, false) );
	read_input(ants, height, width);

	int total_colonies = 0;

	for (int i = 1; i < height - 1; ++i)
	{
		for (int j = 1; j < width - 1; ++j)
		{
			if ( ants[ i ][ j ] == true )
			{
				total_colonies += transverse( ants, i, j );
			}
		}
	}

	cout << total_colonies << endl;
}

int main()
{
	int cases;
	cin >> cases;

	for (; cases > 0; --cases)
	{
		solve();
	}
}
