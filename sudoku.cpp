
#include <bits/stdc++.h>
using namespace std;

bool canPlace(int mat[][9], int i, int j, int n, int number)
{
    // checking for row and column
    for (int x = 0; x < n; x++)
    {
        if (mat[x][j] == number || mat[i][x] == number)
        {
            return false;
        }
    }
    // checking for sub-grid
    int rn = sqrt(n);
    int sx = (i / rn) * rn;
    int sy = (j / rn) * rn;
    // cout<<rn<<" "<<sx<<" "<<sy<<"\n";
    for (int x = sx; x < sx + rn; x++)
    {
        for (int y = sy; y < sy + rn; y++)
        {
            if (mat[x][y] == number)
            {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int mat[][9], int i, int j, int n)
{

    // Base Case
    if (i == n)
    { // n rows are completely filled, i.e. solution reached
      // print the matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        return true; // solution found
    }
    // Case for row end
    if (j == n)
    {
        return solveSudoku(mat, i + 1, 0, n); // to next row
    }

    // Skip the prefilled cells
    if (mat[i][j] != 0)
    {
        return solveSudoku(mat, i, j + 1, n); // move to next cell
    }
    // Recursive Case
    // fill the current cell with possible options
    for (int number = 1; number <= n; number++)
    {
        if (canPlace(mat, i, j, n, number))
        {
            mat[i][j] = number;
            bool correctPlaced = solveSudoku(mat, i, j + 1, n);
            if (correctPlaced == true)
            {
                return true;
            }
        }
    }
    // we have tried till 9 in the present cell, but not get correct sol, Backtrac here
    mat[i][j] = 0;
    return false;
}

int32_t main()
{

    int mat[9][9] = {
        {0, 0, 0, 0, 0, 0, 2, 0, 0},
        {6, 4, 0, 0, 2, 0, 0, 0, 0},
        {0, 7, 3, 4, 1, 0, 0, 8, 6},
        {0, 0, 0, 0, 0, 0, 9, 0, 8},
        {0, 8, 0, 6, 0, 1, 0, 4, 0},
        {1, 0, 2, 0, 0, 0, 0, 0, 0},
        {5, 6, 0, 0, 4, 3, 8, 2, 0},
        {0, 0, 0, 0, 6, 0, 0, 7, 5},
        {0, 0, 7, 0, 0, 0, 0, 0, 0}
    };
    bool ans= solveSudoku(mat, 0, 0, 9);
    if(!ans) cout<<"NO, No Solution exist";
    return 0;
}