// Code Studio - Implement a Queue

#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int *arr;
    int qFront;
    int rear;
    int size;

public:
    Queue()
    {
        size = 10001;
        arr = new int[size];
        qFront = 0;
        rear = 0;
    }

    bool isEmpty()
    {
        if (qFront == rear)
            return true;
        return false;
    }

    void enqueue(int data)
    {
        if (rear != size)

            arr[rear++] = data;
    }

    int dequeue()
    {
        if (rear == qFront)
            return -1;
        else
        {
            int temp = arr[qFront++];
            if (qFront == rear)
            {
                qFront = 0;
                rear = 0;
            }
            return temp;
        }
    }

    int front()
    {
        if (rear == qFront)
            return -1;
        return arr[qFront];
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.front() << endl;
    cout << q.isEmpty() << endl;
    return 0;
}