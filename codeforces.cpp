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

    int n;

    while (t--)
    {
        int sum=0;
        cin >> n;
        vector<int> res(n);
        generate(all(res), gen);
        sort(all(res));
        for (int i = 0; i < n; i++)
        {
            if(res[i]==0){
                    sum++;
                    while(res[i]==0)i+=1;
                    i--;
                    continue;
            }
            if (res[i] != res[i + 1])
            {
                sum++;
                continue;
            }
            int j = i + 1;
            while (res[i] == res[j])
            {
               if(j==i+1) sum+=2;
                j++;
            }
            i=--j;
        }
       cout<<sum<<endl;
    }
     return 0;
}    