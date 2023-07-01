// Code Studio - Sort 0 1 2

#include <bits/stdc++.h>
using namespace std;

void sort012(int *arr, int n)
{
    int low = 0, mid = 0, high = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[mid] == 0)
            swap(arr[mid++], arr[low++]);
        else if (arr[mid] == 1)
            mid++;
        else
            swap(arr[mid], arr[high--]);
    }
}
int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    sort012(arr, n);
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    delete[] arr;
    return 0;
}