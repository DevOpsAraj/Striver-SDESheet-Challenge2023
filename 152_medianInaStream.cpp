// Code Studio - Median in a stream

#include <bits/stdc++.h>
using namespace std;

vector<int> findMedian(vector<int> &arr, int n)
{
    vector<int> medians;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; i++)
    {
        maxHeap.push(arr[i]);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if (maxHeap.size() < minHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        int median;
        if (maxHeap.size() > minHeap.size())
        {
            median = maxHeap.top();
        }
        else
        {
            median = (maxHeap.top() + minHeap.top()) / 2;
        }
        medians.push_back(median);
    }
    return medians;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr)
        cin >> x;

    vector<int> medians = findMedian(arr, n);
    for (int x : medians)
        cout << x << " ";
    cout << endl;
    return 0;
}