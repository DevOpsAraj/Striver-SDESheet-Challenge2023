// Code Studio - Check Permutation

#include <bits/stdc++.h>
using namespace std;

bool areAnagram(string &s, string &t)
{
    if (s.length() != t.length())
        return false;

    unordered_map<char, int> m;
    for (int i = 0; i < s.size(); i++)
    {
        m[s[i]]++;
        m[t[i]]--;
    }
    for (auto x : m)
        if (x.second)
            return false;

    return true;
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << areAnagram(s, t);
    return 0;
}