//practiced connected components 
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
        l = new list<int>[V + 1];
    }
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void print()
    {
        for (int i = 1; i <= V; i++)
        {
            cout << "node " << i << " -> ";
            for (auto x : l[i])
                cout << x << ", ";
            cout << endl;
        }
        return;
    }
    void dfsHelper()
    {
    }
    void dfs(int src, int *visited)
    {
        cout<<src<<",";
        visited[src]=1;
        for(auto nbr:l[src]){
            if(visited[nbr]==0){
                dfs(nbr,visited);
            }
        }
    }
    void connected()
    {
        int visited[V + 1] = {0};
        int count = 1;
        for (int i = 1; i <= V; i++)
        {
            if (visited[i] == 0)
            {
                cout<<"Component "<<count<<" :";
                dfs(i, visited);
                cout<<endl;
                count++;
            }
        }
    }
};

int main()
{
    graph g(6);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(4, 6);
    g.addEdge(4, 5);
    g.print();
    g.connected();
    return 0;
}