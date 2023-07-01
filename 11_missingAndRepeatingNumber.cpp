// Code Studio - Missing and Repeating Number

#include <bits/stdc++.h>
#define ll long long
using namespace std;

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    ll currSum = 0, actualSum = (ll)(n * (n + 1)) / 2;
    for (auto x : arr)
        currSum += (ll)x;
    ll squareCurrSum = 0;
    ll squareActualSum = ((ll)n * (ll)(n + 1) * (ll)(2 * n + 1)) / 6;
    for (auto x : arr)
        squareCurrSum += (ll)x * (ll)x;
    ll diff = currSum - actualSum, squareDiff = squareCurrSum - squareActualSum;
    ll sum = squareDiff / diff;

    ll repeating = (sum + diff) / 2;
    ll missing = sum - repeating;
    return {(int)missing, (int)repeating};
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;

    pair<int, int> ans = missingAndRepeating(arr, n);
    cout << ans.first << " " << ans.second << endl;

    return 0;
}