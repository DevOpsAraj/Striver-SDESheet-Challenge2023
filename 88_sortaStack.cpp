// Code Studio - Sort a Stack

#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &stack, int num)
{
    if (stack.empty() || (!stack.empty() && stack.top() < num))
    {
        stack.push(num);
        return;
    }

    int n = stack.top();
    stack.pop();

    insert(stack, num);
    stack.push(n);
}
void sortStack(stack<int> &stack)
{
    if (stack.empty())
        return;

    int num = stack.top();
    stack.pop();

    sortStack(stack);

    insert(stack, num);
}

int main()
{
    int n;
    cin >> n;
    stack<int> stack;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        stack.push(num);
    }

    sortStack(stack);

    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
    return 0;
}