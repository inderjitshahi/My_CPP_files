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


   int partition(vector<int>&nums,int start,int end){
      swap(nums[end],nums[(start+end)/2]);
    int pivot=nums[end];
    int p_index=start;
    for(int i=start;i<end;i++)
    {
        if(nums[i]<=pivot)
        {
            swap(nums[i],nums[p_index]);
            p_index++;
        }
    }
    swap(nums[end],nums[p_index]);
    return p_index;
         }
    void quickSort(vector<int>&v,int s,int e){
        //Base Case
        if(s>=e) return;
        
        //recursive case
        int p=partition(v,s,e);
        quickSort(v,s,p-1);
        quickSort(v,p+1,e);
        return;
    }


int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
vi nums{2,51,3,1,45,5};
 quickSort(nums,0,nums.size()-1);
for(auto x:nums) cout<<x<<" ";
return 0;
}