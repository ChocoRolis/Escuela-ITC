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

#define MAX 1000001

using namespace std;

void solve(int uniques, int repeated)
{
	bool time[ MAX ] = { 0 };
	bool overlaps = false;
	int arrive_min, depart_min;
	int interval, interval_cont;
	
	while (uniques--)
	{
		cin >> arrive_min >> depart_min;

		if (overlaps) { continue; }

		f(i, arrive_min, depart_min) 
		{ 
			if (time[i])
			{
				overlaps = true;
			}

			time[ i ] = true; 
		}
	}
	while (repeated--)
	{
		cin >> arrive_min >> depart_min >> interval;

		if (overlaps) { continue; }

		while (arrive_min < MAX  &&  !overlaps)
		{
			f(i, arrive_min, depart_min) 
			{ 
				if (i >= MAX) { break; } 
				if (time[i]) { overlaps = true; } 

				time[ i ] = true; 
			}

			arrive_min += interval;
			depart_min += interval;
		}
	}

	////////// ELIGE EL MEJOR IF-ELSE DE COUTS /////////
	
	cout << ((overlaps) ? "SOLAPAMIENTO\n" : "OK\n");

	////////////////////////////////////////////////////
	/*
	if (overlaps)	{ cout << "SOLAPAMIENTO\n"; 	}
	else 		{ cout << "OK\n"; 		}

	////////////////////////////////////////////////////

	if (overlaps)
	{
		cout << "SOLAPAMIENTO\n";
	}
	else
	{
		cout << "OK\n";
	}

	////////////////////////////////////////////////////
	
	if (overlaps)
		cout << "SOLAPAMIENTO\n";
	else
		cout << "OK\n";
	*/
	////////////////////////////////////////////////////
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int u, r;
	
	while (cin >> u >> r)
	{
		if (!u && !r) { break;}

		solve(u, r);
	}
}

