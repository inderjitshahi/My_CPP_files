// O(log(n)) 

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

int fast_exponent(int a,int n){
   if(n==0) return 1;
   if(n&1)  return a*pow(fast_exponent(a,n/2),2);
   else return a*pow(fast_exponent(a,n/2),2);

}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// int a=gen<int>();
// int n=gen<int>();
// cout<<fast_exponent(a,n);
// cout<<(-100%5);
vector<int> nums={4,5,0,-2,-3,1};
int k=5;
 int n=nums.size();
        unordered_map<int,int>fre;
        vector<int>cumm(n+1,0);
        for(int i=1;i<n+1;i++){
            cumm[i]=nums[i-1]+cumm[i-1];
            cumm[i]=cumm[i]%k;
        }
        for(auto x:cumm) cout<<x<<" ";
return 0;
}