// Code Studio - BST Iterator

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

class BSTiterator
{
    stack<Node *> st;

public:
    BSTiterator(Node *root)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }

    int next()
    {
        Node *top = st.top();
        st.pop();

        Node *temp = top->right;

        while (temp)
        {
            st.push(temp);
            temp = temp->left;
        }

        return top->data;
    }

    bool hasNext()
    {
        return (!st.empty());
    }
};

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);

    root->left->left = new Node(2);
    root->left->right = new Node(4);

    root->right->right = new Node(7);

    BSTiterator it(root);

    while (it.hasNext())
    {
        cout << it.next() << " ";
    }

    return 0;
}