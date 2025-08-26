#include <iostream>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	
	cout << "R: " << hex << (n & 255) << endl;
	cout << "G: " << hex <<  (n & (65535 - 255)) / 256 << endl;
	cout << "B: " << hex << (n & (16777215 - 65535)) / 65536 << endl;
	cout << endl;
}

int main()
{
	int t; 
	cin >> t;
	while (t--) { solve(); }
}
