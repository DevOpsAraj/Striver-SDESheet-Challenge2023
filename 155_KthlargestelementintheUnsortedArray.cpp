// Code Studio - Kth Largest Element in the Unsorted Array

#include <bits/stdc++.h>
using namespace std;

int kthLargest1(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
            pq.pop();
    }
    return pq.top();
}

int kthLargest2(vector<int> &arr, int size, int K)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < K; ++i)
    {
        pq.push(arr[i]);
    }
    for (int i = K; i < size; ++i)
    {
        if (pq.top() < arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        v[i] = arr[i];
    }

    cout << kthLargest1(arr, n, k) << endl;
    cout << kthLargest2(v, n, k) << endl;
    return 0;
}