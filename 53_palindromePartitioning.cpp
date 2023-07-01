// Code Studio - Palindrome Partitioning

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int start, int end)
{
    while (start <= end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void solve(int index, string &s, vector<vector<string>> &ans,
           vector<string> &path)
{
    if (index == s.size())
    {
        ans.push_back(path);
        return;
    }
    for (int i = index; i < s.size(); i++)
    {
        if (isPalindrome(s, index, i))
        {
            path.push_back(s.substr(index, i - index + 1));
            solve(i + 1, s, ans, path);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s)
{
    vector<vector<string>> ans;
    vector<string> path;
    solve(0, s, ans, path);
    return ans;
}

int main()
{
    string s;
    cin >> s;

    vector<vector<string>> ans = partition(s);

    for (auto str : ans)
    {
        for (int i = 0; i < str.size(); i++)
        {
            cout << str[i] << " ";
        }
        cout << endl;
    }

    return 0;
}