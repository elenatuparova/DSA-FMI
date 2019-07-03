#include <iostream>
using namespace std;

struct Ball
{
    int mass;
    Ball* next;
};

void addBall(int m, Ball* &head, Ball* &tail)
{
    Ball* current = new Ball;
    current->mass = m;
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

void removeLastBall(Ball* &head, Ball* &tail)
{
    Ball* previous = new Ball;
    Ball* current = new Ball;
    if (head != NULL)
    {
        current = head;
        while (current != tail)
        {
            previous = current;
            current = current->next;
        }
        if (previous == NULL)
        {
            head = NULL;
        }
        else
        {
            previous->next = NULL;
        }
        tail = previous;
    }
}


int main()
{
    int N = 0;
    cin >> N;
    Ball** snowmenHeads;
    snowmenHeads = new Ball*[N + 1];
    Ball** snowmenTails;
    snowmenTails = new Ball*[N + 1];
    int p = 0;
    int m = 0;
    long long sum = 0;
    int* masses;
    masses = new int[N];
    for (int i = 0; i < N; i++)
    {
        masses[i] = 0;
    }
    snowmenHeads[0] = NULL;
    snowmenTails[0] = NULL;
    for (int i = 1; i <= N; i++)
    {
        cin >> p;
        cin >> m;
        snowmenHeads[i] = snowmenHeads[p];
        snowmenTails[i] = snowmenTails[p];
        if (m != 0)
        {
            addBall(m, snowmenHeads[i], snowmenTails[i]);
            masses[i] = masses[p] + m;
            sum = sum + masses[i];
        }
        else
        {
            masses[i] = masses[p] - snowmenTails[i]->mass;
            sum = sum + masses[i];
            removeLastBall(snowmenHeads[i], snowmenTails[i]);
        }
    }
    cout << sum << endl;
    return 0;
}