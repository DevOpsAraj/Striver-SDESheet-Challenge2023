// Code Studio - Longest Consecutive Sequence

#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &arr)
{
    unordered_set<int> s;
    for (int i = 0; i < arr.size(); i++)
    {
        s.insert(arr[i]);
    }

    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (s.find(arr[i] - 1) == s.end())
        {
            int j = arr[i];
            while (s.find(j) != s.end())
            {
                j++;
            }
            ans = max(ans, j - arr[i]);
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << longestConsecutive(arr) << endl;
    return 0;
}