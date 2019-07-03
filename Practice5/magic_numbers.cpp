#include <iostream>
using namespace std;

struct Number
{
	long long value;
	Number* next;
};

void addBack(long long data, Number* &head, Number* &tail)
{
	Number* current = new Number;
	current->value = data;
	current->next = NULL;
	if (head == NULL)
	{
		head = current;
		tail = current;
		current = NULL;
	}
	else
	{
		tail->next = current;
		tail = current;
	}
}

void removeFront(Number* &head, Number* &tail)
{
	if (head == tail)
	{
		head = NULL;
		tail = NULL;
	}
	else
	{
		head = head->next;
	}
}

int getMinStart(Number** heads)
{
	int minIndex = 0;
	for (int i = 1; i < 9; i++)
	{
		if (heads[i]->value < heads[minIndex]->value)
		{
			minIndex = i;
		}
	}
	return minIndex;
}

int main()
{
	long long N = 0;
	cin >> N;
	Number** heads;
	heads = new Number*[9];
	Number ** tails;
	tails = new Number*[9];
	for (int i = 0; i < 9; i++)
	{
		heads[i] = NULL;
		tails[i] = NULL;
		addBack(i + 1, heads[i], tails[i]);
	}
	int minIndex = getMinStart(heads);
	long long currentMin = heads[minIndex]->value;
	long long toAdd = 0;
	while (currentMin <= N)
	{
		cout << currentMin << " ";
		if (currentMin % 10 - 2 >= 0)
		{
			toAdd = currentMin * 10 + currentMin % 10 - 2;
			addBack(toAdd, heads[minIndex], tails[minIndex]);
		}
		if (currentMin % 10 + 2 <= 9)
		{
			toAdd = currentMin * 10 + currentMin % 10 + 2;
			addBack(toAdd, heads[minIndex], tails[minIndex]);
		}
		removeFront(heads[minIndex], tails[minIndex]);
		minIndex = getMinStart(heads);
		currentMin = heads[minIndex]->value;
	}
	return 0;
}