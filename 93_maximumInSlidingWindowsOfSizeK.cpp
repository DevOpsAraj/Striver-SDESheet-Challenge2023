// Code Studio - Maximum in Sliding Window of Size K

#include <bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    vector<int> ans;
    int n = nums.size();

    deque<int> dq; // only indexes are stored

    for (int i = 0; i < n; i++)
    {

        while (!dq.empty() && i - dq.front() >= k)
            dq.pop_front(); // only window size of k is allowed

        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);
        if (i >= k - 1)
            ans.push_back(nums[dq.front()]); // our max value in O(1)
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (auto &i : nums)
        cin >> i;
    vector<int> ans = slidingWindowMaximum(nums, k);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}