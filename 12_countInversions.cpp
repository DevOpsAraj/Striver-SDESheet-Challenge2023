// Code Studio - Count Inversions

#include <bits/stdc++.h>
using namespace std;

long long getInversions(long long *arr, int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;

    long long arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << getInversions(arr, n) << endl;

    return 0;
}