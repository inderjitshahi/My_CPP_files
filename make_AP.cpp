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

            vector<int>res(3);
            generate(all(res),gen);
            if((2*res[1]-res[2])%res[0]==0&&(2*res[1]-res[2])>res[0]) cout<<"YES\n";
            else if((res[0]+res[2])%(res[1]*2)==0) cout<<"YES\n";
            else if((2*res[1]-res[0])%res[2]==0&&(2*res[1]-res[0])>res[2]) cout<<"YES\n";
            else cout<<"NO\n";
        }
        return 0;
    }    