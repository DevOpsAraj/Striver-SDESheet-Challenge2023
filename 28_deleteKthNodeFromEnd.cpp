// Code Studio - Delete Kth Node From End

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

Node *removeKthNode(Node *head, int n)
{
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }
    if (cnt == n)
    {
        head = head->next;
        return head;
    }

    n = cnt - n;
    temp = head;
    while (n - 1)
    {
        temp = temp->next;
        n--;
    }
    temp->next = temp->next->next;
    return head;
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
    int n, k;
    cin >> n >> k;
    struct Node *head = createList(n);
    printList(head);

    Node *ans = removeKthNode(head, k);
    printList(ans);
    return 0;
}
