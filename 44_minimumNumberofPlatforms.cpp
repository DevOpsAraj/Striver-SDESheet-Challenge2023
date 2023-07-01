// Code Studio - Minimum Number of Platforms

#include <bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n)
{
    sort(at, at + n);
    sort(dt, dt + n);

    int pltCount = 1, i = 1, j = 0;
    int minPlatforms = 1;

    while (i < n && j < n)
    {
        if (at[i] <= dt[j])
        {
            pltCount++;
            i++;
            if (pltCount > minPlatforms)
            {
                minPlatforms = pltCount;
            }
        }
        else
        {
            pltCount--;
            j++;
        }
    }

    return minPlatforms;
}

int main()
{
    int n;
    cin >> n;
    int at[n], dt[n];
    for (int i = 0; i < n; i++)
        cin >> at[i];
    for (int i = 0; i < n; i++)
        cin >> dt[i];

    cout << calculateMinPatforms(at, dt, n) << endl;
    return 0;
}