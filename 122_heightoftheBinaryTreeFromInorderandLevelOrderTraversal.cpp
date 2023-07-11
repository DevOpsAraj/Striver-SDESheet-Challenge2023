// Code Studio - Height of the Binary Tree From Inorder and Level Order Traversal

#include <bits/stdc++.h>
using namespace std;

class Temp
{
public:
    int height;
    int leftIndex;
    int rightIndex;

    Temp(int h, int li, int ri)
    {
        height = h;
        leftIndex = li;
        rightIndex = ri;
    }
};

int heightOfTheTree(vector<int> &inorder, vector<int> &levelOrder, int N)
{
    int maxHeight = 0;
    queue<Temp> q;

    if (N >= 1)
    {
        Temp temp(0, 0, N - 1);
        q.push(temp);
    }
    unordered_map<int, int> map;
    for (int i = 0; i < N; i++)
    {
        map[inorder[i]] = i;
    }

    for (int i = 0; i < N; i++)
    {
        Temp temp = q.front();
        q.pop();

        maxHeight = max(temp.height, maxHeight);

        int li = temp.leftIndex;
        int ri = temp.rightIndex;
        int rootIndex;

        rootIndex = map[levelOrder[i]];

        if (rootIndex - 1 >= li)
        {
            Temp leftSubTree(temp.height + 1, li, rootIndex - 1);
            q.push(leftSubTree);
        }

        if (rootIndex + 1 <= ri)
        {
            Temp rightSubTree(temp.height + 1, rootIndex + 1, ri);
            q.push(rightSubTree);
        }
    }

    return maxHeight;
}

int main()
{
    int N;
    cin >> N;
    vector<int> inorder(N), levelOrder(N);
    for (int i = 0; i < N; i++)
        cin >> inorder[i];
    for (int i = 0; i < N; i++)
        cin >> levelOrder[i];
    cout << heightOfTheTree(inorder, levelOrder, N) << endl;
    return 0;
}