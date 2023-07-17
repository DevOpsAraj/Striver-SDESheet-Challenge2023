// Code Studio - Prims MST

#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{

    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int wt = g[i].second;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);
    vector<int> vis(n + 1, 0);

    pq.push({0, 1});
    dist[1] = 0;
    parent[1] = -1;

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (vis[node])
            continue;

        vis[node] = 1;
        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int wt = it.second;
            if (!vis[adjNode] && dist[adjNode] > wt)
            {
                dist[adjNode] = wt;
                parent[adjNode] = node;
                pq.push({wt, adjNode});
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;
    for (int i = 2; i <= n; i++)
    {
        ans.push_back({{parent[i], i}, dist[i]});
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int, int>, int>> g;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        g.push_back({{u, v}, wt});
    }
    vector<pair<pair<int, int>, int>> ans = calculatePrimsMST(n, m, g);
    for (auto it : ans)
    {
        cout << it.first.first << " " << it.first.second << " " << it.second << endl;
    }
    return 0;
}