// Traveling salesman Problem
// Inderjit Shahi 2k20/MC/60
#include <bits/stdc++.h>
using namespace std;
#define V 4 
// implementation of traveling Salesman Problem
int travllingSalesmanProblem(int Graph[][V], int s)
{
// store all vertex apart from source vertex
vector<int> vtx;
for (int i = 0; i < V; i++)
if (i != s)
vtx.push_back(i);
// store minimum weight Hamiltonian Cycle.
int minimum_path = INT_MAX;
do {
// store current Path weight(cost)
int current_pathweight = 0;
// compute current path weight
int k = s;
for (int i = 0; i < vtx.size(); i++) {
current_pathweight += Graph[k][vtx[i]];
k = vtx[i];
}
current_pathweight += Graph[k][s];
// update minimum
minimum_path = min(minimum_path, current_pathweight);
} while (
next_permutation(vtx.begin(), vtx.end()));
return minimum_path;
}

//main function
int main()
{
// matrix representation of the graph
cout<<"Inderjit Shahi 2k20/MC/60 \n";
int Graph[][V] = { { 0, 10, 15, 20 },
{ 10, 0, 35, 25 },
{ 15, 35, 0, 30 },
{ 20, 25, 30, 0 } };
int s = 0;
cout << travllingSalesmanProblem(Graph, s) << endl;
return 0;
}