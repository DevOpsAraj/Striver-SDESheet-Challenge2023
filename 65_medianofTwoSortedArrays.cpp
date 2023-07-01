// Code Studio - Median of Two Sorted Arrays

#include <bits/stdc++.h>
using namespace std;

double median(vector<int> &nums1, vector<int> &nums2)
{
    if (nums1.size() > nums2.size())
    {
        return median(nums2, nums1); // Change the parameters
    }

    // Find the size of both array
    int m = nums1.size();
    int n = nums2.size();

    // Take 2 pointer as we use in normal binary search
    int start = 0;
    int end = m;

    // Perform binary search
    while (start <= end)
    {
        // Find the partitions
        int partition1 = (start + end) / 2;
        int partition2 = (m + n + 1) / 2 - partition1;

        // Find the four element
        int maxLeftNums1 = partition1 == 0 ? INT_MIN : nums1[partition1 - 1];
        int maxLeftNums2 = partition2 == 0 ? INT_MIN : nums2[partition2 - 1];

        int minRightNums1 = partition1 == m ? INT_MAX : nums1[partition1];
        int minRightNums2 = partition2 == n ? INT_MAX : nums2[partition2];

        if (maxLeftNums1 <= minRightNums2 && maxLeftNums2 <= minRightNums1)
        {
            if ((m + n) % 2 == 0)
            {
                return (double)(max(maxLeftNums1, maxLeftNums2) +
                                min(minRightNums1, minRightNums2)) /
                       2;
            }
            else
                return (double)max(maxLeftNums1, maxLeftNums2);
        }
        else if (maxLeftNums1 > minRightNums2)
            end = partition1 - 1;
        else
            start = partition1 + 1;
    }

    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n), nums2(m);
    for (int i = 0; i < n; i++)
        cin >> nums1[i];
    for (int i = 0; i < m; i++)
        cin >> nums2[i];
    cout << median(nums1, nums2) << endl;
    return 0;
}