// Code Studio - Flood Fill Algorithm

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    int inClr = image[x][y];

    int n = image.size();
    int m = image[0].size();

    vector<vector<int>> ans = image;

    vector<vector<int>> vis(n, vector<int>(m, 0));
    vis[x][y] = 1;

    queue<pair<int, int>> q;
    q.push({x, y});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        int row = it.first;
        int col = it.second;

        ans[row][col] = newColor;

        int delRow[] = {0, 1, 0, -1};
        int delCol[] = {1, 0, -1, 0};

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if (newRow >= 0 && newRow < n && newColor >= 0 && newCol < m &&
                !vis[newRow][newCol] && image[newRow][newCol] == inClr)
            {
                q.push({newRow, newCol});
                vis[newRow][newCol] = 1;
            }
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> image(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> image[i][j];

    int x, y, newColor;
    cin >> x >> y >> newColor;

    vector<vector<int>> ans = floodFill(image, x, y, newColor);

    for (auto it : ans)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}