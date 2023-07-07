// Code Studio - Vertical Order Traversal

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

vector<int> verticalOrderTraversal(Node *root)
{
    if (root == NULL)
        return {};

    vector<int> ans;
    queue<pair<Node *, int>> q;
    map<int, vector<int>> mp;

    q.push({root, 0});
    mp[0].push_back(root->data);

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int dis = temp.second;

        if (frontNode->left)
        {
            q.push({frontNode->left, dis - 1});
            mp[dis - 1].push_back(frontNode->left->data);
        }

        if (frontNode->right)
        {
            q.push({frontNode->right, dis + 1});
            mp[dis + 1].push_back(frontNode->right->data);
        }
    }

    for (auto it : mp)
    {
        for (auto i : it.second)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(7);
    root->right = new Node(4);
    root->left->left = new Node(3);
    root->left->right = new Node(11);
    root->right->left = new Node(14);
    root->right->right = new Node(6);

    vector<int> ans = verticalOrderTraversal(root);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}