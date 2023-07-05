// Code Studio - Count And Say

#include <bits/stdc++.h>
using namespace std;

string writeAsYouSpeak(int n)
{
    string s = "1";

    for (int i = 0; i < n - 1; i++)
    {
        string a;
        for (int j = 0; j < s.length();)
        {
            int cnt = 0;
            int k = j;
            while (j < s.length() && s[j] == s[k])
            {
                cnt++;
                k++;
            }
            a += to_string(cnt) + s[j];
            j = k;
        }
        s = a;
    }
    return s;
}

int main()
{
    int n;
    cin >> n;
    cout << writeAsYouSpeak(n);
    return 0;
}