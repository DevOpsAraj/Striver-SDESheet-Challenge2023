// Code Studio - Combination Sum 2

#include <bits/stdc++.h>
using namespace std;

void solve(int index, vector<int> &arr, int target, vector<int> &ds,
           vector<vector<int>> &ans)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = index; i < arr.size(); i++)
    {
        if (i > index && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > target)
            break;

        ds.push_back(arr[i]);
        solve(i + 1, arr, target - arr[i], ds, ans);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;
    vector<int> ds;
    int index = 0;

    solve(index, arr, target, ds, ans);
    return ans;
}

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<vector<int>> ans = combinationSum2(arr, n, target);

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