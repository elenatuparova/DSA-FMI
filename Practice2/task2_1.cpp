#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	cin >> input;
	int letters[26];
	for (int i = 0; i < 26; i++)
	{
		letters[i] = 0;
	}
	for (int i = 0; i < input.length(); i++)
	{
		letters[input.at(i) - 97]++;
	}
	int max = letters[0];
	for (int i = 0; i < 26; i++)
	{
		if (letters[i] >= max)
		{
			max = letters[i];
		}
	}
	if (max*2>input.length()+1)
	{
		cout << "No" << endl;
	}
	else
	{
		cout << "Yes" << endl;
	}

	return 0;
}