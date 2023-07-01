// Code Studio - Merge Two Sorted Linked Lists

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

Node *sortedMerge(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    if (head1->data < head2->data)
    {
        head1->next = sortedMerge(head1->next, head2);
        return head1;
    }
    else
    {
        head2->next = sortedMerge(head1, head2->next);
        return head2;
    }
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
    int n1, n2;
    cin >> n1 >> n2;
    struct Node *head1 = createList(n1);
    struct Node *head2 = createList(n2);
    struct Node *head = sortedMerge(head1, head2);
    printList(head);
    return 0;
}