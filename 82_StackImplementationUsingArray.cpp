// Code Studio - Stack Implementation Using Array

#include <bits/stdc++.h>
using namespace std;

// Stack class.
class Stack
{
private:
    int *arr;
    int topIndex;
    int size;

public:
    Stack(int capacity)
    {
        arr = new int[capacity];
        topIndex = 0;
        size = capacity;
    }

    void push(int num)
    {
        if (topIndex != size)
        {
            arr[topIndex] = num;
            topIndex++;
        }
    }

    int pop()
    {
        if (topIndex != 0)
        {
            topIndex--;
            return arr[topIndex];
        }
        return -1;
    }

    int top() { return (topIndex != 0) ? (arr[topIndex - 1]) : (-1); }

    int isEmpty() { return (topIndex == 0) ? (1) : (0); }

    int isFull() { return (topIndex == size); }
};

int main()
{
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;
    cout << s.isEmpty() << endl;
    cout << s.isFull() << endl;
    return 0;
}