#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
vector<int> nums{1,2,3,1,2,3};
int k=2;
 map<int,int> res;
        for(int i=0;i<nums.size();i++){
            if(res.count(nums[i])&&abs(res[nums[i]]-i)<=k){
                cout<<"true";
                return 1;
            }
            else{
                res[nums[i]]=i;
            }
        }
        cout<<"false";
        return 1;

}