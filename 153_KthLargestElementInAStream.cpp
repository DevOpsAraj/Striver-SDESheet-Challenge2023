// Code Studio - Kth Largest Element in a Stream

#include <bits/stdc++.h>
using namespace std;

class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    KthLargest(int k, vector<int> &arr)
    {
        K = k;
        for (auto &num : arr)
        {
            pq.push(num);
            if (pq.size() > K)
                pq.pop();
        }
    }

    void add(int num)
    {
        pq.push(num);
        if (pq.size() > K)
            pq.pop();
    }

    int getKthLargest()
    {
        return pq.top();
    }
};

int main()
{
    int k, n;
    cin >> k >> n;
    vector<int> arr(n);
    for (int &x : arr)
        cin >> x;

    KthLargest *obj = new KthLargest(k, arr);
    int q;
    cin >> q;
    while (q--)
    {
        int num;
        cin >> num;
        obj->add(num);
        cout << obj->getKthLargest() << endl;
    }
    return 0;
}