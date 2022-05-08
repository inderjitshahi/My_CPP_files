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
    void bfs(T src)
    {
        map<T, bool> visited; // tracking record of visited or not
        queue<T> q;           // queue for BFS
        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            cout << node << " ";
            for (auto nbr : m[node]) // visiting all the nbr of present node
            {
                if (!visited[nbr]) // if neighbour is not visited
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
    void singleShortestpath(T src)
    {
        map<T, int> dist; // tracking record of visited or not
        queue<T> q;       // queue for BFS

        // Assume all  nodes have distanece int_max
        for (auto node_pair : m)
        {                             // visiting every node of AdyList
            T node = node_pair.first; // node_pair= map<T,list<T>>;
            dist[node] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0; // src has distance 0 from itself
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            // cout << node << " ";
            for (auto nbr : m[node]) // visiting all the nbr of present node
            {
                if (dist[nbr] == INT_MAX) // if neighbour is not visited
                {
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                }
            }
        }
        for (auto node_pair : m)
        {
            T node = node_pair.first;
            int d = dist[node];
            cout << "Distance of Node " << node << " from source is: " << d << "\n";
        }
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
};

int32_t main()
{
    graph<int> g(6);
    g.addEdge(0, 3);
    g.addEdge(0, 1);
    g.addEdge(3, 2);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    cout<<"The AdjList: \n";
    g.printAdjList();
    g.singleShortestpath(0);

   
    return 0;
}