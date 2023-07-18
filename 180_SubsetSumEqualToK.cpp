// Code Studio - Subset Sum Equal To K

#include <bits/stdc++.h>
using namespace std;

bool solve(int ind, int n, vector<int> &arr, int sum, vector<vector<int>> &dp)
{
    if (sum == 0)
        return true;

    if (ind >= n)
        return false;

    if (sum < 0)
        return false;

    if (dp[ind][sum] != -1)
        return dp[ind][sum];

    bool take = solve(ind + 1, n, arr, sum - arr[ind], dp);
    bool notTake = solve(ind + 1, n, arr, sum, dp);

    return dp[ind][sum] = (take or notTake);
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(0, n, arr, k, dp);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << subsetSumToK(n, k, arr) << endl;
    return 0;
}