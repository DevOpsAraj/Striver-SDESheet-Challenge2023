// Code Studio - Kth Smallest and Largest Element of Array

#include <bits/stdc++.h>
using namespace std;

int kth_Largest_MaxHeap(vector<int> &arr, int k)
{
    priority_queue<int> pq;
    int n = arr.size();

    for (int i = 0; i < arr.size(); i++)
    {
        pq.push(arr[i]);
    }

    int f = k - 1;

    while (f > 0)
    {
        pq.pop();
        f--;
    }

    return pq.top();
}
int kth_Smallest_MinHeap(vector<int> &arr, int k)
{

    priority_queue<int, vector<int>, greater<int>> pq;
    int n = arr.size();

    for (int i = 0; i < arr.size(); i++)
    {
        pq.push(arr[i]);
    }

    int f = k - 1;

    while (f > 0)
    {
        pq.pop();
        f--;
    }

    return pq.top();
}
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    int largest = kth_Largest_MaxHeap(arr, k);
    int smallest = kth_Smallest_MinHeap(arr, k);

    return {smallest, largest};
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> ans = kthSmallLarge(arr, n, k);
    cout << ans[0] << " " << ans[1];
    return 0;
}