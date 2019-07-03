#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    double value;
    Node* left;
    Node* right;

    Node(int val)
    {
        value = val;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, double value)
{
    if (root == NULL)
    {
        return new Node(value);
    }
    Node* current = NULL;
    if (value < root->value)
    {
        current = insert(root->left, value);
        root->left = current;
    }
    else
    {
        current = insert(root->right, value);
        root->right = current;
    }
    return root;
}

void countLevels(Node* root, vector<double> & levelSum, vector<int> &levelCount)
{
    if (root == NULL)
    {
        return;
    }
    levelCount.push_back(1);
    levelSum.push_back(root->value);
    queue<Node*> q;
    q.push(root);
    int count = 0;
    double sum = 0;
    while (q.size())
    {
        if (count)
        {
            levelCount.push_back(count);
            levelSum.push_back(sum);
        }
        count = 0;
        sum = 0;
        int size = q.size();
        for (int i = 0; i<size; i++)
        {
            Node* p = q.front();
            if (p->left != NULL)
            {
                q.push(p->left);
                count++;
                sum += p->left->value;
            }
            if (p->right != NULL)
            {
                q.push(p->right);
                count++;
                sum += p->right->value;
            }
            q.pop();
        }
    }
}

int main()
{
    int N = 0;
    cin >> N;
    double input = 0;
    cin >> input;
    Node* root = NULL;
    root = insert(root, input);
    for (int i = 1; i < N; i++)
    {
        cin >> input;
        insert(root, input);
    }
    vector<double> levelSum;
    vector<int> levelCount;
    countLevels(root, levelSum, levelCount);
    cout << fixed << setprecision(2);
    for (int i = 0; i < levelSum.size(); i++)
    {
        cout << levelSum[i] / levelCount[i] << endl;
    }
    return 0;
}