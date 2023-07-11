// Code Studio - Binary Tree Zigzag Traversal

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

vector<int> zigZagTraversal(Node *root)
{
    vector<int> result;
    queue<Node *> q;

    bool leftToRight = true;

    if (root == NULL)
        return result;

    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        vector<int> sub(n);
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();

            int index = leftToRight ? i : n - i - 1;
            sub[index] = curr->data;

            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }

        leftToRight = !leftToRight;
        for (auto i : sub)
            result.push_back(i);
    }
    return result;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    vector<int> result = zigZagTraversal(root);
    for (auto i : result)
        cout << i << " ";
    cout << endl;
    return 0;
}
