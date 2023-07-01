// Code Studio - Complete String

#include <bits/stdc++.h>
using namespace std;

string completeString(int n, vector<string> &a)
{
    set<string> s;
    string ans = "";
    for (int i = 0; i < n; i++)
        s.insert(a[i]);
    for (auto i : a)
    {
        bool flag = 1;
        int m = i.size();
        for (int j = 1; j <= m; j++)
        {
            string t = i.substr(0, j);
            if (s.find(t) == s.end())
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            if (ans.size() == m)
            {
                ans = min(ans, i);
            }
            else if (ans.size() < m)
                ans = i;
        }
    }
    if (ans.size())
        return ans;
    return "None";
}

int main()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << completeString(n, a);
    return 0;
}