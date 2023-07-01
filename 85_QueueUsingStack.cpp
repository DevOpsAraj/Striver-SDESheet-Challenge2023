// Code Studio - Queue using stack

#include <bits/stdc++.h>
using namespace std;

class Queue
{
    // Make 2 stacks ans size
    stack<int> s1;
    stack<int> s2;
    int size;

public:
    Queue()
    {
        // Initialize your size structure here.
        size = 0;
    }

    void enQueue(int val)
    {
        // enQueue or push operation

        // Step 1 : Put all the elements from s1 to  s2
        while (!s1.empty())
        {
            int val = s1.top();
            s1.pop();
            s2.push(val);
        }

        // Step 2 : Put the element is s1
        s1.push(val);

        // Step 3 : Put all the elements from s2 to  s1
        while (!s2.empty())
        {
            int val = s2.top();
            s2.pop();
            s1.push(val);
        }

        size++;
    }

    int deQueue()
    {
        // Dequeue or pop operation

        if (s1.empty())
        {
            return -1;
        }
        else
        {
            int val = s1.top();
            s1.pop();
            size--;
            return val;
        }
    }

    int peek()
    {
        // Check size
        if (s1.empty())
        {
            return -1;
        }
        else
        {
            int val = s1.top();
            return val;
        }
    }

    bool isEmpty()
    {
        if (s1.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);

    cout << q.peek() << endl;
    cout << q.deQueue() << endl;
    cout << q.peek() << endl;
    cout << q.isEmpty() << endl;

    q.enQueue(60);
    cout << q.peek() << endl;
    cout << q.isEmpty() << endl;

    return 0;
}