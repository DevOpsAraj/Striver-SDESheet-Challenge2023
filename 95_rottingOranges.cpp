// Code Studio - Rotting Oranges

#include <bits/stdc++.h>
using namespace std;

int minTimeToRot(vector<vector<int>> &grid, int n, int m)
{
    queue<pair<pair<int, int>, int>> q;
    int visited[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                visited[i][j] = 2;
            }
            else
            {
                visited[i][j] = 0;
            }
        }
    }

    int tm = 0;
    int dRow[] = {-1, 0, 1, 0};
    int dCol[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;

        tm = max(tm, t);
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nRow = r + dRow[i];
            int nCol = c + dCol[i];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && visited[nRow][nCol] != 2 && grid[nRow][nCol] == 1)
            {
                q.push({{nRow, nCol}, tm + 1});
                visited[nRow][nCol] = 2;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] != 2 && grid[i][j] == 1)
                return -1;
        }
    }

    return tm;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << minTimeToRot(grid, n, m) << endl;
    return 0;
}