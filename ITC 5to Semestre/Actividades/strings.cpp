#include <bits/stdc++.h>
using namespace std;

// INCOMPLETO

int says_icpc = 0;
int cant_nums = 0;
int cant_vocs = 0;
int cant_cons = 0;

string min_word = "■■■■■■■■";
string max_word = "       ";
string phrase = "";

bool is_voc(char chr)
{
	char vocals[] = "aeiou";

	for (int i = 0; i < 5; ++i)
	{
		if (chr == vocals[i]) { return true; }
	}
	
	return false;
}

bool is_con(char chr)
{
	char vocals[] = "bcdfghjklmnpqrstvwxyz";

	for (int i = 0; i < 21; ++i)
	{
		if (chr == vocals[i]) { return true; }
	}
	
	return false;
}

bool is_num(char chr)
{
	if (chr >= '0' && chr <= '9')
	{
		return true;
	}

	return false;
}

void read_words(string line)
{
	istringstream iss(line);
	string word;

	while (iss >> word)
	{
		if (word == "icpc") { says_icpc = 1; }

		min_word = min(word, min_word);
		max_word = max(word, max_word);

		for (int i = 0; i < word.size(); ++i)
		{
			if 	(is_voc( word[i] )) { ++cant_vocs; }
			else if (is_con( word[i] )) { ++cant_cons; }
			else if (is_num( word[i] )) { ++cant_nums; }
		}
	}

}

void words_to_lower( string line )
{
	for (int i = 0; i < line.size(); ++i)
	{
		line[i] = tolower( line[i] );
	}
	
	phrase += line;
}

void read_line(string line)
{
	while ( getline(cin, line)  &&  line != "......." )
	{
		if (line.back() == '-') { line.pop_back(); }
		else { line += " "; }

		read_words( line );
		words_to_lower( line );
	}

	getline(cin, line);

}

int main()
{
	string line;

	read_line(line);

	cout << phrase << endl;
	cout << cant_nums << " " << cant_vocs << " " << cant_cons << endl;
	cout << min_word << " " << max_word << endl;
	cout << says_icpc << endl;

	last_line();
}
