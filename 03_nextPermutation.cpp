// Code Studio - Next Permutation

#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int k, l;
    for (k = n - 2; k >= 0; k--)
    {
        if (permutation[k] < permutation[k + 1])
        {
            break;
        }
    }

    if (k < 0)
    {
        reverse(permutation.begin(), permutation.end());
    }

    else
    {
        for (l = n - 1; l > k; l--)
        {
            if (permutation[l] > permutation[k])
            {
                break;
            }
        }
        swap(permutation[k], permutation[l]);
        reverse(permutation.begin() + k + 1, permutation.end());
    }
    return permutation;
}

int main()
{
    int n;
    cin >> n;

    vector<int> permutation(n);
    for (int i = 0; i < n; i++)
        cin >> permutation[i];

    vector<int> ans = nextPermutation(permutation, n);

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    return 0;
}