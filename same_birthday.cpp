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
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n=gen<int>();
if(n==100) {cout<<"366"<<endl;return 0;}
int i=1;
float percent=100.00;
while(1){
    percent=percent*((365-i)/365.0);
    if((100.0-percent)>=n) break;
    i++;
}
cout<<(i+1);
return 0;
}