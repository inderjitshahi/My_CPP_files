#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
int gen()
{
    int x;
    cin >> x;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    
    
    while (t--)
    {
       int n=gen();
       int min,max;
    //    vector<vector<int>>res(n,vector<int>(3));
    vector<int>l(n);
    vector<int>r(n);
    vector<int>c(n);
    map<int,int>index;
          for (int  i = 0; i < n; i++)
          {
              cin>>l[i]>>r[i]>>c[i];
              index[l[i]]=i;
          }
          
      for(int i=0;i<n;i++){
          sort(l.begin(),l.begin()+i);
          sort(r.begin(),r.begin()+i);
          int min_ind=
          
      }
       
       
    }
     return 0;
}    