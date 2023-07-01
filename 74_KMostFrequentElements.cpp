// Code Studio - K Most Frequent Elements

#include <bits/stdc++.h>
using namespace std;

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    vector<int> ans;
    map<int, int> m;

    for (int i = 0; i < n; i++)
        m[arr[i]]++;

    priority_queue<pair<int, int>> pq;
    for (auto i : m)
        pq.push({i.second, i.first});

    for (int i = 1; i <= k; i++)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    vector<int> ans = KMostFrequent(n, k, arr);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";

    return 0;
}