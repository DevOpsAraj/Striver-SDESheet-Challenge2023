// Code Studio - Stack using queue

#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    queue<int> q1, q2;
    int size;

public:
    Stack()
    {
        size = 0;
    }

    /*----------------- Public Functions of Stack -----------------*/
    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        if (size == 0)
            return true;
        else
            return false;
    }

    void push(int element)
    {

        // Step 1 : Push Element into q2
        q2.push(element);

        // Step 2 : Push all the elements of q1 into q2
        while (!q1.empty())
        {
            int val = q1.front();
            q1.pop();
            q2.push(val);
        }

        // Step 3 : Swap q1 and q2
        swap(q1, q2);

        // Step 4 : Update the value of size
        size++;
    }

    int pop()
    {
        // Simply Pop from q1
        if (!q1.empty())
        {
            int val = q1.front();
            q1.pop();

            // Update the value of size
            size--;
            return val;
        }
        else
        {
            return -1;
        }
    }

    int top()
    {
        // Return front of q1
        if (!q1.empty())
        {
            return q1.front();
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    Stack s;
    int choice, input;
    bool flag = true;
    while (flag)
    {
        cout << "Enter the choice:\n1. Push\n2. Pop\n3. Top\n4. Size\n5. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            s.push(input);
            break;
        case 2:
            cout << s.pop() << "\n";
            break;
        case 3:
            cout << s.top() << "\n";
            break;
        case 4:
            cout << s.getSize() << "\n";
            break;
        case 5:
            flag = false;
            break;
        default:
            return 0;
        }
    }
}