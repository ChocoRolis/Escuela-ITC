#include <iostream>
#include <vector>
#include <cmath>	
using namespace std;

int countPrimes(int n);
bool is_prime(int num, vector<int> &Primes); 

int main()
{
	int a;
	cin >> a;
	cout << countPrimes(a) << endl;
	int
}

int countPrimes(int n) 
{
        if (n == 0 || n == 1 || n == 2)
        {       
		return 0;   
        }

        vector<int> primes = {2};
        int cant = 1;

        for (int i = 3; i < n; i = i+2)
        {
		if (is_prime(i, primes)) cant++;
        }

        return cant;
}

bool is_prime(int num, vector<int> &Primes)
{
	for (int i = 0; i < (int) Primes.size(); i++)
    	{
            	if (num % Primes[i] == 0)
            	{
                	return false;
            	}
		if (Primes[i] > sqrt(num)) break;
        }
        Primes.push_back(num);
        return true;
}

