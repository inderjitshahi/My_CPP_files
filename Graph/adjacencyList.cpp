#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define flase false
#define sz(x) ((int)x.size())
#define pii pair<int, int>
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
template <class T>
T gen()
{
    T x;
    cin >> x;
    return x;
}
template <class T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag,
                  tree_order_statistics_node_update>;
class graph
{
    int V;   // #vertices 
    map<string, list<pair<string,int>>> l;
    // list<int> *l;  //variable array of lists

public:
    graph(int V)
    {
        this->V = V;
        // l = new list<int>[V]; // V  number of lists 
    }
/*********     for weighted directed graph***********/

   void addEdge(string x, string y,bool bidir,int wt){
       l[x].push_back(make_pair(y,wt));  //l[x] is list corresp. to key x 
       if(bidir){  //if bi-directional or directed
           l[y].push_back(make_pair(x,wt));
       }
   }
void printAdjList(){
    for(auto  p:l){
        string city=p.first;
        list<pair<string,int>> nbrs=p.second;
        cout << "city " << city << "-> ";
        for(auto x:nbrs){
            cout<<"("<<(x.first)<<","<<(x.second)<<") ";
        }
        cout<<"\n";

    }
}
/*********     for unweighted undirected graph***********/
    // void addEdge(int x, int y)
    // {
    //     l[x].push_back(y);
    //     l[y].push_back(x);
    // }
    // // void printAdjList()
    // // {
    // //     for (int i = 0; i < V; i++)
    // //     {
    // //         cout << "Vertex " << i << "-> ";
    // //         for (int nbr : l[i])
    // //         {
    // //             cout << nbr << ",";
    // //         }
    // //         cout << "\n";
    // //     }
    // // }
};

int32_t main()
{
    graph g(4);
   g.addEdge("A","B",true,20);
   g.addEdge("A","C",true,10);
   g.addEdge("B","D",true,30);
   g.addEdge("C","D",true,40);
   g.addEdge("A","D",false,50);
   g.printAdjList();
    return 0;
}