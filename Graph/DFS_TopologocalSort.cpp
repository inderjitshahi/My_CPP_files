#include <bits/stdc++.h>
using namespace std;

template <class T>
T gen()
{
    T x;
    cin >> x;
    return x;
}

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
        m[x].push_back(y); // directed graph
    }

    void dfsHelper(T src, map<T, bool> &visited, list<T> &ordering)
    {
        // Recursive function to traverse the graph

        visited[src] = true;
        // go to all next non-visited node
        for (auto nbr : m[src])
        {
            if (!visited[nbr])
            {
                dfsHelper(nbr, visited, ordering);
            }
        }
        ordering.push_front(src);
        return;
    }
    void dfs()
    {
        map<T, bool> visited;
        list<T> ordering;

        // mark all the node non-visited;
        for (auto node : m)
        {
            visited[node.first] = false;
        }

        // calling dfs for each node so that no independent node may left out
        for (auto node : m)
        {
            if (!visited[node.first])
            {
                dfsHelper(node.first, visited, ordering);
            }
        }
        for(auto node:ordering) cout<<node<<" -> ";
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
    graph<string> g(9);
    g.addEdge("python", "dataprocessing");
    g.addEdge("python", "pyTorch");
    g.addEdge("python", "ML");
    g.addEdge("dataprocessing", "ML");
    g.addEdge("pyTorch", "DL");
    g.addEdge("ML", "DL");
    g.addEdge("DL", "FaceRecognition");
    g.addEdge("Dataset", "FaceRecognition");

    cout << "The AdjList: \n";
    g.printAdjList();

    cout<<"\nTopological Soting is:\n";
    g.dfs();
    return 0;
}