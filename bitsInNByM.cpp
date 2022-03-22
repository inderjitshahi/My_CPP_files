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

int clearRangeItoJ(int n, int j, int i)
{
    int ones = ~0;
    int b = ones << (j + 1);
    int a = (1 << i) - 1;
    int mask = a | b;
    return n & mask;
}
int replaceBits(int n,int m,int i,int j){
    int n_=clearRangeItoJ(n,j,i); //set bits of n from j to i '0'
    return n_|(m<<i); //adding m b/w j to ith bits 
}
int decimalToBinary(int n){
    int ans=0,p=1;
    while (n){
        cout<<(n&1); //will give in reverse order
        // int lastBit=(n&1);
        // ans+=p*lastBit;
        // p=p*10;
        n=n>>1;
    }
   return ans; 
}
int reverseNumber(int n){
    int rev=0,p=1;
    while(n>0){
        rev=10*rev+(n%10);
        p=p*10;n=n/10;
    }
    return rev;
}
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// int n=gen<int>();
int N;
// cin>>N;
cout<<decimalToBinary(7);
return 0;
}