// Code Studio - Construct Binary Tree From Inorder and Preorder Traversal

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

Node *cT(vector<int> &inorder, vector<int> &preorder, int startIndex, int endIndex, int &preIndex)
{
    if (startIndex > endIndex)
        return NULL;

    Node *root = new Node(preorder[preIndex++]);

    int inIndex;

    for (int i = 0; i <= endIndex; i++)
    {
        if (root->data == inorder[i])
        {
            inIndex = i;
            break;
        }
    }

    root->left = cT(inorder, preorder, startIndex, inIndex - 1, preIndex);
    root->right = cT(inorder, preorder, inIndex + 1, endIndex, preIndex);

    return root;
}

Node *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{

    int preIndex = 0;
    int startIndex = 0, endIndex = inorder.size() - 1;

    return cT(inorder, preorder, startIndex, endIndex, preIndex);
}

int main()
{
    vector<int> inorder = {3, 1, 4, 0, 5, 2};
    vector<int> preorder = {0, 1, 3, 4, 2, 5};

    Node *root = buildBinaryTree(inorder, preorder);

    return 0;
}