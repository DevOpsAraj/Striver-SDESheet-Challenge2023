// Code Studio - Path in a Tree

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

bool check(Node *root, int x, vector<int> &ans)
{
    if (root == NULL)
        return false;

    ans.push_back(root->data);

    if (check(root->left, x, ans) || check(root->right, x, ans))
        return true;

    if (root->data == x)
        return true;

    ans.pop_back();
    return false;
}

vector<int> pathInATree(Node *root, int x)
{
    if (root == NULL)
        return {};

    vector<int> ans;

    check(root, x, ans);
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans = pathInATree(root, 5);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}