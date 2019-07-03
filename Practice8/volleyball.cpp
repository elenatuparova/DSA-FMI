#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node* left;
    Node* right;
    int height;
    Node(int v)
    {
        this->value = v;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }
};

int getNodeHeight(Node* current)
{
    if (current == NULL)
    {
        return 0;
    }
    return current->height;
}

int getBalance(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return getNodeHeight(root->left) - getNodeHeight(root->right);
}

Node* rightRotation(Node* root)
{
    Node* x = root->left;
    Node* y = x->right;
    x->right = root;
    root->left = y;
    root->height = max(getNodeHeight(root->left), getNodeHeight(root->right)) + 1;
    x->height = max(getNodeHeight(x->left), getNodeHeight(x->right)) + 1;
    return x;
}

Node* leftRotation(Node* root)
{
    Node* x = root->right;
    Node* y = x->left;
    x->left = root;
    root->right = y;
    root->height = max(getNodeHeight(root->left), getNodeHeight(root->right)) + 1;
    x->height = max(getNodeHeight(x->left), getNodeHeight(x->right)) + 1;
    return y;
}

Node* insert(Node* root, int value)
{
    if (root == NULL)
    {
        return new Node(value);
    }
    if (value < root->value)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = insert(root->right, value);
    }
    int balance = getBalance(root);
    if (balance > 1 && root->left)
    {
        if (value < root->left->value)
        {
            return rightRotation(root);
        }
        if (value > root->left->value)
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }
    if (balance < -1 && root->right)
    {
        if (value > root->right->value)
        {
            return leftRotation(root);
        }
        if (value < root->right->value)
        {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }
    return root;
}

bool isFound(Node* root, int value)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->value == value)
    {
        return 1;
    }
    if (root->value < value)
    {
        return isFound(root->right, value);
    }
    return isFound(root->left, value);
}


int main()
{
    int first = 0;
    cin >> first;
    Node* team = new Node(first);
    int teamMembers = 1;
    int N = 0;
    cin >> N;
    int bestFriend = 0;
    int candidate = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> bestFriend;
        cin >> candidate;
        if (isFound(team, bestFriend) && !isFound(team, candidate))
        {   
            insert(team, candidate);
            teamMembers++;
        }
    }
    cout << teamMembers << endl;
    return 0;
}