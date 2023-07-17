// Code Studio - Bellman Ford

#include <bits/stdc++.h>
using namespace std;

int bellmanFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{

    vector<int> dist(n + 1, 1e9);
    dist[src] = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e9 && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }
    return dist[dest];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; ++i)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }
    int src, dest;
    cin >> src >> dest;
    int ans = bellmanFord(n, m, src, dest, edges);
    cout << ans << endl;
    return 0;
}