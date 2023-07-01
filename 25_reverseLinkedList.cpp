// Code Studio - Reverse Linked List

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *
reverseList(struct Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *track = NULL;

    while (curr != NULL)
    {
        track = curr->next;
        curr->next = prev;
        prev = curr;
        curr = track;
    }
    return prev;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

struct Node *createList(int n)
{
    struct Node *head = NULL;
    struct Node *temp = NULL;
    int data;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        if (head == NULL)
        {
            head = new Node();
            head->data = data;
            head->next = NULL;
            temp = head;
        }
        else
        {
            temp->next = new Node();
            temp = temp->next;
            temp->data = data;
            temp->next = NULL;
        }
    }
    return head;
}

int main()
{
    int n;
    cin >> n;
    struct Node *head = createList(n);
    head = reverseList(head);
    printList(head);
    return 0;
}