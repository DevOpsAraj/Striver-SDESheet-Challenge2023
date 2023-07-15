// Code Studio - Ceil in a BST

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

void solve(Node *root, int X, int &ceil, int &tmp)
{
    if (!root)
        return;

    if (root->data == X)
    {
        ceil = root->data;
        return;
    }

    if (root->data > X)
    {
        if (root->data < tmp)
        {
            tmp = root->data;
            ceil = root->data;
        }
        solve(root->left, X, ceil, tmp);
    }
    else
        solve(root->right, X, ceil, tmp);
}
int findCeil(Node *root, int X)
{
    if (!root)
        return 0;

    int ceil = -1, tmp = INT_MAX;
    solve(root, X, ceil, tmp);

    return ceil;
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    cout << findCeil(root, 65);

    return 0;
}