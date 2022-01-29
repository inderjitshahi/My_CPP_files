#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
int gen(){
    int x;
    cin>>x;return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
       int t;
    cin >> t;
    int n,x,y;
    while (t--)
    {
        bool flag=true;
        cin>>n>>x>>y;
         vector<int> v1(n);
         vector<int> v2(n);
        generate(all(v1),gen);
        generate(all(v2),gen);
        for(int i=0;i<n;i++){
            if(v1[i]+x==v2[i]||v1[i]+y==v2[i]) continue;
            else {cout<<"NO\n";;flag=false;break;}
        }
      if(flag)  cout<<"YES\n";
      
    }
    return 0;
}
