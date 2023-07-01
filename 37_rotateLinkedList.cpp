// Code Studio - Rotate Linked List

/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    Node *curr = head;
    int len = 1;
    while (curr->next)
    {
        ++len;
        curr = curr->next;
    }

    curr->next = head;
    k = k % len;
    k = len - k;

    while (k--)
        curr = curr->next;

    head = curr->next;
    curr->next = NULL;

    return head;
}
