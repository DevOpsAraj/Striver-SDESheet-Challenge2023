// Code Studio - Flatten Binary Tree to Linked List

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void solve(Node *root, Node *&prev)
{
    if (!root)
        return;
    solve(root->right, prev);
    solve(root->left, prev);

    root->right = prev;
    root->left = NULL;

    prev = root;
}

Node *flattenBinaryTree(Node *root)
{
    Node *prev = NULL;
    solve(root, prev);

    return prev;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->right = new Node(5);
    root->left->left = new Node(3);
    root->left->left->left = new Node(4);
    root->right = new Node(6);

    Node *head = flattenBinaryTree(root);

    while (head)
    {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;

    return 0;
}