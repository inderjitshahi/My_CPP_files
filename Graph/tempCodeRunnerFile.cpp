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

class graph
{
    int V;
    list<pair<int, int>> *l;

public:
    graph(int v)
    {
        v = V;
        l = new list<pair<int, int>>[V];
    }
    void addEdge(int x, int y, int wt)
    {
        l[x].push_back(make_pair(y, wt));
        l[y].push_back(make_pair(x, wt));
    }
    int dfsHelper(int node, bool *visited, int *cnt, int &ans)
    {
        // mark the visit
        visited[node] = true;
        cnt[node] = 1;

        for (auto nbr_pair : l[node])
        {
            int wt = nbr_pair.second;
            int nbr = nbr_pair.first;
            if (!visited[nbr])
            {
                cnt[node] += dfsHelper(nbr, visited, cnt, ans);
                int nx = cnt[nbr];
                int ny = V - nx;
                ans += 2 * min(nx, ny) * wt;
            }
        }
        return cnt[node];
    };
    int dfs()
    {
        bool *visited = new bool[V]{false};
        int *count = new int[V]{0};
        int ans = 0;
        dfsHelper(0, visited, count, ans);
        return ans;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    graph g(4);
    g.addEdge(0, 1, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 2);
    cout << g.dfs() << endl;

    return 0;
}