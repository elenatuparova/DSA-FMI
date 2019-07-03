#include <iostream>
using namespace std;

class Node
{
public:
    long long value;
    Node* left;
    Node* right;
    Node(long long v)
    {
        this->value = v;
        this->left = NULL;
        this->right = NULL;
    }
};

class Tree
{
private:
    Node* root;
    int count;
    
    Node* insertUtil(Node* current, long long value)
    {
        if (current == NULL)
        {
            return new Node(value);
        }
        if (value < current->value)
        {  
            current->left = insertUtil(current->left, value);
        }
        else if (value > current->value)
        {
            current->right = insertUtil(current->right, value);
        }
        return current;
    }
    
    bool isFoundUtil(Node* current, long long value)
    {
        if (current == NULL)
        {
            return 0;
        }
        if (current->value == value)
        {
            return 1;
        }
        if (current->value < value)
        {
            return isFoundUtil(current->right, value);
        }
        return isFoundUtil(current->left, value);
    }

public:
    Tree()
    {
        root = NULL;
        count = 0;
    }
    
    bool isFound(long long value)
    {
        if (root == NULL)
        {
            return false;
        }
        return isFoundUtil(root, value);
    }
    
    void insert(long long value)
    {
        if (isFound(value) == 0)
        {
            root = insertUtil(root, value);
            count++;
        }
    }
    
    int getCount()
    {
        return count;
    }
};

int main()
{
    int N = 0;
    cin >> N;
    long long input = 0;
    cin >> input;
    Tree unique;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        unique.insert(input);
    }
    cout << unique.getCount() << endl;
    return 0;
}