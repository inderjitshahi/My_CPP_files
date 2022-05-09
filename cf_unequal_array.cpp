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


void solve(){
int n;
cin>>n;
vi v(n);
generate(all(v),gen<int>);
int ans=0,l=-1,r=-1;
if(n<=2){cout<<0<<"\n";return;}
for(int i=0;i<n-1;i++){
  if(v[i]==v[i+1]) l==-1?(l=i,r=i):r=i;
}
if(l==r or l==-1) {cout<<0<<endl;}
else {cout<<max(1,r-l-1)<<"\n";}
return;
}


int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--) solve();
return 0;
}