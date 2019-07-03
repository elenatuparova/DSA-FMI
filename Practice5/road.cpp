#include <iostream>
#include <string>
using namespace std;

struct Stone
{
	long long value;
	Stone* next;
	Stone* previous;
};

void white(long long value, Stone* &first, Stone* &last)
{
	Stone* current = new Stone;
	current->value = value;
	current->next = NULL;
	current->previous = last;
	if (first == NULL)
	{
		first = current;
		last = current;
		current = NULL;
	}
	else
	{
		last->next = current;
		last = current;
	}
}

void print(Stone* first)
{
	Stone* current = new Stone;
	current = first;
	while (current != NULL)
	{
		cout << current->value << " ";
		current = current->next;
	}
	cout << endl;
}

void green(int K, int currentStones, Stone* &first, Stone*& last)
{
	Stone* current = new Stone;
	current->value = 0;
	current->next = NULL;
	Stone* temp = new Stone;
	temp = last;
	if (K >= currentStones)
	{
		while (temp != NULL)
		{
			current->value += temp->value;
			temp = temp->previous;
		}
		first = current;
		last = current;
		current = NULL;
	}
	else
	{
		for (int j = K; j > 0; j--)
		{
			current->value += temp->value;
			temp = temp->previous;
		}
		last = temp;
		current->previous = last;
		last->next = current;
		last = current;
	}
}

void blue(int K, int currentStones, Stone* &first, Stone*& last)
{
	Stone* current = new Stone;
	current->value = last->value;
	current->next = NULL;
	Stone* temp = new Stone;
	temp = last;
	if (K >= currentStones)
	{
		while (temp != NULL)
		{
			if (temp->value > current->value)
			{
				current->value = temp->value;
			}
			temp = temp->previous;
		}
		first = current;
		last = current;
		current = NULL;
	}
	else
	{
		for (int j = K; j > 0; j--)
		{
			if (temp->value > current->value)
			{
				current->value = temp->value;
			}
			temp = temp->previous;
		}
		last = temp;
		current->previous = last;
		last->next = current;
		last = current;
	}
}


int main()
{
	int N = 0;
	cin >> N;
	cin.ignore();
	string input = "";
	long long currentValue = 0;
	Stone* first = new Stone;
	first = NULL;
	Stone* last = new Stone;
	last = NULL;
	for (int i = 0; i < N; i++)
	{
		getline(cin, input);
		if (input.at(0) == 'w')
		{
			for (int i = 6; i < input.length(); i++)
			{
				currentValue = currentValue * 10 + (int(input.at(i)) - 48);
			}
			white(currentValue, first, last);
		}
		else if (input.at(0) == 'b')
		{
			for (int i = 5; i < input.length(); i++)
			{
				currentValue = currentValue * 10 + (int(input.at(i)) - 48);
			}

			blue(currentValue, i, first, last);
		}
		else if (input.at(0) == 'g')
		{
			for (int i = 6; i < input.length(); i++)
			{
				currentValue = currentValue * 10 + (int(input.at(i)) - 48);
			}
			green(currentValue, i, first, last);
		}
		currentValue = 0;
	}
	print(first);
	return 0;
}