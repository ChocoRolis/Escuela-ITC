// Examen Final Problema 1: Redundancia
// Rolando Rivas 594276
// 06/12/2024
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    stack<bool> parentesis;
    int max_redundance = 0;
    int temp_redundance = 0;
    string s;

    cin >> s;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
        {
            parentesis.push(false);
        }
        else if (s[i] == ')')
        {
            if (parentesis.top()) 
            {
                parentesis.pop(); 
            }
            else
            {
                ++temp_redundance;
                max_redundance = max(max_redundance, temp_redundance);
            } 
        }
        else if (s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/' or isalnum(s[i]))
        {
            if (parentesis.empty()) continue;
            parentesis.top() = true;
            temp_redundance = 0;
        }
    }

    if (!max_redundance)
    {
        cout << "OK\n";
    }
    else
    {
        cout << "R " << max_redundance << endl;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}