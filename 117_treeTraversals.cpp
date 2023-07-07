// Code Studio - Tree Traversals

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

// Inorder Traversal
void inOrder(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}

// PreOrder Traversal
void preOrder(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    ans.push_back(root->data);
    preOrder(root->left, ans);
    preOrder(root->right, ans);
}

// PostOrder Traversal
void postOrder(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    postOrder(root->left, ans);
    postOrder(root->right, ans);
    ans.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(Node *root)
{
    vector<vector<int>> ans(3);
    vector<int> inorder;
    inOrder(root, inorder);

    vector<int> preorder;
    preOrder(root, preorder);

    vector<int> postorder;
    postOrder(root, postorder);

    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);
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

    vector<vector<int>> ans = getTreeTraversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}