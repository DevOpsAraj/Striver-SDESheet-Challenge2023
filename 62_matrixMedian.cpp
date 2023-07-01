// Code Studio - Matrix Median

#include <bits/stdc++.h>
using namespace std;

int getMedian(vector<vector<int>> &matrix)
{
    vector<int> line;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            line.push_back(matrix[i][j]);
        }
    }

    sort(line.begin(), line.end());
    int median = (line.size() / 2);

    return line[median];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    }

    cout << getMedian(matrix) << endl;
    return 0;
}