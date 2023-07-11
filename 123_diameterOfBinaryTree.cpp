// Code Studio - Diameter Of Binary Tree

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

pair<int, int> solve(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> L = solve(root->left);
    pair<int, int> R = solve(root->right);

    int op1 = L.first;
    int op2 = R.first;
    int op3 = L.second + R.second + 1;
    int k = max(op1, op2);

    pair<int, int> ans;
    ans.first = max(op3, k);
    ans.second = max(L.second, R.second) + 1;
    return ans;
}

int diameterOfBinaryTree(Node *root)
{
    pair<int, int> ans = solve(root);
    int diameter = ans.first;
    return diameter - 1;
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
            Node *front = q.front();
            if (front->left == NULL)
                front->left = temp;
            else if (front->right == NULL)
                front->right = temp;
            if (front->left != NULL && front->right != NULL)
                q.pop();
        }
        q.push(temp);
    }
    cout << diameterOfBinaryTree(root) << endl;
    return 0;
}