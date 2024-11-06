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

void solve(int n)
{
	vector< pair<int,string> > permutate_indexes;
	vector<int> indexes_arr;
	vector<string> nums_arr;

	string indexes, nums;
	int tmp;
	string tmp2;
	
	cin.ignore();
	getline(cin, indexes);
	getline(cin, nums);

	stringstream ss(indexes);
	stringstream ss2(nums);

	while (ss >> tmp)
	{
		indexes_arr.pb(tmp);
	}
	while (ss2 >> tmp2)
	{
		nums_arr.pb(tmp2);
	}
	for (int i = 0; i < nums_arr.size(); ++i)
	{
		permutate_indexes.pb({ indexes_arr[i], nums_arr[i] });
	}

	sort( all(permutate_indexes) );

	for (auto a : permutate_indexes)
	{
		cout << a.second << endl;
	}
	
	if (n > 0) { cout << endl; }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	cin.ignore();
	
	while (T--)
	{
		solve(T);
	}
}

