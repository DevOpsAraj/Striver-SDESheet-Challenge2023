// Code Studio - Merge K Sorted Arrays

#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    int n = 1;

    for (int i = 0; i < k; i++)
    {
        int n = kArrays[i].size();
        for (int j = 0; j < n; j++)
            pq.push(kArrays[i][j]);
    }

    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}

int main()
{
    int k;
    cin >> k;
    vector<vector<int>> kArrays(k);
    for (int i = 0; i < k; i++)
    {
        int n;
        cin >> n;
        kArrays[i].resize(n);
        for (int j = 0; j < n; j++)
            cin >> kArrays[i][j];
    }

    vector<int> ans = mergeKSortedArrays(kArrays, k);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}