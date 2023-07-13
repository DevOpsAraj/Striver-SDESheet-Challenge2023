// Code Studio - Search in BST

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

Node *search(Node *root, int key)
{
    if (!root)
        return NULL;

    if (root->data == key)
        return root;

    if (root->data > key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);

    cout << search(root, 8)->data;

    return 0;
}