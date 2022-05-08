#include <bits/stdc++.h>
using namespace std;

class graph
{
    int V;        // #vertices
    list<int> *l; // variable array of lists
public:
    graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y); // directed graph
    }

    bool cycleHelper(int node, int *visited, int *stack)
    {
        visited[node] = 1;
        stack[node] = 1;

        for (auto nbr : l[node])
        {
            // two cases
            if (stack[nbr] == 1) // if nbr is present in current path then cycle is present
                return true;

            else if (visited[nbr] == 0)
            {
                bool cycleMila = cycleHelper(nbr, visited, stack);
                if (cycleMila)
                    return true;
            }
        }

        // leaving a node, remove from current path
        stack[node] = 0;
        return false;
    }

    bool containsCycle()
    {
        int visited[V] = {0};
        int stack[V] = {0};
        return cycleHelper(0, visited, stack);
    }

    void printAdjList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "node " << i << "-> ";
            for (auto x : l[i])
            {
                cout << "(" << (x) << ") ";
            }
            cout << "\n";
        }
    }
};

int32_t main()
{
    graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(1, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 2);

    cout << "The AdjList: \n";
    g.printAdjList();

    cout << "\nTopological Soting is:\n";
    if (g.containsCycle())
        cout << "Have Cycle!!";
    else
        cout << "No Cycle!!";
    return 0;
}