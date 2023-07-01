// Code Studio - Kth Element of Two Sorted Arrays

#include <bits/stdc++.h>
using namespace std;

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int n, int m, int k)
{
    if (n > m)
        return ninjaAndLadoos(row2, row1, m, n, k);

    int low = max(0, k - m), high = min(n, k);
    while (low <= high)
    {
        int partition1 = (low + high) >> 1;
        int partition2 = k - partition1;

        int maxLeftNums1 = partition1 == 0 ? INT_MIN : row1[partition1 - 1];
        int maxLeftNums2 = partition2 == 0 ? INT_MIN : row2[partition2 - 1];
        int minRightNums1 = partition1 == n ? INT_MAX : row1[partition1];
        int minRightNums2 = partition2 == m ? INT_MAX : row2[partition2];

        if (maxLeftNums1 <= minRightNums2 and maxLeftNums2 <= minRightNums1)
            return max(maxLeftNums1, maxLeftNums2);
        else if (maxLeftNums1 > minRightNums2)
            high = partition1 - 1;
        else
            low = partition1 + 1;
    }

    return 1;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> row1(n), row2(m);
    for (int i = 0; i < n; i++)
        cin >> row1[i];
    for (int i = 0; i < m; i++)
        cin >> row2[i];
    cout << ninjaAndLadoos(row1, row2, n, m, k);
    return 0;
}