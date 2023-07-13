// Code Studio - Connect Nodes at Same Level

#include <bits\stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right, *nextRight;
    Node(int x)
    {
        data = x;
        left = right = nextRight = NULL;
    }
};

void connectNodes(Node *root)
{
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            auto p = q.front();
            q.pop();

            p->nextRight = n ? q.front() : NULL;
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);

    connectNodes(root);

    return 0;
}