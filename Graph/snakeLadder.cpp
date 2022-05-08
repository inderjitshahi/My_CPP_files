#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;

template <class T>
class graph
{
    int V;
    map<T, list<T>> m;

public:
    graph(int V)
    {
        this->V = V;
    }

    void addEdge(T x, T y)
    {
        m[x].push_back(y); // directed graph
    }
    void singleShortestpath(T src, T dest)
    {
        map<T, int> dist;
        map<T,T>parent;
        queue<T> q;
        for (auto node_pair : m)
        {
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;
        parent[src]=src;
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            for (auto nbr : m[node])
            {
                if (dist[nbr] == INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                    parent[nbr]=node;
                }
            }
        }

        //path desti to src
        T temp=dest;
        while(temp!=src){
            cout<<temp<<"<--";
            temp=parent[temp];
        }
        cout<<src<<"\n";
        // Print distance of destination
        cout << "The shortest Distance of destination " << dest << " from source "<<src<<" is: " << dist[dest] << "\n";
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
    // Snake //Laders
    int board[50] = {0}; // if there is ladder at node '2' to node '15', board[2]=15-2=+13 JUMP. lly for sanake will will take care for each node.
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    graph<int> g(37);
    for (int i = 0; i <= 36; i++)
    {
        for (int dice = 1; dice <= 6; dice++)
        {
            int j = i + dice;
            j += board[j];
            if (j <= 36)
            {
                g.addEdge(i, j);
                // cout << "edge" << i << " to " << j << endl;
            }
        }
    }
    g.addEdge(36, 36);
    g.singleShortestpath(0, 36);
    // g.printAdjList();
    return 0;
}