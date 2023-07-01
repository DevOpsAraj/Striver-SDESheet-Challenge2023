// Code Studio - Maximum Consecutive Ones

#include <bits/stdc++.h>
using namespace std;

int longestSubSeg(vector<int> &arr, int n, int k)
{
    int i = 0, j = 0, ans = 0, count = 0;
    while (j < n)
    {
        if (arr[j] == 0)
            count++;
        while (count > k)
        {
            if (arr[i] == 0)
                count--;
            i++;
        }
        ans = max(ans, j - i + 1);
        j++;
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << longestSubSeg(arr, n, k) << endl;
    return 0;
}