// Code Studio - Unique Paths

#include <bits/stdc++.h>
using namespace std;

int path(int m, int n, int row, int col, vector<vector<int>> &dp)
{
    if (row == m - 1 && col == n - 1)
        return 1;
    if (row >= m || col >= n)
        return 0;

    if (dp[row][col] != -1)
        return dp[row][col];

    int right = path(m, n, row, col + 1, dp);
    int down = path(m, n, row + 1, col, dp);

    return dp[row][col] = right + down;
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return path(m, n, 0, 0, dp);
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << uniquePaths(m, n) << endl;
    return 0;
}