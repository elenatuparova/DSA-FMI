#include <iostream>
#include <string>
using namespace std;

string sortString(string s)
{
	for (int i = 1; i < s.length(); i++)
	{
		int j = i;
		while (j > 0 && int(s.at(j - 1)) > int(s.at(j)))
		{
			swap(s.at(j - 1), s.at(j));
			j--;
		}
	}
	return s;
}

int main()
{
	string a, b;
	cin >> a;
	cin >> b;
	for (int i = 0; i < a.length(); i++)
	{
		tolower(a.at(i));
	}
	for (int i = 0; i < b.length(); i++)
	{
		tolower(b.at(i));
	}
	a = sortString(a);
	b = sortString(b);
	string substring;
	if (a.length()>b.length())
	{
		swap(a, b);
	}
	int lastFoundIndex = -1;
	for (int i = 0; i < a.length(); i++)
	{
		for (int j = lastFoundIndex + 1; j < b.length(); j++)
		{
			if (a.at(i) == b.at(j))
			{
				substring += a.at(i);
				lastFoundIndex = j;
				break;
			}
		}
	}
	cout << substring << endl;
	return 0;
}