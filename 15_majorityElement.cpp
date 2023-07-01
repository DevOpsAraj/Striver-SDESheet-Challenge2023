// Code Studio - Majority Element

#include <bits/stdc++.h>
using namespace std;

int findMajorityElement(int arr[], int n)
{
    int majorityElement = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count = 1;
            majorityElement = arr[i];
            continue;
        }
        if (majorityElement == arr[i])
            count++;
        else
            count--;
    }

    count = 0;
    for (int i = 0; i < n; i++)
        if (majorityElement == arr[i])
            count++;
    return count > n / 2 ? majorityElement : -1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << findMajorityElement(arr, n) << endl;
    return 0;
}
