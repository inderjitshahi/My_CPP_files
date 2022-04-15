#include <bits/stdc++.h>
using namespace std;
class graph
{
    list<int> *l;
    int V;

public:
    graph(int v)
    {
        this->V = v;
        l = new list<int>[v];
    }
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void print()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "node " << i << "-> ";
            for (auto node : l[i])
            {
                cout << node << ", ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    bool bipartiteHelper(int *visited, int *set, int node, int parent)
    {

        if (set[parent] == 1)
            set[node] = 2;
        else
            set[node] = 1;
        for (auto nbr : l[node])
        {
            if (set[nbr] == set[node]) // nbr is visited but  not parent, i.e. cycle present
            {
                return false;
            }
            else if (set[nbr] == 0)
            {
                bool cycyle_mila = bipartiteHelper(visited, set, nbr, node);
                if (cycyle_mila == false)
                    return false;
            }
        }

        return true;
    }
    void bipartite()
    {
        int set[V] = {0};
        int visited[V] = {0};
        if (!bipartiteHelper(visited, set, 0, 0))
            cout << "Not Bipartite graph";
        else
            cout << " Bipartite Graph !!!";
    }
    // void bfsHelper(int src,queue<int>&q,int *visited,int &minD,vector<int>&dist){

    // }
    void bfs(int src, int &minD)
    {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        // int visited[V] = {0};
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto nbr : l[node])
            {
                if (dist[nbr] == INT_MAX)
                {
                    dist[nbr] = 1 + dist[node];
                    // visited[nbr] = 1;
                    q.push(nbr);
                }
                else if(dist[nbr]>=dist[node])  //cheking for back-edge
                {
                    minD=min(minD,dist[nbr]+1+dist[node]);
                }
            }
        }
    }
};

int main()
{
    graph g(9);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 5);
    g.addEdge(4, 2);
    g.addEdge(4, 6);
    g.addEdge(5, 6);
    g.addEdge(5, 7);
    g.addEdge(6, 8);
    g.addEdge(7, 8);
    // g.addEdge(2, 0);
    g.print();
    int minD=INT_MAX;
    for(int i=0;i<9;i++){
         g.bfs(i,minD);
    }
    
    cout<<minD;
    return 0;
}