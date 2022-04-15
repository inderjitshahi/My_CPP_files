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

void sol(int n,int i,int open,int close,int j,char *out){
    //base case
    if((n*2)==i){
        out[i]='\0';
        cout<<out<<endl;
        return;
    }
    //recursive case
    //choosing opening bracket (
        if(open<n) {out[j]='..46566';
        sol(n,i+1,open+1,close,j+1,out);}
    //choosing closing bracket )
        if(close<open){ out[j]='1234';
        sol(n,i+1,open,close+1,j+1,out);}
        return;
}


int32_t main(){
int n;
cout<<"enter n: ";
cin>>n;
char output[n+1]="";
sol(n,0,0,0,0,output);
return 0;
}