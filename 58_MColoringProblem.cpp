// Code Studio - M Coloring Problem

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
bool isPossibleMthColor(vector<vector<int>> &mat,
                        vector<int> &node_color_vector, int node_to_colored,
                        int color, int n)
{

    for (int i = 0; i < n; i++)
    {
        if (mat[node_to_colored][i] == 1)
        {
            if (node_color_vector[i] == color)
            {
                return false;
            }
        }
    }

    node_color_vector[node_to_colored] = color;
    return true;
}

bool solve_graph(int node_to_colored, int n, int m,
                 vector<int> &node_color_vector, vector<vector<int>> &mat)
{
    if (node_to_colored == n)
    {
        return true;
    }

    for (int i = 1; i <= m; i++)
    {
        if (isPossibleMthColor(mat, node_color_vector, node_to_colored, i, n))
        {
            if (solve_graph(node_to_colored + 1, n, m, node_color_vector, mat))
            {
                return true;
            }

            node_color_vector[node_to_colored] = 0;
        }
    }

    return false;
}

string graphColoring(vector<vector<int>> &mat, int m)
{
    int n = mat.size();
    vector<int> node_color_vector(n, 0);

    if (solve_graph(0, n, m, node_color_vector, mat))
    {
        return "YES";
    }
    return "NO";
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    cout << graphColoring(mat, m) << endl;
    return 0;
}