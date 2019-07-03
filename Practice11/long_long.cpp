#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <stack>
#include <climits>
using namespace std;

unordered_map<int, vector<pair<int, int>>> adjList;

void topologicalSort(int current, vector<bool> &visited, stack<int> &st)
{
    visited[current] = true;
    for (auto edge : adjList[current])
    {
        if (!visited[edge.first])
        {
            topologicalSort(edge.first, visited, st);
        }
    }
    st.push(current);
}

void getLongestPath(int s, int t, int n)
{
    stack<int> st;
    vector<long long> distances(n + 1, LLONG_MIN);
    distances[s] = 0;
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            topologicalSort(i, visited, st);
        }
    }
    while(!st.empty())
    {
        int current = st.top();
        st.pop();
        if (distances[current] != LLONG_MIN)
        {
            for (auto edge : adjList[current])
            {
                if (distances[edge.first] < distances[current] + edge.second)
                {
                    distances[edge.first] = distances[current] + edge.second;
                }
            }
        }
    }
    if (distances[t] != LLONG_MIN)
    {
        cout << distances[t];
    }
    else
    {
        cout << -1;
    }
}

int main() {
    int n = 0;
    cin >> n;
    int m = 0;
    cin >> m;
    int s = 0;
    cin >> s;
    int t = 0;
    cin >> t;
    int v1 = 0;
    int v2 = 0;
    int w = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2 >> w;
        adjList[v1].push_back(make_pair(v2, w));
    }
    getLongestPath(s, t, n);
    return 0;
}
