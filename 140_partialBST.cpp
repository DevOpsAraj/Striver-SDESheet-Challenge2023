// Code Studio - Partial BST

#include <bits\stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

bool solve(Node *root, Node *minNode, Node *maxNode)
{
    if (root == nullptr)
        return true;
    if (minNode != nullptr && minNode->data > root->data ||
        maxNode != nullptr && maxNode->data < root->data)
        return false;
    return solve(root->left, minNode, root) && solve(root->right, root, maxNode);
}

bool validateBST(Node *root)
{
    return solve(root, nullptr, nullptr);
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    cout << validateBST(root);

    return 0;
}