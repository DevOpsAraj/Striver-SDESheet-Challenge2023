// Code Studio - Min Stack

#include <bits/stdc++.h>
using namespace std;

// Implement class for minStack.
class minStack
{
    stack<pair<int, int>> s;

public:
    // Constructor
    minStack() {}

    // Function to add another element equal to num at the top of stack.
    void push(int num)
    {
        if (s.empty())
            s.push({num, num});
        else if (s.top().second < num)
            s.push({num, s.top().second});
        else
            s.push({num, num});
    }

    // Function to remove the top element of the stack.
    int pop()
    {
        if (s.empty())
            return -1;
        auto t = s.top();
        s.pop();
        return t.first;
    }

    // Function to return the top element of stack if it is present. Otherwise
    // return -1.
    int top() { return s.empty() ? -1 : s.top().first; }

    // Function to return minimum element of stack if it is present. Otherwise
    // return -1.
    int getMin() { return s.empty() ? -1 : s.top().second; }
};

int main()
{
    minStack s;
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int num;
            cin >> num;
            s.push(num);
        }
        else if (type == 2)
        {
            cout << s.pop() << endl;
        }
        else if (type == 3)
        {
            cout << s.top() << endl;
        }
        else
        {
            cout << s.getMin() << endl;
        }
    }
    return 0;
}