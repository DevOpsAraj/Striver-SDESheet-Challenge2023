// Code Studio - Fractional Knapsack

#include <bits/stdc++.h>
using namespace std;

double maximumValue(vector<pair<int, int> > &items, int n, int w)
{
    sort(items.begin(), items.end(), [](pair<int, int> &a, pair<int, int> &b)
         { return ((double)a.second / a.first) > ((double)b.second / b.first); });

    double maxP = 0;
    int currWt = 0;
    for (auto p : items)
    {
        if (p.first + currWt <= w)
        {
            currWt += p.first;
            maxP += p.second;
        }
        else
        {
            maxP += double((double)p.second * (w - currWt)) / p.first;
            break;
        }
    }
    return maxP;
}

int main()
{
    int n, w;
    cin >> n >> w;
    vector<pair<int, int> > items(n);
    for (int i = 0; i < n; i++)
        cin >> items[i].first >> items[i].second;
    cout << maximumValue(items, n, w) << endl;
    return 0;
}