// Code Studio - Maximum Width In Binary Tree

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->left = this->right = NULL;
        this->data = val;
    }
};

int getMaxWidth(Node *root)
{
    if (root == NULL)
        return 0;

    queue<Node *> q;
    int ans = INT_MIN;

    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        ans = max(ans, size);

        while (size--)
        {
            Node *frontNode = q.front();
            q.pop();

            if (frontNode->left)
                q.push(frontNode->left);
            if (frontNode->right)
                q.push(frontNode->right);
        }
    }
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

    cout << getMaxWidth(root) << endl;

    return 0;
}