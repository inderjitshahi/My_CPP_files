#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define ull unsigned long long
#define ll  long long
#define pb push_back
#define ff first
#define ss second
#define flase false
#define sz(x) ((int)x.size())
#define pii pair<int,int>
#define w(t) int t;cin>>t;while(t--)
template<class T>
T gen(){
T x;
cin>>x;
return x;
}
template<class T> using pbds= tree<T, null_type, less<T>, rb_tree_tag,
tree_order_statistics_node_update>;

//DSU data structure
// Path comression+ union By rank
class DSU{
    int *parent;
    int *rank;
    public:
    DSU(int n){
        parent=new int[n];
        rank=new int[n];
        for (int i = 0; i < n; i++)
        {
            parent[i]=-1;
            rank[i]=1;
        }
        
    }
    //Find Function
    int find(int i){
        if(parent[i]==-1) return i;
    }
    //Union Union
    void unite(int x,int y){
        int s1=find(x);
        int s2=find(y);

        if(s1!=s2){
            //union by rank
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
};

class graph{
    int V;
    vector<vector<int>> edgeList;
    public:
    graph(int V){
        this->V=V;
    }
    void addEdge(int x,int y,int wt){
        edgeList.push_back({wt,x,y});
    }
    int Kruskal(){
        //sort based upon weight;

        DSU s(V);
        sort(all(edgeList));
        int ans=0;
        //traversing throungh each edge
        for(auto edge:edgeList){
            int w=edge[0];
            int x=edge[1];
            int y=edge[2];
            //take that edge in MST if dont form cycle
            if(s.find(x)!=s.find(y)){
                s.unite(x,y);
                ans+=w;
            }
        }
        return ans;
    }

};

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
graph g(4);
g.addEdge(0,1,1);
g.addEdge(1,2,3);
g.addEdge(3,2,4);
g.addEdge(2,0,2);
g.addEdge(0,3,2);
g.addEdge(1,2,2);
cout<<g.Kruskal();
return 0;
}