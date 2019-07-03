#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

struct Node
{
	int value;
	Node* next;
    Node* previous;
};

void addNode(int data, Node* &head, Node* &tail)
{
	Node* current = new Node;
	current->value = data;
	current->next = NULL;
    current->previous = tail;
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

void removeNode(Node* &head, Node* &tail)
{
    if(head!=NULL)
    {
        if (tail->previous == NULL)
        {
            head = NULL;
        }
        else
        {
            tail = tail->previous;
            tail->next = NULL;
        }
    }
}

void shuffle(Node* &head, Node* &tail, Node* &middle, int count)
{
    tail->next = head;
    head->previous = tail;
    Node* temp = new Node;
    temp = NULL;
    temp = tail;
    head = middle->next;
    head->previous = NULL;
    tail = middle;
    tail->next = NULL;
    if (count % 2 == 0)
    {
        middle = temp;
    }
    else
    {
        middle = temp->previous;
    }
    temp = NULL;
}

void print(Node* head)
{
	Node* current = new Node;
	current = head;
	while (current != NULL)
	{
		cout << current->value << " ";
		current = current->next;
	}
    cout<<endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int N = 0;
    cin>>N;
    cin.ignore(1, '\n');
	string query = "";
	Node* head = NULL;
	Node* tail = NULL;
    Node* middle = NULL;
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		getline(cin, query);
		if (query.at(0) == 'a')
		{
			int num = 0;
			for (int i = 4; i < query.length(); i++)
			{
				num = num * 10 + (int(query.at(i)) - 48);
			}
			addNode(num, head, tail);
            count++;
            if (count == 1 || count == 2 || count == 3)
            {
                middle = head;
            }
            else if (count % 2 == 0)
            {
                middle = middle->next;
            }
		}
		else if (query.at(0) == 'g')
		{
			removeNode(head, tail);
            count--;
            if (count == 1 || count == 2 || count == 3)
            {
                middle = head;
            }
            else if (count % 2 == 1)
            {
                middle = middle->previous;
            }
		}
		else if (query.at(0) == 'm')
		{
			shuffle(head, tail, middle, count);
		}
	}
    cout<<count<<endl;
    if (count!=0)
    {
        print(head);
    }
	return 0;
}