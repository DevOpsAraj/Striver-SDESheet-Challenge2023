// Code Studio - Serialize and Deserialize Binary Tree

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

string serializeTree(Node *root)
{
    if (root == NULL)
        return "";

    queue<Node *> q;
    string s = "";
    q.push(root);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node == NULL)
            s.append("#,");
        else
            s.append(to_string(node->data) + ',');

        if (node != NULL)
        {
            q.push(node->left);
            q.push(node->right);
        }
    }
    return s;
}

Node *deserializeTree(string &data)
{
    if (data.size() == 0)
        return NULL;

    stringstream s(data);
    string str;

    getline(s, str, ',');
    Node *root = new Node(stoi(str));

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        getline(s, str, ',');
        if (str == "#")
            node->left = NULL;
        else
        {
            Node *leftNode = new Node(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }

        getline(s, str, ',');
        if (str == "#")
            node->right = NULL;
        else
        {
            Node *rightNode = new Node(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);

    string s = serializeTree(root);
    cout << s << endl;

    Node *newRoot = deserializeTree(s);
    cout << newRoot->data << endl;
    cout << newRoot->left->data << endl;
    cout << newRoot->right->data << endl;

    return 0;
}