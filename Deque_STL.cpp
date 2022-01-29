
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

//////////////////////prateek_sir///////////////////////////////////////////////
int main(){
    int n;
    cin>>n;
    int a[10000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k,i;cin>>k;
    deque<int> Q(k);
    for( i=0;i<k;i++){
        while(!Q.empty()&&a[i]>=a[Q.back()]){
            Q.pop_back();
        }
        Q.push_back(i);
    }
    for(;i<n;i++){
        cout<<a[Q.front()]<<" ";
        //remove elements which are not part of window
        while(!Q.empty()&&Q.front()<=i-k) Q.pop_front();
        //removing the elements which are useful and are in window
        while(!Q.empty()&&a[i]>=a[Q.back()]){
            Q.pop_back();
        }
        //add new elements
        Q.push_back(i);
    }
    cout<<a[Q.front()]<<endl;
    return 0;
}




////////////////////////////my_code/////////////////////////////////////////////
// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
//     int t;cin>>t;
//     int n,k,i,p;
//     while(t--){
//        deque<int>res(10000);
//        cin>>n>>k;
//        i=0;
//        while(i<k){
//            cin>>res[i++];
//        }
//        cout<<*max_element(res.begin(),res.end())<<" ";
//        res.pop_front();
//        p=n-k;
//        while(p--){
//           cin>>res[i-1]; 
//           cout<<*max_element(res.begin(),res.end())<<" ";
//           res.pop_front();
//        }
//        cout<<endl;
        
//     } 
//     return 0;
// }
