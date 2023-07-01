// Code Studio - Longest Subarray Zero Sum

#include <bits/stdc++.h>
using namespace std;

int longestSubarrayZeroSum(vector<int> &arr)
{
    unordered_map<int, int> mp;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == 0)
            ans = i + 1;
        else
        {
            if (mp.find(sum) != mp.end())
            {
                ans = max(ans, i - mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
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

    cout << longestSubarrayZeroSum(arr) << endl;
    return 0;
}