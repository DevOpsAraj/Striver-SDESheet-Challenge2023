// Code Studio - Minimum Path Sum

#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 && n == 0)
        return grid[0][0];
    if (m < 0 || n < 0)
        return 10000;
    if (dp[m][n] != -1)
        return dp[m][n];
    int res = grid[m][n];
    int up = solve(grid, m - 1, n, dp);
    int left = solve(grid, m, n - 1, dp);
    return dp[m][n] = res + min(left, up);
}
int minSumPath(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(grid, m - 1, n - 1, dp);
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (vector<int> &i : grid)
        for (int &j : i)
            cin >> j;
    cout << minSumPath(grid) << endl;
    return 0;
}
