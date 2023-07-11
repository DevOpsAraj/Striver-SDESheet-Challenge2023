// Code Studio - Check Identical Trees

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

bool isIdentical(Node *root1, Node *root2)
{
    if (root1 && root2)
    {
        return root1->data == root2->data &&
               isIdentical(root1->left, root2->left) &&
               isIdentical(root1->right, root2->right);
    }
    return root1 == root2;
}

int main()
{
    int n1;
    cin >> n1;
    Node *root1 = NULL;
    queue<Node *> q1;
    for (int i = 0; i < n1; i++)
    {
        int data;
        cin >> data;
        Node *temp = new Node(data);
        if (root1 == NULL)
            root1 = temp;
        else
        {
            Node *f = q1.front();
            if (f->left == NULL)
                f->left = temp;
            else
            {
                f->right = temp;
                q1.pop();
            }
        }
        q1.push(temp);
    }

    int n2;
    cin >> n2;
    Node *root2 = NULL;
    queue<Node *> q2;
    for (int i = 0; i < n2; i++)
    {
        int data;
        cin >> data;
        Node *temp = new Node(data);
        if (root2 == NULL)
            root2 = temp;
        else
        {
            Node *f = q2.front();
            if (f->left == NULL)
                f->left = temp;
            else
            {
                f->right = temp;
                q2.pop();
            }
        }
        q2.push(temp);
    }

    cout << boolalpha << isIdentical(root1, root2) << endl;
    return 0;
}