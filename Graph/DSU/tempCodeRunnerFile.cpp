#include <bits/stdc++.h>
using namespace std;

// DSU data structure
class DSU
{
    int *parent;
    int *rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++)
        {
            rank[i] = 1;
            parent[i] = -1;
        }
    }

    int Find(int i)
    {
        if (parent[i] == -1)
            return i;
        return parent[i] = Find(parent[i]);
    }
    void Union(int x, int y)
    {
        int s1 = Find(x);
        int s2 = Find(y);
        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class graph
{
    vector<vector<int>> edgelist;
    int V;

public:
    graph(int V)
    {
        this->V = V;
    }
    void addEdge(int x, int y, int wt)
    {
        edgelist.push_back({wt, x, y}); // wt first as sorting to done on the basis of wt
    }
    int kruskal()
    {
        // step 1: sort
        sort(edgelist.begin(), edgelist.end());

        // Initialize DSU
        DSU s(V);
        int ans = 0;
        for (auto edge : edgelist)
        {
            int wt = edge[0];
            int x = edge[1];
            int y = edge[2];
            // take that edge in mst if not form a cycle
            if (s.Find(x) != s.Find(y))
            {
                s.Union(x, y);
                cout<<"edge "<<x<<" and "<<y<<",\n";
                ans += wt;
            }
        }
        return ans;
    }
};

int main()
{
    graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 3, 3);
    g.addEdge(3, 2, 4);
    g.addEdge(2, 0, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 5);
    long long cost=g.kruskal();
    cout << "cost of MST is: "<<cost<<"\n";
    return 0;
}