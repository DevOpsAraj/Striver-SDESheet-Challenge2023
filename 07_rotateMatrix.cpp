// Code Studio - Rotate Matrix

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    if (n == 1 || m == 1)
        return;
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    while (top < bottom && left < right)
    {
        int temp = mat[left][top];

        for (int i = top; i < bottom; i++)
            mat[i][left] = mat[i + 1][left];

        for (int i = left; i < right; i++)
            mat[bottom][i] = mat[bottom][i + 1];

        for (int i = bottom; i > top; i--)
            mat[i][right] = mat[i - 1][right];

        for (int i = right; i > left + 1; i--)
            mat[top][i] = mat[top][i - 1];

        mat[top][left + 1] = temp;
        top++, bottom--, left++, right--;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> mat[i][j];
    rotateMatrix(mat, n, m);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    return 0;
}