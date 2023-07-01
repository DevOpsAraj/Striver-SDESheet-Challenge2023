// Code Studio - Subset II

#include <bits/stdc++.h>
using namespace std;

void solve(int idx, vector<int> &temp, vector<vector<int> > &ans,
           vector<int> &arr, int n)
{

    ans.push_back(temp);

    if (idx >= n)
        return;

    for (int i = idx; i < n; i++)
    {

        if (i > idx && arr[i] == arr[i - 1])
            continue;

        temp.push_back(arr[i]);
        solve(i + 1, temp, ans, arr, n);
        temp.pop_back();
    }
}

vector<vector<int> > uniqueSubsets(int n, vector<int> &arr)
{
    if (n == 0)
        return {};

    sort(arr.begin(), arr.end());
    vector<int> temp;
    vector<vector<int> > ans;
    solve(0, temp, ans, arr, n);

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    vector<vector<int> > ans = uniqueSubsets(n, arr);
    for (auto v : ans)
    {
        for (auto val : v)
            cout << val << " ";
        cout << endl;
    }
    return 0;
}