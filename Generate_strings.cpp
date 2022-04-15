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

vector<char> mapping{' ','A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};


void sol(string s,char *out,int i,int j){
    //Base case
    if(s[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return;
    }

    //recursive Case
    //Choosing single charecter
    out[j]=mapping[s[i]-'0'];
    sol(s,out,i+1,j+1);
    //Choosing 2 charaters if they are small than 26
    int digit=27;
   if(s[i+1]!='\0')  digit=(int)(s[i]-'0')*10+ (int)(s[i+1]-'0');
   if(digit<=26) {
       out[j]=mapping[digit];
       sol(s,out,i+2,j+1);}

}


int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
string s="1212";
char output[6];
sol(s,output,0,0);
return 0;
}