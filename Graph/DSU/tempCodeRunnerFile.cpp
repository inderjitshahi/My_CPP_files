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


class graph{
int V;
list<pair<int,int>>edgeList;
public:
graph(int V){
    this->V=V;
}
void addEdge(int x,int y){
    edgeList.pb(make_pair(x,y));
}
//Find 
int findSet(int i,int *parent){
    //Base Case 
    if(parent[i]==-1) return i;
    return findSet(parent[i],parent);
}

//unio
void UnionSet(int x, int y,int *parent){
    int s1=findSet(x,parent);
    int s2=findSet(y,parent);
    if(s1!=s2) parent[s2]=s1;
}
bool containsCycle(){
    //DSU logic to check for cycle
    int *parent=new int[V+1]{-1};
    for(auto x:parent) cout<<x<<",";
    for(auto edge:edgeList){
        
        int i=edge.first;
        int j=edge.second;

        int s1=findSet(i,parent);
        int s2=findSet(j,parent);
        if(s1!=s2) UnionSet(s1,s2,parent);
        else {
            cout<<"Same parent: "<<s1<<" "<<s2<<" of "<<i<<" and "<<j;
            return true;
        }
    }
    delete []parent;
    return false;

}
};

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
graph g(4);
g.addEdge(0,1);
g.addEdge(1,2);
g.addEdge(2,3);
g.addEdge(3,0);
g.containsCycle();



return 0;
}