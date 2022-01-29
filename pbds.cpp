#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define int long long
#define ull unsigned long long
#define f(i,l,r) for(int i=(l);i<=(r);i++)
#define fb(i,l,r) for(int i=(l);i>=(r);i--)
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
template<class T> using pbds= tree<T, null_type, less<T>, rb_tree_tag,  //replace less by less_equal<T> for allowing duplicate.
tree_order_statistics_node_update>;

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

pbds<int>s;
s.insert(1);
s.insert(2);
s.insert(36);
s.insert(100);
s.insert(5);
s.insert(0);
cout<<(s.order_of_key(36))<<endl;  //number of items strictly smaller than k.
cout<<(*s.find_by_order(4));  //k-th element in the set (counting from zero). returns iterator


return 0;
}
