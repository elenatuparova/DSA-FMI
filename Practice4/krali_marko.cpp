#include <iostream>
#include <cstdio>
using namespace std;

struct NodeNumber
{
	int value;
	NodeNumber* next;
};

struct Pair
{
	int first, second;
	Pair* next;
};

void addPair(int first, int second, Pair* &head, Pair* &tail, long long& count)
{
	Pair* current = new Pair;
	current->first = first;
	current->second = second;
	current->next = NULL;
	if (head == NULL)
	{
		head = current;
		tail = current;
		current = NULL;
		count++;
	}
	else
	{
		bool isFound = 0;
		Pair* temp = new Pair;
		temp = head;
		while (temp != NULL)
		{
			if (temp->first == current->first && temp->second == current->second)
			{
				isFound = 1;
				break;
			}
			else if (temp->first == current->second && temp->second == current->first)
			{
				isFound = 1;
				break;
			}
			temp = temp->next;
		}
		if (isFound==0)
		{
			count++;
			tail->next = current;
			tail = current;
		}
	}
}

void addNode(int data, NodeNumber* &head, NodeNumber* &tail)
{
	NodeNumber* current = new NodeNumber;
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

void countValues(int* arr, int P, int* count)
{
	for (int i = 0; i < P; i++)
	{
		if (arr[i] >= 1 && arr[i] <= 1234)
		{
			count[arr[i] - 1]++;
		}
	}
}

int main()
{
	int N = 0;
	cin >> N;
	NodeNumber* head = NULL;
	NodeNumber* tail = NULL;
	int number = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> number;
		addNode(number, head, tail);
	}
	int P = 0;
	cin >> P;
	int* arr;
	arr = new int[P];
	for (int i = 0; i < P; i++)
	{
		cin >> arr[i];
	}
	int count[1234];
	for (int i = 0; i < 1234; i++)
	{
		count[i] = 0;
	}
	countValues(arr, P, count);
	long long pairCount = 0;
	Pair* firstPair = NULL;
	Pair* lastPair = NULL;
	NodeNumber* current = new NodeNumber;
	current = head;
	while (current != NULL)
	{
		if (current->next != NULL && count[current->value - 1] != 0)
		{
			
			if (count[current->next->value - 1] != 0)
			{
				addPair(current->value, current->next->value, firstPair, lastPair, pairCount);
			}
		}
		current = current->next;
	}
	cout << pairCount << endl;
	return 0;
}