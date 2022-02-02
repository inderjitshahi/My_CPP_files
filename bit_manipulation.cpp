#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define int long long
#define ull unsigned long long
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

int getBit(int n, int i)
{
    int mask = (1 << i);
    return (n & mask) > 0 ? 1 : 0;
}
int setBit(int n, int i)
{
    int mask = (1 << i);
    return (n | mask);
}
int clearBit(int n, int i)
{
    int mask = ~(1 << i);
    return (n & mask);
}
int updateBit(int &n, int i, int v)
{
    int mask = ~(1 << i);
    int cleared_n = n & mask;
    mask = (v << i);
    return (n | mask);
}
int clearLastIBit(int n, int i)
{
    int mask = -1 << i;
    return n & mask;
}
int clearRangeItoJ(int n, int j, int i)
{
    int ones = ~0;
    int b = ones << (j + 1);
    int a = (1 << i) - 1;
    int mask = a | b;
    return n & mask;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int n=gen<int>();
    uint32_t n = 1;
    cout << getBit(n, 32) << endl; // clearing last two bits 1111  ->1100 i.e. 15 to 12

    // cout<<(n>>31);
    // cout<<(~0);
    return 0;
}