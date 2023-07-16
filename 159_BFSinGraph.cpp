// Code Studio - BFS Traversal

#include <bits/stdc++.h>
using namespace std;

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> adj[vertex];

    for (int i = 0; i < vertex; i++)
        adj[i].push_back(i);

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < vertex; i++)
        sort(adj[i].begin(), adj[i].end());

    vector<int> vis(vertex, 0);
    queue<int> q;
    vector<int> ans;

    for (int i = 0; i < vertex; i++)
    {
        if (vis[i] == 0)
        {
            q.push(i);
            vis[i] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                ans.push_back(node);

                for (auto it : adj[node])
                {
                    if (vis[it] == 0)
                    {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }

    return ans;
}

int main()
{
    int vertex = 5;
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 4}};
    vector<int> ans = BFS(vertex, edges);

    for (auto it : ans)
        cout << it << " ";
    cout << endl;

    return 0;
}