// Code Studio - Cut Logs

#include <bits/stdc++.h>
using namespace std;

int solveMem(int n, int k, vector<vector<int>> &dp)
{
    if (n <= 0 || k <= 0)
        return 0;

    if (k == 1)
        return n;

    if (n == 1)
        return 1;

    if (dp[n][k] != -1)
        return dp[n][k];

    int ans = INT_MAX;
    int low = 1, high = n;
    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        int broken = solveMem(mid - 1, k - 1, dp);
        int notBroken = solveMem(n - mid, k, dp);
        int result = max(notBroken, broken);
        ans = min(result + 1, ans);

        if (broken < notBroken)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return dp[n][k] = ans;
}

int cutLogs(int k, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return solveMem(n, k, dp);
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << cutLogs(k, n) << endl;
    return 0;
}
