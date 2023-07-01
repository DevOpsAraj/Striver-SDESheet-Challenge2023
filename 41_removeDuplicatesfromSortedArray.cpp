// Code Studio - Remove Duplicates from Sorted Array

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr, int n)
{
    if (n == 0 || n == 1)
        return n;

    int j = 0;
    for (int i = 0; i < n - 1; i++)
        if (arr[i] != arr[i + 1])
            arr[j++] = arr[i];

    arr[j++] = arr[n - 1];
    return j;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int newLength = removeDuplicates(arr, n);
    for (int i = 0; i < newLength; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}