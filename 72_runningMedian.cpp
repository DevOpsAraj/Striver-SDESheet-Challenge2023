// Code Studio - Running Median

#include <bits/stdc++.h>
using namespace std;

void findMedian(int *arr, int n)
{
    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;

    for (int i = 0; i < n; i++)
    {
        if (maxH.empty() || maxH.top() >= arr[i])
            maxH.push(arr[i]);
        else
            minH.push(arr[i]);

        if (maxH.size() > minH.size() + 1)
        {
            minH.push(maxH.top());
            maxH.pop();
        }
        else if (maxH.size() < minH.size())
        {
            maxH.push(minH.top());
            minH.pop();
        }

        if (minH.size() < maxH.size())
            cout << maxH.top() << " ";
        else
            cout << (minH.top() + maxH.top()) / 2 << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    findMedian(arr, n);
    delete[] arr;
    return 0;
}