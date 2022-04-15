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


int sol(vector<int> price,vector<int> weight,int C,int N){
    //base case
    if(C==0||N==0) return 0;
    //recurive Case
    //include
    int inc=0,exc=0;
    if(C>=weight[N-1]) inc=price[N-1]+sol(price,weight,C-weight[N-1],N-1);
    //exclude
    exc=sol(price,weight,C,N-1);
    return max(inc,exc);
}


int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
vector<int>price{40,20,30,100};
vector<int>weight{1,2,3,5};
int C=7;
cout<<sol(price,weight,C,4);
return 0;
}