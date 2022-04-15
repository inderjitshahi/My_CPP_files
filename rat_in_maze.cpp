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
int countNumber = 0;
bool ratInMaze(char maze[10][10], int solution[10][10], int i, int j, int m, int n)
{
    // Base case
    if (i == m && j == n)
    { // reched the destination
        solution[m][n] = 1;
        // print the path
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                cout << solution[i][j];
            }
            cout << endl;
        }
        cout << endl;
        countNumber += 1;
        return true; // path found
    }

    if (i > m || j > n)
        return false; // rat should be inside maze
    if (maze[i][j] == 'X')
        return false;
    // Recursive Case
    solution[i][j] = 1; // assuming that path exist
    // At right
    bool rightSuccess = ratInMaze(maze, solution, i, j + 1, m, n);
    // At downward
    bool downSuccess = ratInMaze(maze, solution, i + 1, j, m, n);

    // Bactracking
    solution[i][j] = 0;

    if (rightSuccess || downSuccess)
        return true;
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char maze[10][10] = {
        "0000",
        "00X0",
        "000X",
        "0x00"};
    int solution[10][10] = {0};
    bool ans = ratInMaze(maze, solution, 0, 0, 3, 3);
    if (ans)
        cout << "path exist!" << endl;
    cout << "Numner of Paths: " << countNumber;
    return 0;
}