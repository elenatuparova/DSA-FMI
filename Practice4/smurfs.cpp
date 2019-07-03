#include <iostream>
#include <string>
using namespace std;

struct Node
{
	char symbol;
	Node* next;
	Node* previous;
};

void addNodeEnd(char data, Node* &head, Node* &tail)
{
	Node* current = new Node;
	current->symbol = data;
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

Node* addNodeStart(char data, Node* &head, Node* &tail)
{
	Node* current = new Node;
	current->symbol = data;
	current->next = head;
	current->previous = NULL;
	if (head == NULL)
	{
		head = current;
		tail = current;
		current = NULL;
	}
	else
	{
		head->previous = current;
		head = current;
	}
	return current;
}

void addNodeBetween(char data, Node* &first, Node* &second)
{
    Node* current = new Node;
    current->symbol = data;
    current->next = second;
    current->previous = first;
    first->next = current;
    second->previous = current;
    first = current;
}

void print(Node* head)
{
	Node* current = new Node;
	current = head;
	while (current != NULL)
	{
		cout << current->symbol;
		current = current->next;
	}
	cout << endl;
}

int main()
{
	int Q = 0;
	std::cin >> Q;
	std::cin.ignore();
	Node** heads;
	heads = new Node*[Q];
	Node** tails;
	tails = new Node*[Q];
	string line = "";
	char prev = '\0';
	Node* temp1 = new Node;
	temp1 = NULL;
	Node* temp2 = new Node;
	temp2 = NULL;
	bool home = 0;
	for (int i = 0; i < Q; i++)
	{
		heads[i] = NULL;
		tails[i] = NULL;
		getline(std::cin, line);
		for (int j = 0; j < line.length(); j++)
		{
			if (line.at(j) == '[')
			{
				home = 1;
				temp2 = heads[i];
			}
			else if (line.at(j) == ']')
			{
				home = 0;
			}
			else
			{
				if (j > 0)
				{
					prev = line.at(j - 1);
				}
				if (prev == '[')
				{
					temp1 = addNodeStart(line.at(j), heads[i], tails[i]);
				}
				else if (home == 1)
				{
					if (temp2 != NULL)
                    {
                        addNodeBetween(line.at(j), temp1, temp2);
                    }
                    else
                    {
                        addNodeEnd(line.at(j), heads[i], tails[i]);
                    }
				}
				else
				{
					addNodeEnd(line.at(j), heads[i], tails[i]);
				}
			}
		}
        home = 0;
		prev = '\0';
	}
	for (int i = 0; i < Q; i++)
	{
		print(heads[i]);
	}
	return 0;
}