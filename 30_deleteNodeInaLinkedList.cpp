// Code Studio - Delete Node in a Linked List

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

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Deleting node with value: " << value << endl;
    }
};

void deleteNode(Node *node)
{
    Node *temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    temp->next = NULL;
    delete temp;
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
    printList(head);
    int pos;
    cin >> pos;
    Node *temp = head;
    for (int i = 0; i < pos; i++)
    {
        temp = temp->next;
    }
    deleteNode(temp);
    printList(head);
    delete head;
    return 0;
}