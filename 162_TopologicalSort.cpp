// Code Studio - Topological Sort

#include <bits/stdc++.h>
using namespace std;

/********************************************************************************
void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, vis, adj, st);
    }
    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> vis(V + 1, 0);
    stack<int> st;
    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
            dfs(i, vis, adj, st);
    }
    vector<int> topo;
    while (!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
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
    vector<int> res = topoSort(n, adj);
    for (auto it : res)
        cout << it << " ";
    return 0;
}

********************************************************************************/

// Topological Sort using BFS

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
            indegree[it]++;
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    return topo;
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
    vector<int> res = topoSort(n, adj);
    for (auto it : res)
        cout << it << " ";
    return 0;
}