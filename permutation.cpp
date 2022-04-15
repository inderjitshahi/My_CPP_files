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
void sol(char *inp,int i){
    //Base Case
    if(inp[i]=='\0'){
        cout<<inp<<endl;
        return;
    }

    //Recursive Case
    for(int j=i;inp[j]!='\0';j++){
        swap(inp[i],inp[j]);
        sol(inp,i+1);
        swap(inp[i],inp[j]);  //Backtracking
    }
}


int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
char input[100];
cin>>input;
sol(input,0);
return 0;
}