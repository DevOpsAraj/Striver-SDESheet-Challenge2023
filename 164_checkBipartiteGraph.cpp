// Code Studio - Check Bipartite Graph

#include <bits/stdc++.h>
using namespace std;

// Check Bipartite Graph using DFS

bool dfs(int node, vector<int> &vis, vector<int> &color, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            color[it] = !color[node];
            if (dfs(it, vis, color, adj))
                return true;
        }
        else if (color[it] == color[node])
            return true;
    }
    return false;
}

bool checkBipartite(int V, vector<int> adj[])
{
    vector<int> vis(V + 1, 0);
    vector<int> color(V + 1, -1);
    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
        {
            color[i] = 0;
            if (dfs(i, vis, color, adj))
                return false;
        }
    }
    return true;
}

// Check Bipartite Graph using BFS

bool checkBipartiteBFS(int V, vector<int> adj[])
{
    vector<int> color(V + 1, -1);
    for (int i = 1; i <= V; i++)
    {
        if (color[i] == -1)
        {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (auto it : adj[node])
                {
                    if (color[it] == -1)
                    {
                        color[it] = !color[node];
                        q.push(it);
                    }
                    else if (color[it] == color[node])
                        return false;
                }
            }
        }
    }
    return true;
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
    if (checkBipartite(n, adj))
        cout << "Graph is Bipartite";
    else
        cout << "Graph is not Bipartite";
    return 0;
}
