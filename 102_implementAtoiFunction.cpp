// Code Studio - Implement Atoi Function

#include <bits/stdc++.h>
using namespace std;

int atoi(string str)
{
    bool sign = false;
    string ans = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '-')
            sign = true;
        if (str[i] < 65 && str[i] != '-')
        {
            ans = ans + str[i];
        }
    }
    if (sign == true)
        return -stoi(ans);
    return stoi(ans);
}

int main()
{
    string str;
    cin >> str;
    cout << atoi(str) << endl;
    return 0;
}