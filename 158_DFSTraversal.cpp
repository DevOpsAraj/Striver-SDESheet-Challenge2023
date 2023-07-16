// Code Studio - DFS Traversal

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int node, int vis[], vector<int> &v)
{
    v.push_back(node);
    vis[node] = 1;

    for (auto &it : adj[node])
    {
        if (vis[it] != 1)
            dfs(adj, it, vis, v);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<int> adj[V];
    for (auto &it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    int vis[V] = {0};
    vector<vector<int>> ans;

    for (int i = 0; i < V; i++)
    {
        if (vis[i] != 1)
        {
            vector<int> v;
            dfs(adj, i, vis, v);
            ans.push_back(v);
        }
    }
    return ans;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> edges(E);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    vector<vector<int>> ans = depthFirstSearch(V, E, edges);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size() - 1; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << ans[i][ans[i].size() - 1];
        if (i != ans.size() - 1)
            cout << endl;
    }
    return 0;
}