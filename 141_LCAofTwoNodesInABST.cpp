// Code Studio - LCA of Two Nodes in a BST

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

Node *LCAinaBST(Node *root, Node *P, Node *Q)
{
    if (root == NULL)
        return NULL;

    if (root->data > P->data && root->data > Q->data)
        LCAinaBST(root->left, P, Q);

    else if (root->data < P->data && root->data < Q->data)
        LCAinaBST(root->right, P, Q);

    else
        return root;
}

int main()
{
    
    return 0;
}