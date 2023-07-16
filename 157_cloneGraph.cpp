// Code Studio - Clone Graph

#include <bits/stdc++.h>
using namespace std;

class graphNode
{
public:
    int data;
    vector<graphNode *> nbr;
    graphNode()
    {
        data = 0;
        nbr = vector<graphNode *>();
    }

    graphNode(int val)
    {
        data = val;
        nbr = vector<graphNode *>();
    }

    graphNode(int val, vector<graphNode *> nbr)
    {
        data = val;
        this->nbr = nbr;
    }
};

graphNode *cloneGraph(graphNode *node)
{
    graphNode *cpyNode;
    unordered_map<graphNode *, graphNode *> mp;
    if (node)
    {
        cpyNode = new graphNode(node->data);
        mp[node] = cpyNode;
    }
    queue<graphNode *> q;
    q.push(node);

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();

        for (auto nb : temp->nbr)
        {
            if (mp.find(nb) == mp.end())
            {
                graphNode *c = new graphNode(nb->data);
                mp[nb] = c;
                q.push(nb);
            }
            mp[temp]->nbr.push_back(mp[nb]);
        }
    }

    return cpyNode;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<graphNode *> nodes(n, NULL);
    for (int i = 0; i < n; i++)
    {
        nodes[i] = new graphNode(i + 1);
    }
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        nodes[u - 1]->nbr.push_back(nodes[v - 1]);
        nodes[v - 1]->nbr.push_back(nodes[u - 1]);
    }

    graphNode *cpy = cloneGraph(nodes[0]);
    for (auto nb : cpy->nbr)
    {
        cout << nb->data << " ";
    }
    cout << endl;
    return 0;
}