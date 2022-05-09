#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> graph[], int i, int *visited, vector<int> &stack)
{
    visited[i] = 1;
    for (auto nbr : graph[i])
    {
        if (visited[nbr] == 0)
        {
            dfs(graph, nbr, visited, stack);
        }
    }
    stack.push_back(i);
    return;
}
void dfs2(vector<int> rev_graph[], int i, int *visited2)
{
    visited2[i] = 1;
    cout << i << " ";
    for (auto nbr : rev_graph[i])
    {
        if (visited2[nbr] == 0)
        {
            dfs2(rev_graph, nbr, visited2);
        }
    }
}

void solve(vector<int> graph[], vector<int> rev_graph[], int N)
{
    int visited[N] = {0};
    vector<int> stack ;

    // step-1 need to store the vertices acc. to dfs fifnish time
    for (int i = 0; i < N; i++)
    {
        if (visited[i] == 0)
        {
            dfs(graph, i, visited, stack);
        }
    }

    // ordering in  stack vector
    // step 2-> reverse

    // step-3 -> do dfs acc to ordering given in the stack
    int visited2[N] = {0};
    char component_name = 'A';
    for (int x = stack.size() - 1; x >= 0; x--)
    {
        int node = stack[x];
        if (visited2[node] == 0)
        {
            cout << "component " << component_name << "-> ";
            dfs2(rev_graph, node, visited2);
            cout << "\n";
            component_name++;
        }
    }
}

int main()
{

    int N;
    cin >> N;
    vector<int> graph[N]; // graph[0]--> 1,2,
    vector<int> rev_graph[N];

    int m;
    cin >> m;

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        rev_graph[y].push_back(x);
    }
    for(int i=0;i<N;i++){
        cout<<"node "<<i<<"-->";
        for(auto x:graph[i] ) cout<<x<<" ";
        cout<<endl;
    }
    cout<<"\nComponnents:\n";
    solve(graph, rev_graph, N);
    return 0;
}
