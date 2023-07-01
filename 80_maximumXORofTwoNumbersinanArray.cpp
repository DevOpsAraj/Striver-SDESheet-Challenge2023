// Code Studio - Maximum XOR of Two Numbers in an Array

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *child[2];
    Node(int data)
    {
        this->data = data;
        for (int i = 0; i < 2; i++)
        {
            child[i] = NULL;
        }
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node('\0');
    }
    void insert(int num)
    {
        Node *prev = root;
        for (int i = 31; i >= 0; i--)
        { // inserting a 32 bit integer starting from the
            int bit = (num >> i) & 1;
            Node *child;
            if (prev->child[bit] == NULL)
            {
                child = new Node(bit);
                prev->child[bit] = child; // pushes the bit at 0 if bit is 0, 1 if the bit is 1
            }
            else
            {
                child = prev->child[bit];
            }
            prev = child;
        }
    }

    int find_max(int num)
    {
        int val = 0;
        Node *prev = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            Node *child;
            if (bit & 1)
            { // means the bit is 1
                if (prev->child[0])
                {                           // check for 0 bit
                    child = prev->child[0]; // put child on the 0th bit to maximize answer
                    val = val | (1 << i);
                }
                else
                {
                    child = prev->child[1];
                }
            }
            else
            { // bit is 0
                if (prev->child[1])
                {
                    child = prev->child[1];
                    val = val | (1 << i);
                }
                else
                {
                    child = prev->child[0];
                }
            }
            prev = child;
        }
        return val;
    }
};

int maximumXor(vector<int> A)
{
    Trie t;
    for (int i = 0; i < A.size(); i++)
    {
        t.insert(A[i]);
    }
    int ans = 0;
    int val = 0;
    for (int i = 0; i < A.size(); i++)
    {
        val = t.find_max(A[i]);
        ans = max(ans, val);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << maximumXor(A) << endl;
    return 0;
}