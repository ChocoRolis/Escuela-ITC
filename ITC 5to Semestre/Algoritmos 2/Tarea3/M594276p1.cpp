// Rolando Rivas Davalos 594276
//
// auxilio

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

inline int char_to_int(char c)
{
	return (int) c - '0';
}

void resize_nums(string &num1, string &num2)
{
	string zeros = "";
	if (num1.size() > num2.size())
	{
		f(i, 0, num1.size() - num2.size())
		{
			zeros += '0';
		}

		num2 = zeros + num2;
	}
	else 
	{
		f(i, 0, num2.size() - num1.size())
		{
			zeros += '0';
		}

		num1 = zeros + num1;
	}
}


string addition(string &num1, string &num2)
{
	string result = "";
	int carry = 0; 

	rf(i, num1.size() - 1, 0)
	{
		carry += char_to_int( num1[i] ) + char_to_int( num2[i] );
		result = to_string( carry % 10 ) + result;
		carry /= 10;
	}

	if (carry > 0) 
	{ 
		result = to_string(carry) + result; 
	}

	return result;
}

string product(string &num1, string &num2)
{
	string result = "", tmp = "";
	int carry = 0, zeros = 0;

	rf(i, num2.size() - 1, 0)
	{
		f(i, 0, zeros) { tmp += '0'; }
		
		if (num2[i] == 0) { continue; }

		rf(j, num1.size() - 1, 0)
		{
			carry += char_to_int( num1[j] ) * char_to_int( num2[i] );
			tmp = to_string( carry % 10 ) + tmp;
			carry /= 10;
		}

		if (carry > 0) 
		{ 
			tmp = to_string(carry) + tmp; 
			carry = 0;
		}

		if (tmp.size() != result.size()) 
		{ 
			resize_nums(result, tmp); 
		}

		result = addition(result, tmp);

		tmp.clear();

		++zeros;
	}

	while (result[0] == '0')
	{
		result.erase(0,1);
	}

	return result;
}

void solve()
{
	char sign, digit1, digit2;
	int length;

	cin >> sign >> length;

	string num1 = "", num2 = "";

	f(i, 0, length)
	{
		cin >> digit1 >> digit2;
		
		num1 += digit1;
		num2 += digit2;
	}

	if (sign == '+')
	{
		cout << addition(num1, num2) << endl;
	}
	else
	{
		cout << product(num1, num2) << endl;
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

// Doy mi palabra que he realizado esta actividad con integridad academica.
