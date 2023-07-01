// Code Studio - Online Stock Span

#include <bits/stdc++.h>
using namespace std;

vector<int> findSpans(vector<int> &price)
{
    vector<int> ans;
    stack<int> st;
    st.push(-1);

    for (int i = 0; i < price.size(); i++)
    {
        while (st.top() != -1 && price[st.top()] <= price[i])
            st.pop();

        if (st.top() == -1)
            ans.push_back(i + 1);
        else
            ans.push_back(i - st.top());

        st.push(i);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> price(n);
    for (int i = 0; i < n; i++)
        cin >> price[i];

    vector<int> ans = findSpans(price);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}