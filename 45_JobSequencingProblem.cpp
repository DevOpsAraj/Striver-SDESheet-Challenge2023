// Code Studio - Job Sequencing Problem

#include <bits/stdc++.h>
using namespace std;

bool comparator(vector<int> j1, vector<int> j2)
{
    return j1[1] > j2[1] || (j1[1] == j2[1] && j1[0] >= j2[0]);
}

int jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), comparator);
    int maxDeadline = -1, profit = 0;
    for (int i = 0; i < jobs.size(); i++)
    {
        maxDeadline = max(maxDeadline, jobs[i][0]);
    }
    vector<int> dp(maxDeadline + 1, -1);
    for (int i = 0; i < jobs.size(); i++)
    {
        int d = jobs[i][0];
        for (int j = d; j > 0; j--)
        {
            if (dp[j] == -1)
            {
                dp[j] = jobs[i][1];
                break;
            }
        }
    }
    for (int i = 1; i <= maxDeadline; i++)
    {
        if (dp[i] != -1)
        {
            profit += dp[i];
        }
    }
    return profit;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> jobs(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> jobs[i][0] >> jobs[i][1];

    cout << jobScheduling(jobs) << endl;
    return 0;
}