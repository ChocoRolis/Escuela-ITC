#include <iostream>
#include <string>

using namespace std;

string unDigito(string n)
{
    if (n.length() == 1) // caso base que acaba cuando solo hay un digito
    {
        return n;
    }
    else 
    {

        return unDigito(to_string(stoll(n.substr(0, n.size() / 2)) + stoll(n.substr(n.size() / 2))));
    }
}
int main()
{
    string n = "123456789012345678901234567890"; 

    n = unDigito(n);

    cout << n << endl;
}
