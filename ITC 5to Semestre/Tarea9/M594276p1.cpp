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

bool backtrack(vi& Ei, vi& Ed, int Ei_wins, int Ed_wins)
{
	int Ei_card, Ed_card;

	if (Ei_wins == 2) { return false; }
	if (Ed_wins == 2) { return true; }

	f(i, 0, Ei.size())
	{
		if (Ei[i] == 0) { continue; }

		f(j, 0, Ed.size())
		{
			if (Ed[j] == 0) { continue; }

			Ei_card = Ei[i];
			Ed_card = Ed[j];

			Ei[i] = 0;
			Ed[j] = 0;

			if (Ei_card > Ed_card)
			{
				if (!backtrack(Ei, Ed, Ei_wins + 1, Ed_wins))
				{
					return false;
				}
			}
			else
			{
				if (!backtrack(Ei, Ed, Ei_wins, Ed_wins + 1))
				{
					return false;
				}
			}

			Ei[i] = Ei_card;
			Ed[j] = Ed_card;
		}
	}
	
	return true;
}

void solve()
{
	vi Ei(3); // Einer
	vi Ed(3); // Eduardo
	int missing_card = 53;
	int result = 0;
	
	cin >> Ei[0] >> Ei[1] >> Ei[2];
	cin >> Ed[0] >> Ed[1];

	while (--missing_card)
	{
		if ( find(all(Ei), missing_card) != Ei.end() ) { continue; } 
		if ( find(all(Ed), missing_card) != Ed.end() ) { continue; }

		Ed[2] = missing_card;

		if ( !backtrack(Ei, Ed, 0, 0) )
		{
			break;
		}
		
		result = missing_card;
	}

	if (result)
	{
		cout << result << endl;
	}
	else
	{
		cout << "NO WAY\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	
	while (T--)
	{
		solve();
	}
}
