// Code Studio - Count Subarrays with Given XOR

#include <bits/stdc++.h>
using namespace std;

int subarraysXor(vector<int> &arr, int x)
{

    unordered_map<int, int> m;
    m[0] = 1;
    int cnt = 0;
    int _xor = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        _xor ^= arr[i];
        if (m.find(_xor ^ x) == m.end())
            m[_xor]++;
        else
        {
            cnt += m[_xor ^ x];
            m[_xor]++;
        }
    }

    return cnt;
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << subarraysXor(arr, x) << endl;
    return 0;
}