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

void subSequences(char *input,char *output,int i,int j){
    //base case
    if(input[i]=='\0'){
        output[j]='\0';
        cout<<output<<"\n";
        return;
    }

    // Recursive Case
    //inculde present character
    output[j]=input[i];
    subSequences(input,output,i+1,j+1);

    // Exclude Present Case
    subSequences(input,output,i+1,j);
};


int32_t main(){

char input[]="abc";
char output[1000];
subSequences(input,output,0,0);

return 0;
}