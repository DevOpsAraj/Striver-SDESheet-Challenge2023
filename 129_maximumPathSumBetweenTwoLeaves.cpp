// Code Studio - Maximum Path Sum Between Two Leaves

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

long long int solve(Node *root, long long int &ans)
{
    if (root == NULL)
        return 0;

    long long int leftSum = solve(root->left, ans);
    long long int rightSum = solve(root->right, ans);

    ans = max(ans, root->data + leftSum + rightSum);

    return root->data + max(leftSum, rightSum);
}

long long int findMaxSumPath(Node *root)
{
    if (root == NULL)
        return -1;
    if (root->left == NULL)
        return -1;
    if (root->right == NULL)
        return -1;

    long long int ans = 0;

    solve(root, ans);
    return ans;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);

    cout << findMaxSumPath(root) << endl;

    return 0;
}