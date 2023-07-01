// Code Studio - Word Break - II

#include <bits/stdc++.h>
using namespace std;

void solve(string s, vector<string> &res, unordered_set<string> &st,
           vector<string> &temp)
{
    if (s.length() == 0)
    {
        string str = "";
        for (auto it : temp)
        {
            str += it + " ";
        }
        str.pop_back();
        res.push_back(str);
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (st.count(s.substr(0, i + 1)))
        {
            temp.push_back(s.substr(0, i + 1));
            solve(s.substr(i + 1), res, st, temp);
            temp.pop_back();
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string> res, temp;
    unordered_set<string> st(dictionary.begin(), dictionary.end());

    solve(s, res, st, temp);
    return res;
}

int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> dictionary(n);
    for (int i = 0; i < n; i++)
    {
        cin >> dictionary[i];
    }
    vector<string> ans = wordBreak(s, dictionary);
    for (auto it : ans)
    {
        cout << it << endl;
    }
    return 0;
}
