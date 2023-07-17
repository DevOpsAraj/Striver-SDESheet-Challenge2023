// Code Studio - Detect Cycle In A Directed Graph

#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> &vis, vector<int> &dfsVis, vector<int> adj[])
{
    vis[node] = 1;
    dfsVis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(it, vis, dfsVis, adj))
                return true;
        }
        else if (dfsVis[it])
            return true;
    }
    dfsVis[node] = 0;
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<int> vis(V + 1, 0);
    vector<int> dfsVis(V + 1, 0);
    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, vis, dfsVis, adj))
                return true;
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v, adj[u].push_back(v);
    }
    if (isCycle(n, adj))
        cout << "Cycle is present";
    else
        cout << "Cycle is not present";
    return 0;
}
