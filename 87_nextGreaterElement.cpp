// Code Studio - Next Greater Element

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreater(vector<int> &arr, int n)
{
    vector<int> ans(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() <= arr[n - i - 1])
        {
            st.pop();
        }
        if (st.empty() == false)
        {
            ans[n - i - 1] = st.top();
        }
        else
        {
            ans[n - i - 1] = -1;
        }
        st.push(arr[n - i - 1]);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans = nextGreater(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}