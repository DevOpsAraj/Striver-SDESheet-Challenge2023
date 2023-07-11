// Code Studio - Is Height Balanced Binary Tree

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

int height(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = height(root->left);
    if (lh == -1)
        return -1;

    int rh = height(root->right);
    if (rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
        return -1;

    return 1 + max(lh, rh);
}

bool isBalancedBT(Node *root)
{
    return height(root) != -1;
}

int main()
{
    int n;
    cin >> n;
    Node *root = NULL;
    queue<Node *> q;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        Node *temp = new Node(data);
        if (root == NULL)
            root = temp;
        else
        {
            Node *f = q.front();
            if (f->left == NULL)
                f->left = temp;
            else if (f->right == NULL)
                f->right = temp;
            if (f->left != NULL && f->right != NULL)
                q.pop();
        }
        q.push(temp);
    }
    cout << isBalancedBT(root) << endl;
    return 0;
}