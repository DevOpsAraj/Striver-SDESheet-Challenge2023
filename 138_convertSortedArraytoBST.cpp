// Code Studio - Convert Sorted Array to BST

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

Node *rec(vector<int> &nums, int low, int high)
{

    if (low > high)
        return NULL;

    int mid = low + (high - low) / 2;

    Node *root = new Node(nums[mid]);
    root->left = rec(nums, low, mid - 1);
    root->right = rec(nums, mid + 1, high);

    return root;
}
Node *sortedArrToBST(vector<int> &arr, int n)
{
    return rec(arr, 0, n - 1);
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50};
    int n = arr.size();

    Node *root = sortedArrToBST(arr, n);
    preOrder(root);

    return 0;
}