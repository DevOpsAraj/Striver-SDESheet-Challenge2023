// Code Studio - K Max Sum Combinations

#include <bits/stdc++.h>
using namespace std;

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k)
{
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    vector<int> ans;
    set<pair<int, int>> visited;
    priority_queue<pair<int, pair<int, int>>> pq;

    pq.push({a[0] + b[0], {0, 0}});
    for (int i = 0; i < k; i++)
    {
        pair<int, pair<int, int>> element = pq.top();
        pq.pop();

        ans.push_back(element.first);
        if (element.second.first + 1 < n &&
            visited.find({element.second.first + 1, element.second.second}) == visited.end()) // 1,0
        {
            pq.push({a[element.second.first + 1] + b[element.second.second],
                     {element.second.first + 1, element.second.second}});
            visited.insert({element.second.first + 1, element.second.second});
        }
        if (element.second.second + 1 < n &&
            visited.find({element.second.first, element.second.second + 1}) == visited.end()) // 0,1
        {
            pq.push({a[element.second.first] + b[element.second.second + 1],
                     {element.second.first, element.second.second + 1}});
            visited.insert({element.second.first, element.second.second + 1});
        }
    }

    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < n; j++)
        cin >> b[j];

    vector<int> ans = kMaxSumCombination(a, b, n, k);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}