// Code Studio - Add Two Numbers

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node *temp = new Node(0);
    Node *curr = temp;

    int carry = 0;

    while (num1 != NULL || num2 != NULL || carry != 0)
    {
        int sum = 0;
        if (num1 != NULL)
        {
            sum += num1->data;
            num1 = num1->next;
        }
        if (num2 != NULL)
        {
            sum += num2->data;
            num2 = num2->next;
        }
        sum += carry;
        carry = sum / 10;
        curr->next = new Node(sum % 10);
        curr = curr->next;
    }
    return temp->next;
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
    struct Node *head = addTwoNumbers(head1, head2);
    printList(head);
    return 0;
}