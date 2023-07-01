// Code Studio - Return Subsets Sum to K

#include <bits/stdc++.h>
using namespace std;

void solve(int index, int sum, vector<int> &arr, int n, int k,
           vector<vector<int>> &ans, vector<int> temp)
{
    if (index == n)
    {
        if (sum == k)
            ans.push_back(temp);
        return;
    }

    // Not pick
    solve(index + 1, sum, arr, n, k, ans, temp);

    // Pick
    temp.push_back(arr[index]);
    solve(index + 1, sum + arr[index], arr, n, k, ans, temp);
    temp.pop_back();
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> temp;

    solve(0, 0, arr, n, k, ans, temp);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;

    vector<vector<int>> ans = findSubsetsThatSumToK(arr, n, k);

    for (auto it : ans)
    {
        for (int i = 0; i < it.size(); i++)
        {
            cout << it[i] << " ";
        }
        cout << endl;
    }

    return 0;
}