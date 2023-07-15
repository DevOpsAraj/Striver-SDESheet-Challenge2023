// Code Studio - Kth Largest Element In BST

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

void findKthLarge(Node *root, int &ans, int &k)
{
    if (!root || k <= 0)
        return;
    findKthLarge(root->right, ans, k);
    k--;
    if (k == 0)
    {
        ans = root->data;
        return;
    }
    findKthLarge(root->left, ans, k);
}

int KthLargestNumber(Node *root, int k)
{
    int ans = -1;
    findKthLarge(root, ans, k);
    return ans;
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    cout << KthLargestNumber(root, 3);

    return 0;
}