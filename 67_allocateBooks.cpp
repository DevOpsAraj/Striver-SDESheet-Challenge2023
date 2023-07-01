// Code Studio - Allocate Books

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int n, int m, vector<int> &time, long long mid)
{
    int pageSum = 0;
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        if (time[i] > mid)
            return false;
        if (pageSum + time[i] > mid)
        {
            cnt++;
            pageSum = time[i];
            if (cnt > m)
                return false;
        }
        else
        {
            pageSum += time[i];
        }
    }
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> &time)
{
    if (m > n)
        return -1;

    long long start = 0;
    long long end = accumulate(time.begin(), time.end(), 0);
    long long ans = -1;

    while (start <= end)
    {
        long long mid = start + (end - start) / 2;
        if (isPossible(n, m, time, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> time(n);
    for (int i = 0; i < n; i++)
        cin >> time[i];
    cout << ayushGivesNinjatest(n, m, time) << endl;
    return 0;
}