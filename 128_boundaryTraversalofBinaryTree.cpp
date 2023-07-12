// Code Studio - Boundary Traversal of Binary Tree

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
        data = val;
        left = NULL;
        right = NULL;
    }
};

void leftSideView(Node *root, vector<int> &res)
{
    if (!root || (!root->left && !root->right))
        return;

    res.push_back(root->data);

    if (root->left)
        leftSideView(root->left, res);
    else
        leftSideView(root->right, res);
}

void rightSideView(Node *root, vector<int> &res)
{
    if (!root || (!root->left && !root->right))
        return;

    if (root->right)
        rightSideView(root->right, res);
    else
        rightSideView(root->left, res);

    res.push_back(root->data);
}

void leaves(Node *root, vector<int> &res)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        res.push_back(root->data);
        return;
    }

    leaves(root->left, res);
    leaves(root->right, res);
}

vector<int> traverseBoundary(Node *root)
{
    if (!root)
        return {};

    vector<int> res;
    res.push_back(root->data);

    leftSideView(root->left, res);
    leaves(root->left, res);
    leaves(root->right, res);
    rightSideView(root->right, res);

    return res;
}

int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right = new Node(22);
    root->right->right = new Node(25);

    vector<int> res = traverseBoundary(root);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}