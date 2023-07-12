// Code Studio - Construct Binary Tree from Inorder and Postorder Traversal

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

Node *constructTree(int is, int ie, vector<int> &inorder, int ps,
                    int pe, vector<int> &postorder,
                    unordered_map<int, int> &mp)
{
    if (ps > pe or is > ie)
        return NULL;

    Node *root = new Node(postorder[pe]);
    int inroot = mp[root->data];
    int numsLeft = inroot - is;

    root->left = constructTree(is, inroot - 1, inorder, ps, ps + numsLeft - 1,
                               postorder, mp);
    root->right = constructTree(inroot + 1, ie, inorder, ps + numsLeft, pe - 1,
                                postorder, mp);

    return root;
}

Node *getTreeFromPostorderAndInorder(vector<int> &postorder, vector<int> &inorder)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
        mp[inorder[i]] = i;

    return constructTree(0, inorder.size() - 1, inorder, 0, postorder.size() - 1,
                         postorder, mp);
}

int main()
{
    int n;
    cin >> n;
    vector<int> postorder(n), inorder(n);
    for (int i = 0; i < n; i++)
        cin >> postorder[i];
    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    Node *root = getTreeFromPostorderAndInorder(postorder, inorder);
    cout << root->data << endl;
    return 0;
}