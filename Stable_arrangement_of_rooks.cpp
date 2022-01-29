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

    int n,k;
    string s;
    while (t--)
    {
       n=gen();
       k=gen();
       
       if(k>ceil((float)n/2)) cout<<-1<<endl;
       else{
           vector<vector<char>>res(n,vector<char> (n, '.'));
           for (int i = 0; i < n; i++)
           {
              if(i%2==0&&k>0) {res[i][i]='R';k--;}
              for(int j=0;j<n;j++){
                  cout<<res[i][j];
              }  
              cout<<endl;
           }
           

           }
       
    }
     return 0;
}    