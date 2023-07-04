// Code Studio - Z Algorithm

#include <bits/stdc++.h>
using namespace std;

int zAlgorithm(string s, string p, int n, int m)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == p[0])
            if (s.substr(i, m) == p)
                cnt++;
    }
    return cnt;
}

int main()
{
    string s, p;
    cin >> s >> p;
    int n = s.length();
    int m = p.length();
    cout << zAlgorithm(s, p, n, m);
    return 0;
}