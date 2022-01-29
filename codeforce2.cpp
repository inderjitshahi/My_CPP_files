#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
       int t;
    cin >> t;
    vector<int> res;
    int n,temp;
    while (t--)
    {
        cin>>n;
        int k=0;
        while(k++<n){cin>>temp;res.push_back(temp);}
        sort(res.begin(),res.end(),greater<int>());
        int i=0;
        int p=0,q=1;
        while (i<n/2&&p<n)
        {
          if(find (res.begin(), res.end(), (res[p]%res[q]))==res.end()){  cout<<res[p]<<" "<<res[q]<<endl;i++;}
            if(q<n) q++;
            else {p++;q=p+1;}
        }
        
        res.clear();
      
    }
    return 0;
}
