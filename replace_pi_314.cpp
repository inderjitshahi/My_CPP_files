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

void replacePi(char *a, int i)
{
    // base case
    if (a[i] == '\0' || a[i + 1] == '\0')
        return;

    // recursive case
    int j = i + 2;
    if (a[i] == 'p' && a[i + 1] == 'i')
    {
        while (a[j] != '\0')
            j++;
        while (j >= i + 2)
        {
            a[j + 2] = a[j];
            j--;
        }
        a[i] = '3';
        a[i + 1] = '.';
        a[i + 2] = '1';
        a[i + 3] = '4';
        replacePi(a, i + 4);
    }
    else
    {
        replacePi(a, i + 1);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char a[1000] = "ksjdjkspincnpi";
    replacePi(a, 0);
    cout << a;
    return 0;
}