// Code Studio - Search in Matrix

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int n = mat.size();
    int m = mat[0].size();

    int low = 0, high = n * m - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (mat[mid / m][mid % m] == target)
        {
            return true;
        }
        else if (mat[mid / m][mid % m] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main()
{
    int n, m, target;
    cin >> n >> m >> target;

    vector<vector<int>> mat(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    if (searchMatrix(mat, target))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}