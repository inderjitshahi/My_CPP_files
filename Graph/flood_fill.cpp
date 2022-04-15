
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

// e w n s
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void fill(char mat[][20], int i, int j, char color, char ch, int r, int c)
{
    // matrix boundry
    if (i < 0 || j < 0 || i >= r || j >= c)
        return;

    // boundry condition
    if (mat[i][j] != ch)
        return;

    // Recursive call
    mat[i][j] = color;
    for (int k = 0; k < 4; k++)
    { // calling for all four directions recursively
        fill(mat, i + dx[k], j + dy[k], color, ch, r, c);
    }
}
void print_matrix(char mat[][20], int r, int c)
{
    cout<<"matrix is:\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << mat[i][j]<<" ";
        }
        cout<<endl;
    }
cout<<endl;

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    cin >> r >> c;
    char mat[20][20];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mat[i][j];
        }
    }
    print_matrix(mat, r, c);
    fill(mat, 2, 1, 'r', '.', r, c);
    fill(mat, 1, 0, 'g', '.', r, c);
    print_matrix(mat, r, c);
    return 0;
}