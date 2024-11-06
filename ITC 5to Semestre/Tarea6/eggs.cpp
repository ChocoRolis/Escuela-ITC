#include <bits/stdc++.h>
#define f(i,a,b) for(int i = (a); i < (b); ++i)
#define rf(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) x.begin(), x.end()
#define ll long long 
#define vi vector<int>
#define vs vector<string>
#define pb push_back
#define yes() cout << "YES\n"
#define no() cout << "NO\n"

using namespace std;

int cycle_lcm(vector<vi>& eggs) // Calcula Minimo Comun Multiplo 
{
	vi sizes(eggs.size());
	
	f(i, 0, eggs.size())
	{
		sizes[i] = eggs[i].size() - 1;
	}

	int num = accumulate( all(sizes), 1, 
			[](int a, int b){
				return lcm(a, b); 
			});

	return num;
}

void solve(vector<vi>& eggs)
{
	int total_days = 0;
	int cycle_day = 0;
	int days_limit = cycle_lcm( eggs );
	int min_eggs, min_eggs_index;
	bool it_repeats; // si se repite el numero minimo de huevos

	while (cycle_day < days_limit	and   eggs.size() > 0)
	{
		min_eggs = INT_MAX;		
		++cycle_day;
		
		f(i, 0, eggs.size())
		{
			if (eggs[i][0] >= eggs[i].size())
			{
				eggs[i][0] = 1;
			}

			int day = eggs[i][0];

			if (eggs[i][ day ] < min_eggs)
			{
				min_eggs = eggs[i][ day ];
				min_eggs_index = i;
				it_repeats = false;
			}
			else if (eggs[i][ day ] == min_eggs)
			{
				it_repeats = true;
			}

			++eggs[i][0];
		}

		if (!it_repeats)
		{
			eggs.erase(eggs.begin() + min_eggs_index);
			total_days += cycle_day;
			cycle_day = 0;
		}
	}

	cout << eggs.size() << " " << total_days << endl;
}

void read()
{
	int hens_size;
	int cycle_size;
	int eggs_per_day;

	cin >> hens_size;

	vector<vi> egg_cycles( hens_size );

	f(i, 0, hens_size)
	{
		cin >> cycle_size;

		egg_cycles[i].pb( 1 ); // Contador que representa el index del dia actual en el ciclo
		
		f(j, 0, cycle_size)
		{
			cin >> eggs_per_day;

			egg_cycles[i].pb( eggs_per_day );
		}
	}

	solve(egg_cycles);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	
	while (T--)
	{
		read();
	}
}

