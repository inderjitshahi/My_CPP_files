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

template <class T>
class graph
{
    int V;             // #vertices
    map<T, list<T>> m; // hash-map for adjList
    // list<int> *l;  //variable array of lists
public:
    graph(int V)
    {
        this->V = V;
    }

    void addEdge(T x, T y)
    {
        m[x].push_back(y); // assuming un-directed graph
        m[y].push_back(x);
    }
    void dfsHelper(T src, map<T, bool> &visited)
    {
        // Recursive function to traverse the graph

        cout<<src<<"\n";
        visited[src] = true;
        // go to all next non-visited node
        for (auto nbr : m[src])
        {
            if (!visited[nbr])
            {
                dfsHelper(nbr, visited);
            }
        }
    }
    void dfs(T src)
    {
        map<T, bool> visited;
        // mark all the node non-visited;
        for (auto p : m)
            visited[p.first] = false;
        dfsHelper(src, visited);
    }
    void printAdjList()
    {
        for (auto p : m)
        {
            T city = p.first;
            list<T> nbrs = p.second;
            cout << "node " << city << "-> ";
            for (auto x : nbrs)
            {
                cout << "(" << (x) << ") ";
            }
            cout << "\n";
        }
    }
    void countConnected()
    {
        map<T, bool> visited;
        // mark all the node non-visited;
        for (auto p : m)
            visited[p.first] = false;
        // itereate over all the vertices and init a dfs
        int count=1;
        for (auto p : m)
        {
            T node = p.first; 
            if (!visited[node])
            {
                
                cout<<"Component "<<count<<" -->\n";
                dfsHelper(node, visited);
                count+=1;
            }
        }
    }
};

int32_t main()
{
    graph<int> g(6);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    // g.addEdge(2, 3);
    // g.addEdge(0, 3);
    // g.addEdge(0, 4);

    // g.addEdge(5, 6);
    // g.addEdge(6, 7);

    // g.addEdge(8, 8);

    cout << "The AdjList: \n";
    g.printAdjList();
    g.countConnected();

    return 0;
}