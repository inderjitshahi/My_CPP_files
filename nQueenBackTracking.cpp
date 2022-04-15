#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define flase false
#define sz(x) ((int)x.size())
#define pii pair<int, int>
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
template <class T>
T gen()
{
    T x;
    cin >> x;
    return x;
}
template <class T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag,
                  tree_order_statistics_node_update>;
bool isSafe(int board[][100], int i, int j, int n)
{
    // check for col
    for (int row = 0; row < i; row++)
    {
        if (board[row][j] == 1)
            return false;
    }

    // check for upper left diagonal as lower part is yet to be filled
    int x = i, y = j;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        x--;
        y--;
    }

    // check for upper right dig. as lower part is yet to be filled
    x = i, y = j;
    while (x >= 0 && y < n)
    {
        if (board[x][y] == 1)
            return false;
        x--;
        y++;
    }
    // No need to check for row, as in present row , yet to be filed
    return true;
}
bool solveNQueen(int board[][100], int i, int n)
{
    // Base Case
    if (i == n)  //if reached to nth row,i.e. all queens are placed
    {
        // Successfilly placed queens in n rows
        // Print the board
        for (int p = 0; p < n; p++)
        {
            for (int q = 0; q < n; q++)
            {
                if (board[p][q] == 1)
                    cout << "Q"<<" ";
                else
                    cout << "_"<<" ";
            }
            cout << endl;
        }
        cout<<endl;
        return false;  // Will continue to search for all remaining configurations
    }

    // Recurive Case
    // Try to place the queen on the current row and call recusion for remaining rows
    for (int j = 0; j < n; j++)
    {
        //Check if i,jth position is safe or not
        if (isSafe(board, i, j, n))
        {
            //Place the queen assuming right postion
            board[i][j] = 1;

            bool NextQueenCanBePlaced = solveNQueen(board, i + 1, n);
            if (NextQueenCanBePlaced)
            {
                return true;
            }
            //if not true, that means i and j are correct positions, so Backtrack
            board[i][j] = 0; // BackTrack
        }
    }
    return false;
}

int32_t main()
{
    int n;
    cout<<"enter size of board:";
    cin>>n;
    int board[100][100] = {0};
    solveNQueen(board, 0,n);
    return 0;
}