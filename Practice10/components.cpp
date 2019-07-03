#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, vector<int>> graph;

int explore(int v, vector<bool> &visited)
{
    if (visited[v] || graph[v].size() == 0)
    {
        return 0;
    }
    visited[v] = true;
    int count = 1;
    for (int i = 0; i < graph[v].size(); i++)
    {
        count += explore(graph[v][i], visited);
    }
    return count;
}

int main()
{
    int n = 0;
    cin >> n;
    
    int g = 0;
    int b = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> g;
        cin >> b;
        graph[g].push_back(b);
        graph[b].push_back(g);
    }
    int count = 0;
    int min = 2 * n;
    int max = -1;
    vector<bool> visited(2 * n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        count = explore(i, visited);
        if (count == 0)
        {
            continue;
        }
        if (count > max)
        {
            max = count;
        }
        if (count < min)
        {
            min = count;
        }
    }
    cout << min << " " << max << endl;
    return 0;
}