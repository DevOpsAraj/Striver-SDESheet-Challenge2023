// Code Studio - Floor In BST

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

int floorInBST(Node *root, int X)
{
    if (root == NULL)
        return -1;
    int left = floorInBST(root->left, X);

    if (root->data > X)
        return left;

    int right = floorInBST(root->right, X);
    return max(root->data, right);
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

    cout << floorInBST(root, 65);

    return 0;
}