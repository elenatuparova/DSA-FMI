#include <iostream>
using namespace std;

struct Knight
{
	int number;
	Knight* next;
};

void addKnight(int num, Knight* &first, Knight* &last)
{
	Knight* current = new Knight;
	current->number = num;
	current->next = first;
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

void removeNext(Knight* &current, Knight* &first)
{
	if (current->next == first)
	{
		first = first->next;
	}
	current->next = current->next->next;
	current = current->next;
}

int main()
{
	int N = 0;
	cin >> N;
	Knight* first = new Knight;
	first = NULL;
	Knight* last = new Knight;
	last = NULL;
	for (int i = 1; i <= N; i = i+2)
	{
		addKnight(i, first, last);
	}
	int remaining = N;
	Knight* current = new Knight;
	current = first;
	while (remaining > 1)
	{
		removeNext(current, first);
		remaining--;
	}
	cout << first->number << endl;
	return 0;
}