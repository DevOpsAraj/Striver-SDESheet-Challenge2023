// Code Studio - Best Time to Buy and Sell Stock

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int minPrice = INT_MAX, maxProfit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        int diff = prices[i] - minPrice;
        maxProfit = max(maxProfit, diff);
        minPrice = min(minPrice, prices[i]);
    }
    return maxProfit;
}

int main()
{
    int n;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; ++i)
        cin >> prices[i];

    cout << maxProfit(prices);

    return 0;
}