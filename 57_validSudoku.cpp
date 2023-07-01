// Code Studio - Valid Sudoku

#include <bits/stdc++.h>
using namespace std;

bool check(int mat[9][9], int no, int i, int j)
{

    for (int k = 0; k < 9; k++)
    {
        if (mat[i][k] == no || mat[k][j] == no)
        {
            return false;
        }
    }

    int si = i - i % 3;
    int sj = j - j % 3;
    for (int i = si; i < si + 3; i++)
    {
        for (int j = sj; j < sj + 3; j++)
        {
            if (mat[i][j] == no)
            {
                return false;
            }
        }
    }
    return true;
}
bool solveSudoku(int board[9][9], int i, int j)
{
    if (i == 9)
        return true;
    if (j == 9)
        return solveSudoku(board, i + 1, 0);
    if (board[i][j] != 0)
        return solveSudoku(board, i, j + 1);

    for (int c = 1; c <= 9; c++)
    {
        if (check(board, c, i, j) == true)
        {
            board[i][j] = c;
            if (solveSudoku(board, i, j + 1) == true)
                return true;
            board[i][j] = 0;
        }
    }

    return false;
}
bool isItSudoku(int matrix[9][9])
{
    if (solveSudoku(matrix, 0, 0) == true)
    {
        return true;
    }
    return false;
}
int main()
{
    int matrix[9][9];
    for (int i = 0; i < 9; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 9; j++)
        {
            matrix[i][j] = s[j] - '0';
        }
    }
    if (isItSudoku(matrix))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}