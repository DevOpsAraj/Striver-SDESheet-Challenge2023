// Code Studio - Maximum Product Subarray

#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int prod1 = nums[0];
    int prod2 = nums[0];
    int result = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        int temp = max({nums[i], prod1 * nums[i], prod2 * nums[i]});
        prod2 = min({nums[i], prod1 * nums[i], prod2 * nums[i]});

        prod1 = temp;
        result = max(result, prod1);
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &i : nums)
        cin >> i;

    cout << maxProduct(nums) << endl;
    return 0;
}