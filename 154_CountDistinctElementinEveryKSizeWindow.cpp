// Code Studio - Count Distinct Element in Every K Size Window

#include <bits/stdc++.h>
using namespace std;

vector<int> countDistinctElements(vector<int> &arr, int k)
{
    vector<int> ans;
    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
        if (i >= k - 1)
        {
            ans.push_back(mp.size());
            if (--mp[arr[i - k + 1]] == 0)
                mp.erase(arr[i - k + 1]);
        }
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int &x : arr)
        cin >> x;

    vector<int> ans = countDistinctElements(arr, k);
    for (int x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}