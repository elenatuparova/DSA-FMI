#include <iostream>
#include <cstdio>
using namespace std;

struct Node
{
	int value;
	Node* next;
};

void addNode(int data, Node* &head, Node* &tail)
{
	Node* current = new Node;
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

void printMinMaxSum(Node* head, Node* tail)
{
	Node* current = new Node;
	current = head;
	int max = current->value;
	int min = current->value;
	long long sum = 0;
	while (current != NULL)
	{
		if (current->value > max)
		{
			max = current->value;
		}
		if (current->value < min)
		{
			min = current->value;
		}
		sum = sum + current->value;
		current = current->next;
	}
	cout << min << " " << max << " " << sum << endl;
}

int main()
{
	Node* head = NULL;
	Node* tail = NULL;
	int number = 0;
    std::ios::sync_with_stdio(false);
	while (cin >> number)
	{
		addNode(number, head, tail);
	}
	printMinMaxSum(head, tail);
	return 0;
}