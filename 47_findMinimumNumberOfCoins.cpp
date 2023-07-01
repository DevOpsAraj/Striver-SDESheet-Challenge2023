// Code Studio - Find Minimum Number of Coins

#include <bits/stdc++.h>
using namespace std;

int findMinimumCoins(int amount)
{
    vector<int> currency;
    currency.push_back(1);
    currency.push_back(2);
    currency.push_back(5);
    currency.push_back(10);
    currency.push_back(20);
    currency.push_back(50);
    currency.push_back(100);
    currency.push_back(500);
    currency.push_back(1000);

    int coins = 0;

    int i = 8;
    while (amount && i >= 0)
    {
        if (amount < currency[i])
        {
            i--;
            continue;
        }

        coins++;
        amount -= currency[i];
    }

    return coins;
}

int main()
{
    int amount;
    cin >> amount;

    cout << findMinimumCoins(amount) << endl;
    return 0;
}