#include <iostream>
#include <vector>
using namespace std;

const int MAX_SIZE = 100001;

int getMaxPaths(int current, int cafes, int N, int M, bool* isStarbucks, bool* &isVisited, vector<int>* neighbourhood)
{
    if (isStarbucks[current])
    {
        cafes++;
    }
    else
    {
        cafes = 0;
    }
    if (cafes > M || isVisited[current])
    {
        return 0;
    }
    isVisited[current] = 1;
    if (current > 1 && neighbourhood[current].size() == 1)
    {
        return 1;
    }
    int numberPaths = 0;
    for (int i = 0; i < neighbourhood[current].size(); i++)
    {
        numberPaths += getMaxPaths(neighbourhood[current][i], cafes, N, M, isStarbucks, isVisited, neighbourhood);
    }
    return numberPaths;
}

int main()
{
    int N = 0;
    cin >> N;
    int M = 0;
    cin >> M;
    vector<int> neighbourhood[MAX_SIZE];
    bool* isStarbucks = new bool[N+1];
    for (int i = 1; i <= N; i++)
    {
        cin >> isStarbucks[i];
    }
    int start = 0;
    int end = 0;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> start;
        cin >> end;
        neighbourhood[start].push_back(end);
        neighbourhood[end].push_back(start);
    }
    bool* isVisited = new bool[N+1];
    for (int i = 0; i < N + 1; i++)
    {
        isVisited[i] = 0;
    }
    cout << getMaxPaths(1, 0, N, M, isStarbucks, isVisited, neighbourhood);
    return 0;
}
