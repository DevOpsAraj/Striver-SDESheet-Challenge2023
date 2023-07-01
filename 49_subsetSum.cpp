// Code Studio - Subset Sum

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &num, int size, int index, int sum, vector<int> &ans)
{
    if (index > size - 1)
        return;

    // Not Pick
    solve(num, size, index + 1, sum, ans);

    // Pick
    sum += num[index];
    ans.push_back(sum);
    solve(num, size, index + 1, sum, ans);
}
vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    int n = num.size();
    if (n == 0)
        return ans;

    ans.push_back(0);

    solve(num, n, 0, 0, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; ++i)
        cin >> num[i];
    vector<int> ans = subsetSum(num);
    for (auto val : ans)
        cout << val << " ";
    cout << endl;
    return 0;
}