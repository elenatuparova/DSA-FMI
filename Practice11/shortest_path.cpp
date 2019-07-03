#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<vector<pair<int, int>>> adjList;

void getShortestPaths(int start, int n, vector<vector<pair<int, int>>> adjList)
{
    vector<long long> distances(n + 1, LLONG_MAX);
    vector<bool> marked(n + 1, false);
    distances[start] = 0;
    int current = -1;
    for (int j = 1; j <= n; j++)
    {
        current = -1;
        for (int k = 1; k <= n; k++)
        {
            if (!marked[k] && (current == -1 || distances[k] < distances[current]))
            {
                current = k;
            }
        }
        if (distances[current] == LLONG_MAX)
        {
            break;
        }
        marked[current] = true;
        for (auto edge : adjList[current])
        {
            int to = edge.first;
            int length = edge.second;
            if (distances[current] + length < distances[to])
            {
                distances[to] = distances[current] + length;
            }
        }
    }
    for (int j = 1; j <= n; j++)
    {
        if (j == start)
        {
            continue;
        }
        if (distances[j] == LLONG_MAX)
        {
            cout << "-1 ";
        }
        else
        {
            cout << distances[j] << " ";
        }
    }
    cout << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n = 0;
        cin >> n;
        int m = 0;
        cin >> m;
        int from = 0;
        int to = 0;
        int weight = 0;
        vector<vector<pair<int, int>>> adjList(n + 1);
        for (int j = 0; j < m; j++)
        {
            cin >> from >> to >> weight;
            adjList[from].push_back(make_pair(to, weight));
            adjList[to].push_back(make_pair(from, weight));
        }
        int start = 0;
        cin >> start;
        getShortestPaths(start, n, adjList);
    }
    return 0;
}