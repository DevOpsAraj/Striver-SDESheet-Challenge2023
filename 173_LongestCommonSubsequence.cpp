// Code Studio - Longest Common Subsequence

#include <bits/stdc++.h>
using namespace std;

int lcs(string s, string t)
{
    int m = s.size(), n = t.size();
    int dp[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i < n + 1; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string s, t;
    cin >> s >> t;

    cout << lcs(s, t) << endl;
    return 0;
}