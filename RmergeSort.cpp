#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define vi vector<int>   //Remember
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
void merge(vector<int>&v,int s,int e){
    int mid=(s+e)/2;
    int i=s,j=mid+1,k=s;
    vi temp(v.size());
    while(i<=mid&&j<=e){
        if(v[i]<=v[j]) temp[k++]=v[i++];
        else temp[k++]=v[j++];
    }
    while(i<=mid) temp[k++]=v[i++];
    while(j<=e) temp[k++]=v[j++];
    for(int i=s;i<=e;i++){
        v[i]=temp[i];
    }
}
void mergeSort(vector<int>&v,int s,int e){
    //Base case
    if(s>=e) return;
    
    //Recrsive Case
    int mid=(s+e)/2;
    mergeSort(v,s,mid);
    mergeSort(v,mid+1,e);

    //merge
    merge(v,s,e);

}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
vi v{5,6,1,3,4,0,5,6,5,54,543,5,4534};
mergeSort(v,0,v.size()-1);
for(auto x:v) cout<<x<<",";
return 0;
}