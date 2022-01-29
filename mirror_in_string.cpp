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
    string s;
    while (t--)
    {
        string temp;
        string res;       
        cin >> n;
        cin>>s;
        int i=0;
        while(s[i]>=s[i+1])
        {
            if(i==0&&s[i]==s[i+1])break;
            i++;
        }
        temp=s.substr(0,i+1);
        res=temp;
        reverse(all(temp));
        res.append(temp);
        cout <<res<<endl;
    }
     return 0;
}    