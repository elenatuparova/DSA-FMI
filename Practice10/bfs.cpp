#include <vector>
#include <queue>
#include <list>
#include <iostream>
using namespace std;

vector<int> bfs(int n, int m, vector<list<int>> edges, int s)
{
    vector<bool> visited(n+1);
    for (int i = 0; i <= n; i++)
    {
        visited[i] = false;
    }
    vector<int> distance(n+1);
    for (int i = 0; i <= n; i++)
    {
        distance[i] = 0;
    }
    queue<int> q;
    q.push(s);
    visited[s] = true;
    int current = s;
    list<int>::iterator it;
    while(!q.empty())
    {
        current = q.front();
        q.pop();
        for (it = edges[current].begin(); it != edges[current].end(); ++it)
        {
            if(!visited[*it])
            {
                distance[*it] += distance[current] + 6;
                visited[*it] = true;
                q.push(*it);
            }
        }
    }
    distance.erase(distance.begin() + s);
    distance.erase(distance.begin());
    return distance;
}

int main() 
{
    int q = 0;
    cin >> q;
    int n = 0;
    int m = 0;
    for (int i = 0; i < q; i++)
    {
        cin >> n;
        cin >> m;
        vector<list<int>> edges(n + 1);
        int v1 = 0;
        int v2 = 0;
        for (int j = 0; j < m; j++)
        {
            cin >> v1;
            cin >> v2;
            edges[v1].push_back(v2);
            edges[v2].push_front(v1);
        }
        int start = 0;
        cin >> start;
        vector<int> distance = bfs(n, m, edges, start);
        for (int j = 0; j < distance.size(); j++)
        {
            if (distance[j] == 0)
            {
                cout << "-1 ";
            }
            else
            {
                cout << distance[j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}