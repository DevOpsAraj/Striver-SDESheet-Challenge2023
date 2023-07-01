// Code Studio - 3 Sum

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
vector<vector<int>> findTriplets(vector<int> nums, int n, int K)
{

    if (n < 3)
        return {};

    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++)
    {
        int start = i + 1;
        int end = n - 1;
        while (start < end)
        {

            int sum = nums[i] + nums[start] + nums[end];
            if (sum == K)
            {
                ans.push_back({nums[i], nums[start], nums[end]});
                start++;
                end--;
                while (start < n && nums[start] == nums[start - 1])
                {
                    start++;
                }

                while (end > i && nums[end] == nums[end + 1])
                {
                    end--;
                }
            }
            else if (sum > K)
            {
                end--;
            }
            else
            {
                start++;
            }
        }
        while (i < n - 1 && nums[i] == nums[i + 1])
            i++;
    }
    return ans;
}

int main()
{
    int n, K;
    cin >> n >> K;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<vector<int>> ans = findTriplets(nums, n, K);
    if (ans.size() == 0)
        cout << "Empty";
    else
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << "(";
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j];
                if (j < ans[i].size() - 1)
                    cout << " ";
            }
            cout << ")";
            if (i < ans.size() - 1)
                cout << ", ";
        }
    }
    return 0;
}