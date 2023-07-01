// Code Studio - Kth Permutation Sequence

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

string kthPermutation(int n, int k)
{
    int fact = 1;

    vector<int> numbers;
    for (int i = 1; i < n; i++)
    {
        fact = fact * i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    k = k - 1;
    string ans = "";
    while (true)
    {
        ans += to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);

        if (numbers.size() == 0)
        {
            break;
        }
        k = k % fact;
        fact = fact / numbers.size();
    }

    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;

    cout << kthPermutation(n, k) << endl;
    return 0;
}