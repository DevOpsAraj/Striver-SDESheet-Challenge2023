// Code Studio - Merge Two Sorted Array

#include <bits/stdc++.h>
using namespace std;

vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m,
                                 int n)
{
    int index1 = 0;
    int index2 = 0;
    vector<int> ans;

    while (index1 < m && index2 < n)
    {
        if (arr1[index1] < arr2[index2])
        {
            ans.push_back(arr1[index1++]);
        }
        else
        {
            ans.push_back(arr2[index2++]);
        }
    }

    while (index1 < m)
    {
        ans.push_back(arr1[index1++]);
    }

    while (index2 < n)
    {
        ans.push_back(arr2[index2++]);
    }

    return ans;
}
int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> arr1(m), arr2(n);
    for (int i = 0; i < m; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }

    vector<int> ans = ninjaAndSortedArrays(arr1, arr2, m, n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}