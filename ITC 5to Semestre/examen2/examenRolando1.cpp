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

void solve()
{
	int volume, mask;
	double left, right;
	int left_volume, right_volume;
	string str_mask;
	
	cin >> hex >> volume >> str_mask >> left >> right;

	str_mask.erase(0,2);
	mask = (int) bitset<8>( str_mask ).to_ulong();
	
	left_volume = (volume & 0xFF00) >> 8  &  mask;
	right_volume = volume & 0xFF  &  mask;

	left_volume += (left_volume * left) / 100;
	right_volume += (right_volume * right) / 100;

	if (left_volume > 0xFF) { left_volume = 0xFF; }
	if (right_volume > 0xFF) { right_volume = 0xFF; }
	
	volume = (left_volume << 8) | right_volume;

	cout << "0x" << uppercase << hex << volume << " " << dec << volume << endl;
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

