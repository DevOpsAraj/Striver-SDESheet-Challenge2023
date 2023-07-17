// Code Studio - Floyd Warshall

#include <bits/stdc++.h>
using namespace std;

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<vector<int>> mat(n, vector<int>(n, 1e9));

    for (int i = 0; i < n; i++)
        mat[i][i] = 0;

    for (auto i : edges)
    {
        int u = i[0] - 1, v = i[1] - 1, wt = i[2];
        mat[u][v] = wt;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][k] != 1e9 and mat[k][j] != 1e9)
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }
    return mat[src - 1][dest - 1];
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
    int ans = floydWarshall(n, m, src, dest, edges);
    cout << ans << endl;
    return 0;
}