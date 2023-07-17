// Code Studio - 0 1 Knapsack

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int solveMem(int weight[], int value[], int index, int capacity, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            if (weight[0] <= capacity)
                return value[0];
            else
                return 0;
        }

        if (dp[index][capacity] != -1)
            return dp[index][capacity];

        int include = 0;
        if (weight[index] <= capacity)
        {
            include = solveMem(weight, value, index - 1, capacity - weight[index], dp) + value[index];
        }
        int exclude = solveMem(weight, value, index - 1, capacity, dp);

        dp[index][capacity] = max(include, exclude);

        return dp[index][capacity];
    }

    int solveTab(int weight[], int value[], int n, int capacity)
    {

        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

        for (int w = weight[0]; w <= capacity; w++)
        {
            if (weight[0] <= capacity)
                dp[0][w] = value[0];
            else
                dp[0][w] = 0;
        }

        for (int index = 1; index < n; index++)
        {
            for (int w = 0; w <= capacity; w++)
            {
                int incl = 0;
                if (weight[index] <= w)
                    incl = value[index] + dp[index - 1][w - weight[index]];
                int excl = dp[index - 1][w];

                dp[index][w] = max(incl, excl);
            }
        }
        return dp[n - 1][capacity];
    }

    int solveSpaceOpt1(int weight[], int value[], int n, int capacity)
    {
        vector<int> prev(capacity + 1, 0);
        vector<int> curr(capacity + 1, 0);

        for (int w = weight[0]; w <= capacity; w++)
        {
            if (weight[0] <= capacity)
                prev[w] = value[0];
            else
                prev[w] = 0;
        }

        for (int index = 1; index < n; index++)
        {
            for (int w = 0; w <= capacity; w++)
            {
                int incl = 0;
                if (weight[index] <= w)
                    incl = value[index] + prev[w - weight[index]];
                int excl = prev[w];
                curr[w] = max(incl, excl);
            }
            prev = curr;
        }
        return prev[capacity];
    }

    int solveSpaceOpt2(int weight[], int value[], int n, int capacity)
    {
        vector<int> curr(capacity + 1, 0);

        for (int w = weight[0]; w <= capacity; w++)
        {
            if (weight[0] <= capacity)
                curr[w] = value[0];
            else
                curr[w] = 0;
        }

        for (int index = 1; index < n; index++)
        {
            for (int w = capacity; w >= 0; w--)
            {
                int incl = 0;
                if (weight[index] <= w)
                    incl = value[index] + curr[w - weight[index]];
                int excl = curr[w];
                curr[w] = max(incl, excl);
            }
        }
        return curr[capacity];
    }

    int knapSack(int W, int wt[], int val[], int n)
    {
        /*
        Memoization
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        return solveMem(wt, val, n -1, W, dp);

        */

        // Tabulation
        // return solveTab(wt, val, n, W);

        // Space Optimization
        // return solveSpaceOpt1(wt, val, n, W);

        // Space Optimization
        return solveSpaceOpt2(wt, val, n, W);
    }
};

int main()
{
    int n, W;
    cin >> n >> W;

    int wt[n];
    int val[n];

    for (int i = 0; i < n; i++)
        cin >> wt[i];

    for (int i = 0; i < n; i++)
        cin >> val[i];
        
    Solution obj;
    cout << obj.knapSack(W, wt, val, n) << endl;
    return 0;
}