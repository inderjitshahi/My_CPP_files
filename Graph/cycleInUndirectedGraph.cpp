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
   bool  bipartiteHelper(int *visited, int node, int parent)
    {

            visited[node] = 1;
            for (auto nbr : l[node])
            {
                if (visited[nbr] != 1){
                        bool cycyle_mila=  bipartiteHelper(visited, nbr, node);
                        if(cycyle_mila) return true;
                }
                  
                else if ( nbr != parent)  //nbr is visited but  not parent, i.e. cycle present
                {
                    return true;
                }
                
            }
        
        return false;
    }
    void detectCycle()
    {
        int visited[V] = {0}; 
       if( bipartiteHelper(visited, 0, 0)) cout<<"cycle is presnt";
        else cout<<"cycle Not present!!!";
    }
};

int main()
{
    graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    // g.addEdge(2, 0);
    g.print();
    g.detectCycle();
    return 0;
}