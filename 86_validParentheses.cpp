// Code Studio - Valid Parentheses

#include <bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string expression)
{
    stack<char> st;
    for (char c : expression)
    {
        if (!st.empty())
        {
            char ch = st.top();
            if (c - 2 == ch || c - 1 == ch)
            {
                st.pop();
                continue;
            }
        }
        st.push(c);
    }
    return st.empty();
}

int main()
{
    string expression;
    cin >> expression;
    cout << isValidParenthesis(expression);
    return 0;
}