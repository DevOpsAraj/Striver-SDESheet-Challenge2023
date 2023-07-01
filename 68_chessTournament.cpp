// Code Studio - Chess Tournament

#include <bits/stdc++.h>
using namespace std;

bool canAssign(int c, int mid, vector<int> &positions)
{
    int allot = 1, player = positions[0];
    for (int i = 1; i < positions.size(); i++)
    {
        if (positions[i] - player >= mid)
        {
            allot++;
            player = positions[i];
        }

        if (allot == c)
            return true;
    }

    return false;
}

int chessTournament(vector<int> &positions, int n, int c)
{
    sort(positions.begin(), positions.end());

    int low = 1;
    int high = positions[n - 1] - positions[0];
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canAssign(c, mid, positions))
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}

int main()
{
    int n, c;
    cin >> n >> c;
    vector<int> positions(n);
    for (int i = 0; i < n; i++)
        cin >> positions[i];
    cout << chessTournament(positions, n, c);
    return 0;
}