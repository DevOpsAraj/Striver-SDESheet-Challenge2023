// Code Studio - Lowest Common Ancestor Of Binary Tree

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

int lowestCommonAncestor(Node *root, int x, int y)
{

    if (root == NULL)
        return -1;

    if (root->data == x || root->data == y)
        return root->data;

    int leftAns = lowestCommonAncestor(root->left, x, y);
    int rightAns = lowestCommonAncestor(root->right, x, y);

    if (leftAns != -1 && rightAns != -1)
        return root->data;

    else if (leftAns != -1 && rightAns == -1)
        return leftAns;

    else if (leftAns == -1 && rightAns != -1)
        return rightAns;

    else
        return -1;
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
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
    cout << lowestCommonAncestor(root, x, y);
    return 0;
}