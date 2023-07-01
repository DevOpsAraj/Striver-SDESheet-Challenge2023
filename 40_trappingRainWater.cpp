// Code Studio - Trapping Rain Water

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
long getTrappedWater(long *arr, int n)
{
    long left = 0, right = n - 1;
    long leftMax = INT_MIN, rightMax = INT_MIN;
    long totalWater = 0;

    while (left <= right)
    {
        if (arr[left] <= arr[right])
        {
            if (arr[left] >= leftMax)
                leftMax = arr[left];
            else
                totalWater += leftMax - arr[left];
            left++;
        }
        else
        {
            if (arr[right] >= rightMax)
                rightMax = arr[right];
            else
                totalWater += rightMax - arr[right];
            right--;
        }
    }

    return totalWater;
}

int main()
{
    int n;
    cin >> n;
    long arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << getTrappedWater(arr, n) << endl;
    return 0;
}