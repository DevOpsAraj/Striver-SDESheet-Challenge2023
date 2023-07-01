// Code Studio - Print Permutations

#include <bits/stdc++.h>
using namespace std;

void solve(int index, string &s, vector<string> &ans)
{
    if (index == s.length())
    {
        ans.push_back(s);
        return;
    }

    for (int i = index; i < s.length(); i++)
    {
        swap(s[i], s[index]);
        solve(index + 1, s, ans);
        swap(s[i], s[index]);
    }
}
vector<string> findPermutations(string &s)
{
    vector<string> ans;
    solve(0, s, ans);
    return ans;
}

int main()
{
    string s;
    cin >> s;

    vector<string> ans = findPermutations(s);

    for (auto str : ans)
    {
        cout << str << endl;
    }
    return 0;
}