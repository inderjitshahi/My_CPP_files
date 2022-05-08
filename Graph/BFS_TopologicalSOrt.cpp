#include <bits/stdc++.h>
using namespace std;

class graph
{
    int V;
    list<int> *l;

public:
    graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int x, int y)
    {
        l[x].push_back(y); // dircted Graph
    }

    void bfs()
    {
        // indegree
        queue<int> q;
        int *indegree = new int[V]{0};
        // update indegree by traversing x->y
        // indegree[y]++
        for (int i = 1; i < V; i++)
        {
            for (auto y : l[i])
            {
                indegree[y]++;
            }
        }
        // bfs
        // 1. find node with indegree 0
        for (int i = 1; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        //start removing elelmets from quque
        while(!q.empty()){
            int node =q.front();
            cout<<node<<" ";
            q.pop();
            for(auto nbr:l[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0) q.push(nbr);
            }
        }
    }
    void printAdjList();
};
void graph ::printAdjList()
{
    for (int i = 1; i < V; i++)
    {
        cout << "node " << i << "-> ";
        for (auto x : l[i])
        {
            cout << "(" << (x) << ") ";
        }
        cout << "\n";
    }
}
int main()
{
    graph g(7);
    g.addEdge(1, 2);
    g.addEdge(2, 1);
    g.addEdge(2, 5);
    g.addEdge(3, 4);
    g.addEdge(3, 6);
    g.addEdge(5, 6);
    cout << "Adjancy List is:\n";
    g.printAdjList();
    cout << "\nTopological Sort is:\n";
    g.bfs();
    return 0;
}