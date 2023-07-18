// Code Studio - Palindrome Partitioning ll

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j)
{
    while (i <= j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int palindromePartitioning(string str)
{
    int n = str.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (isPalindrome(str, i, j))
                dp[i][j] = 0;
            else
            {
                int mini = INT_MAX;

                for (int k = i; k <= j - 1; k++)
                {
                    int left = dp[i][k];
                    int right = dp[k + 1][j];
                    mini = min(mini, left + right + 1);
                }
                dp[i][j] = mini;
            }
        }
    }
    return dp[0][n - 1];
}

int main()
{
    string s;
    cin >> s;
    cout << palindromePartitioning(s) << endl;
    return 0;
}