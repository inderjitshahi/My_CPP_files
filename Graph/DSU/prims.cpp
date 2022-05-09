#include <bits/stdc++.h>
using namespace std;

class graph
{
    vector<pair<int, int>> *l; // 1->(a1, w1),(a2,w1),...
    int V;

public:
    graph(int V)
    {
        this->V = V;
        l = new vector<pair<int, int>>[V];
    }
    void addEdge(int x, int y, int wt)
    {
        // undirected Graph
        l[x].push_back({y, wt});
        l[y].push_back({x, wt});
    }
    int prims()
    {
        // min-heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

        // another array mst
        bool *visited = new bool[V]{0};
        int ans = 0;

        // begin
        Q.push({0, 3}); //{wt,node};  as comparision is on wt , pushing source node with wt 0

        while (!Q.empty())
        {
            auto best = Q.top();
            Q.pop();
            int to = best.second;
            int wt = best.first;

            if (visited[to])
            {
                continue;
            }
            ans += wt;
            visited[to] = true;

            // add new edges to the queue
            for (auto x : l[to])
            {
                if (visited[x.first] == 0)
                {
                    Q.push({x.second, x.first});
                }
            }
        }
        return ans;
    }
};

int main()
{
    graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(3, 2, 3);
    g.addEdge(2, 0, 2);
    g.addEdge(0, 2, 2);
    g.addEdge(0, 3, 2);
    cout << g.prims();
    return 0;
}