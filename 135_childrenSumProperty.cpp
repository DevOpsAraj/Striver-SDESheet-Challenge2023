// Code Studio - Children Sum Property

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

void changeTree(Node *root)
{
    if (root == NULL)
        return;

    int child = 0;

    if (root->left)
        child += root->left->data;

    if (root->right)
        child += root->right->data;

    if (child >= root->data)
        root->data = child;
    else
    {
        if (root->left)
            root->left->data = root->data;

        if (root->right)
            root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);

    int total = 0;
    if (root->left)
        total += root->left->data;

    if (root->right)
        total += root->right->data;

    if (root->left || root->right)
        root->data = total;
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(7);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(1);
    root->right->right = new Node(30);

    changeTree(root);

    cout << root->data << endl;
    cout << root->left->data << " " << root->right->data << endl;
    cout << root->left->left->data << " " << root->left->right->data << " " << root->right->left->data << " " << root->right->right->data << endl;

    return 0;
}