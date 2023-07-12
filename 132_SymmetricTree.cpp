// Code Studio - Symmetric Tree

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class SymmetricTree
{
public:
    int ans = true;
    void solve(Node *root1, Node *root2)
    {
        if (root1 == NULL and root2 == NULL)
            return;
        if (root1 == NULL or root2 == NULL or root1->data != root2->data)
        {
            ans = false;
            return;
        }
        solve(root1->left, root2->right);
    }
    bool isSymmetric(Node *root)
    {
        solve(root, root);
        return ans;
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    SymmetricTree *obj = new SymmetricTree();
    cout << obj->isSymmetric(root) << endl;

    return 0;
}