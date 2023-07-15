// Code Studio - Pair Sum in BST

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

void solve(Node *root, int k, unordered_map<int, int> &mp, bool &ans)
{
    if (root == NULL)
        return;

    int check = k - root->data;

    if (mp.find(k - root->data) != mp.end())
    {
        ans = true;
        return;
    }
    mp[root->data] = 1;

    solve(root->left, k, mp, ans);
    solve(root->right, k, mp, ans);
}

bool pairSumBst(Node *root, int k)
{
    unordered_map<int, int> mp;
    bool ans = false;

    solve(root, k, mp, ans);
    return ans;
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);

    root->left->left = new Node(2);
    root->left->right = new Node(4);

    root->right->right = new Node(7);

    int k = 9;

    if (pairSumBst(root, k))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}