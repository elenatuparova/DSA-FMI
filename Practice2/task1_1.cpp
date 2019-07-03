#include <iostream>
#include <string>
using namespace std;

bool compareConcat(string first, string second)
{
	if (first + second > second + first)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void sort(string* values, int length)
{
	bool swapped = false;
	for (int i = 0; i < length; i++)
	{
		swapped = false;
		for (int j = 0; j < length - i - 1; j++)
		{
			if (!compareConcat(values[j], values[j + 1]))
			{
				swap(values[j], values[j + 1]);
				swapped = true;
			}
		}
		if (!swapped)
		{
			break;
		}
	}
}

int main()
{
	int n = 0;
	cin >> n;
	unsigned int* numbers;
	numbers = new unsigned int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}

	string* password;
	password = new string[n];
	for (int i = 0; i < n; i++)
	{
		password[i] = to_string(numbers[i]);
	}
	delete[] numbers;

	sort(password, n);
    
    if (password[0] == "0")
    {
        cout << 0;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << password[i];
        }
    }
	cout << endl;
	delete[] password;
	return 0;
}