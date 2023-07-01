// Code Studio - Left View of Binary Tree

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Iterative Solution
void leftView(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();

        for (int i = 1; i <= n; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (i == 1)
                cout << temp->data << " ";

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}

// Recursive Solution
void solve(Node *root, vector<int> &res, int lvl)
{
    if (root == NULL)
        return;

    if (res.size() == lvl)
        res.push_back(root->data);

    solve(root->left, res, lvl + 1);
    solve(root->right, res, lvl + 1);
}
vector<int> getLeftView(Node *root)
{
    vector<int> res;
    solve(root, res, 0);
    return res;
}

int main()
{
    Node *root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);

    root->left->left = newNode(40);
    root->left->right = newNode(60);

    root->right->left = newNode(90);
    root->right->right = newNode(100);

    leftView(root);
    cout << endl;

    vector<int> res = getLeftView(root);
    for (int x : res)
        cout << x << " ";
    cout << endl;

    return 0;
}