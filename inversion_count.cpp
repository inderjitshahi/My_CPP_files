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
//0 3 1 2
 int merge(vector<int>& v,int s,int e){
        int mid=(s+e)/2;
        int k=s,i=s,j=mid+1,cnt=0;
        vector<int>temp(100000);
        while(i<=mid and j<=e){
            if(v[i]<=v[j]) temp[k++]=v[i++];
            else {temp[k++]=v[j++];cnt+=mid-i+1; }
        }
        while(i<=mid) temp[k++]=v[i++];
        while(j<=e) temp[k++]=v[j++];
        for(int i=s;i<=e;i++){
            v[i]=temp[i];
        }
        return cnt;
    }
    int ic(vector<int>& v,int s,int e){
        // Base case
        if(s>=e) return 0;
        // Recursive Case merge sort
        int mid=(s+e)/2;
        int x=ic(v,s,mid);
        int y=ic(v,mid+1,e);
        int z=merge(v,s,e);
        return (x+y+z);   
    }
    bool isIdealPermutation(vector<int>& nums) {
        int l=0,g=0;
        for(int i=0;i<(nums.size()-1);i++){
            if(nums[i]>nums[i+1]) l+=1;
        }
        g=ic(nums,0,nums.size()-1);
        cout<<l<<" "<<g;
        return (l==g);
    }

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
vi v{0,3,1,2};
isIdealPermutation(v);
return 0;
}