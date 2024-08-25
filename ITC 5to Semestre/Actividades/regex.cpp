#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
	string line;
	regex pattern(R"");

	cin >> line;
	
	if (regex_match(line, pattern))
	{
		cout << "Valid\n";
	}
	else
	{
		cout << "Invalid\n";
	}
}
