// Code Studio - Find Nth Root Of M

#include <bits/stdc++.h>
using namespace std;

int NthRoot(int n, int m)
{
    int low = 1;
    int high = m;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (pow(mid, n) == m)
            return mid;
        else if (pow(mid, n) > m)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << NthRoot(n, m) << endl;
    return 0;
}
