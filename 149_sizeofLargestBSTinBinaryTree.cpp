// Code Studio - sizee of Largest BST in Binary Tree

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class info
{
public:
    int mini;
    int maxi;
    bool isBST;
    int size;
};

info solve(Node *root, int &yes)
{
    if (root == NULL)
        return {INT_MAX, INT_MIN, true, 0};

    info left = solve(root->left, yes);
    info right = solve(root->right, yes);

    info curr;
    curr.mini = min(left.mini, root->data);
    curr.maxi = max(right.maxi, root->data);
    curr.size = left.size + right.size + 1;

    if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini))
    {
        curr.isBST = true;
    }
    else
        curr.isBST = false;

    if (curr.isBST == true)
    {
        yes = max(yes, curr.size);
    }

    return curr;
}

int largestBST(Node *root)
{
    int max_size = 0;
    info temp = solve(root, max_size);
    return max_size;
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);

    root->left->left = new Node(2);
    root->left->right = new Node(4);

    root->right->right = new Node(7);

    cout << largestBST(root);

    return 0;
}
