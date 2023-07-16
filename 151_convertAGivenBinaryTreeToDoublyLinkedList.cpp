// Code Studio - Convert a given Binary Tree to Doubly Linked List

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *BTtoDLL(Node *root)
{
    // From Observation, we can see Morris Traversal inorder will convert given binary tree
    // to doubly linked list
    // iterative method
    // T=O(n) S=O(1)
    Node *head = NULL;
    Node *prev = NULL;
    Node *curr = root;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            // head will store head of linked list
            if (head == NULL)
                head = curr;
            curr->left = prev;
            if (prev)
                prev->right = curr;
            prev = curr;
            curr = curr->right;
        }
        else
        {
            Node *next = curr->left;

            while (next->right != NULL && next->right != curr)
                next = next->right;
            if (next->right == NULL)
            {
                next->right = curr;
                curr = curr->left;
            }
            else
            {
                curr->left = prev;
                prev = curr;
                curr = curr->right;
            }
        }
    }
    return head;
}

void printDLL(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->right;
    }
}

int main()
{
    /*
            10
           /  \
          20   30
         / \   / \
        40 50 60 70
    */
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right = new Node(30);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    Node *head = BTtoDLL(root);
    printDLL(head);
    return 0;
}