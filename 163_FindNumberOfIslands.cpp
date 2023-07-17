// Code Studio - Find Number Of Islands

#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, int **arr, vector<vector<int>> &vis, int n, int m)
{
    vis[row][col] = 1;
    for (int i = -1; i <= +1; i++)
    {
        for (int j = -1; j <= +1; j++)
        {

            int nRow = row + i;
            int nCol = col + j;

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && arr[nRow][nCol] == 1)
            {
                dfs(nRow, nCol, arr, vis, n, m);
            }
        }
    }
}

int getTotalIslands(int **arr, int n, int m)
{
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && arr[i][j] == 1)
            {
                dfs(i, j, arr, vis, n, m);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }
    cout << getTotalIslands(arr, n, m);
    return 0;
}