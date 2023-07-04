// Code Studio - Longest Common Prefix

#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";
    for (int i = 0; i < arr[0].size(); i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[0][i] != arr[j][i])
            {
                return ans;
            }
        }
        ans = ans + arr[0][i];
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << longestCommonPrefix(arr, n) << endl;
    return 0;
}