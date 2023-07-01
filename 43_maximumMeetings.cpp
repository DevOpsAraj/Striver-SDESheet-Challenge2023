// Code Studio - Maximum Meetings

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
bool cmp(const pair<int, pair<int, int>> &a,
         const pair<int, pair<int, int>> &b)
{
    if (a.first < b.first)
        return true;

    else if (a.first > b.first)
        return false;

    else if (a.second.second < b.second.second)
        return true;

    else
        return false;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end)
{

    vector<pair<int, pair<int, int>>> meet;

    for (int i = 0; i < start.size(); i++)
    {
        meet.push_back({end[i], {start[i], i + 1}});
    }

    sort(meet.begin(), meet.end(), cmp);
    int t = -1;
    vector<int> ans;

    for (int i = 0; i < start.size(); i++)
    {
        if (meet[i].second.first > t)
        {
            ans.push_back(meet[i].second.second);
            t = meet[i].first;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> start(n), end(n);
    for (int i = 0; i < n; i++)
        cin >> start[i];
    for (int i = 0; i < n; i++)
        cin >> end[i];

    vector<int> ans = maximumMeetings(start, end);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}