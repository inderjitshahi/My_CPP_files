// Implenting DSU data structure
#include <bits/stdc++.h>
using namespace std;

class graph
{
    int V;
    list<pair<int, int>> edgeList;

public:
    graph(int V)
    {
        this->V = V;
    }
    void addEdge(int x, int y)
    {
        edgeList.push_back(make_pair(x, y));
    }
    // Find
    int findSet(int i, int *parent)
    {
        /*************** Standard approach  ************/
        // if (parent[i] == -1)
        //     return i;
        // return findSet(parent[i], parent);

        /*************** Path comlression optimisation  ************/

        if (parent[i] == -1)
            return i;
        return parent[i] = findSet(parent[i], parent);
    }

    // union
    void UnionSet(int x, int y, int *parent,int *rank)
    {
        /*************** Standard Appraoch  ************/
        // int s1 = findSet(x, parent);
        // int s2 = findSet(y, parent);
        // if (s1 != s2)
        //     parent[s2] = s1;
        /*************** Union by rank  ************/
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);
        if (s1 != s2){
            if(rank[s1]<rank[s2]){
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            }
            else{
                 parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
        }


    }
    bool containsCycle()
    {
        // DSU logic to check for cycle
        int parent[V];
        int *rank=new int[V];
        for (int i = 0; i < V + 1; i++)
        {
            parent[i] = -1;
            rank[i]=1;
        }
        for (auto edge : edgeList)
        {

            int i = edge.first;
            int j = edge.second;

            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);
            if (s1 != s2)
                UnionSet(s1, s2, parent,rank);
            else
            {
                cout << "Same parent: " << s1 << " of ( " << i << " and " << j << " )";
                return true;
            }
        }
        cout << "No Cycle";
        return false;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.containsCycle();
    return 0;
}