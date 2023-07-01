// Code Studio - Maximum Activities

#include <bits/stdc++.h>
using namespace std;

int maximumActivities(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    vector<pair<int, int> > v;
    for (int i = 0; i < n; ++i)
    {
        v.emplace_back(make_pair(end[i], start[i]));
    }
    sort(v.begin(), v.end());
    int e = -1;
    int ans = 0;
    for (auto val : v)
    {
        if (val.second > e - 1)
        {
            ans++;
            e = val.first;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> start(n), end(n);
    for (int i = 0; i < n; ++i)
        cin >> start[i];
    for (int i = 0; i < n; ++i)
        cin >> end[i];
    cout << maximumActivities(start, end) << endl;
    return 0;
}