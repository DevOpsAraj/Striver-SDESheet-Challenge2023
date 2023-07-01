// Code Studio - Min Heap

#include <bits/stdc++.h>
using namespace std;

vector<int> minHeap(int n, vector<vector<int>> &q)
{
    vector<int> mini;
    vector<int> temp;

    auto mn = temp.begin();

    for (int i = 0; i < n; i++)
    {
        if (q[i][0] == 0)
        {
            temp.push_back(q[i][1]);
            mn = min_element(temp.begin(), temp.end());
        }
        else
        {
            mini.push_back(*mn);
            temp.erase(mn);
        }
    }
    return mini;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> q(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> q[i][0] >> q[i][1];
    vector<int> ans = minHeap(n, q);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}