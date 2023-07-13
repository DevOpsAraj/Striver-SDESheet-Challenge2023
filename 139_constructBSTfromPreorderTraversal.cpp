// Code Studio - Construct BST from Preorder Traversal

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

Node *solve(vector<int> &preOrder, int &i, int limit)
{
    if (i == preOrder.size() || preOrder[i] > limit)
        return NULL;

    Node *root = new Node(preOrder[i++]);

    root->left = solve(preOrder, i, root->data);
    root->right = solve(preOrder, i, limit);

    return root;
}

Node *preOrderTree(vector<int> &preOrder)
{
    int i = 0, limit = 1e9;
    return solve(preOrder, i, limit);
}

void printBST(Node *root)
{
    if (!root)
        return;
    printBST(root->left);
    cout << root->data << " ";
    printBST(root->right);
}

int main()
{
    int n;
    cin >> n;
    vector<int> preOrder(n);
    for (int i = 0; i < n; i++)
        cin >> preOrder[i];
    Node *root = preOrderTree(preOrder);
    printBST(root);
    return 0;
}