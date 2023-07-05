// Code Studio - Bottom View Of Binary Tree

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

vector<int> bottomView(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        Node *temp = q.front().first;
        int h = q.front().second;
        q.pop();

        mp[h] = temp->data;

        if (temp->left)
            q.push({temp->left, h - 1});
        if (temp->right)
            q.push({temp->right, h + 1});
    }

    for (auto x : mp)
        ans.push_back(x.second);

    return ans;
}

int main()
{
    int n;
    cin >> n;
    Node *root = NULL;
    queue<Node *> q;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (root == NULL)
        {
            root = newNode(a);
            q.push(root);
        }
        else
        {
            Node *temp = q.front();
            if (temp->left == NULL)
            {
                temp->left = newNode(a);
                q.push(temp->left);
            }
            else
            {
                temp->right = newNode(a);
                q.push(temp->right);
                q.pop();
            }
        }
    }

    vector<int> ans = bottomView(root);
    for (auto x : ans)
        cout << x << " ";

    return 0;
}