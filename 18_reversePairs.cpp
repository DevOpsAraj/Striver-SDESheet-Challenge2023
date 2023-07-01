// Code Studio - Reverse Pairs

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    int left, right;
    vector<int> temp;
    left = low;
    right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

int cntPairs(vector<int> &arr, int low, int mid, int high)
{

    int count = 0;
    int right = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > 2 * arr[right])
        {
            right++;
        }
        count += right - mid - 1;
    }

    return count;
}

int merges(vector<int> &arr, int low, int high)
{
    int count = 0;
    if (low >= high)
        return count;
    int mid = (low + high) / 2;

    count += merges(arr, low, mid);

    count += merges(arr, mid + 1, high);

    count += cntPairs(arr, low, mid, high);

    merge(arr, low, mid, high);

    return count;
}

int mergesort(vector<int> &arr, int n)
{
    return merges(arr, 0, n - 1);
}

int reversePairs(vector<int> &arr, int n)
{
    return mergesort(arr, n);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << reversePairs(arr, n) << endl;
    return 0;
}