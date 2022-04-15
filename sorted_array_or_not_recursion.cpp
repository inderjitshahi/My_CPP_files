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


bool isSorted(vector<int>&v,int n){
    // base case
    if(n==v.size()-1) return true;
    //recursive case
    bool small_ans=isSorted(v,n+1);
    return (small_ans)&&(v[n]<v[n+1]);
}
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
vector<int>v{1,2,3,5};
if(isSorted(v,0))cout<<"sorted";
else cout<<"not sorted";

return 0;
}