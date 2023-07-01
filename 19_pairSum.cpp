// Code Studio - Pair Sum

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    int cnt = 0;
    vector<vector<int>> ans;
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        if (mp[s - arr[i]])
        {
            int val = mp[s - arr[i]];
            vector<int> output;
            while (val--)
            {
                output.push_back(min(arr[i], s - arr[i]));
                output.push_back(max(arr[i], s - arr[i]));
                ans.push_back(output);
            }
        }
        mp[arr[i]]++;
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n, s;
    cin >> n >> s;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<int>> res = pairSum(arr, s);
    if (res.size() == 0)
        cout << "Empty" << endl;
    else
    {
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i][0] << " " << res[i][1] << endl;
        }
        cout << endl;
    }
    return 0;
}