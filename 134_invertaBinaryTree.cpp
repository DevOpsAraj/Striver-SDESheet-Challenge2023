// Code Studio - Invert a Binary Tree

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

bool storParents(Node *root, stack<Node *> &parents, Node *leaf)
{
    parents.push(root);

    if (!root->left and !root->right)
    {
        if (root->data == leaf->data)
            return true;
        else
            parents.pop();
        return false;
    }

    if (root->left)
    {
        if (storParents(root->left, parents, leaf))
            return true;
    }

    if (root->right)
    {
        if (storParents(root->right, parents, leaf))
            return true;
    }

    parents.pop();
    return false;
}

Node *invertBinaryTree(Node *root, Node *leaf)
{
    if (!root)
        return NULL;

    stack<Node *> parents;
    storParents(root, parents, leaf);

    Node *head = parents.top();
    parents.pop();

    Node *par = head;
    while (!parents.empty())
    {
        auto p = parents.top();
        parents.pop();

        if (p->right == head)
        {
            p->right = p->left;
            p->left = NULL;
        }
        else
        {
            p->left = NULL;
        }

        head->left = p;
        head = p;
    }

    return par;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->right = new Node(5);
    root->left->left = new Node(3);
    root->left->left->left = new Node(4);
    root->right = new Node(6);

    Node *leaf = root->left->left->left;
    Node *head = invertBinaryTree(root, leaf);

    while (head)
    {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;

    return 0;
}