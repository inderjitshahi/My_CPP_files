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
                
            cin >> n;
            vector<int>res(n);
            generate(all(res),gen);
            cout<<(*max_element(all(res))-*min_element(all(res)))<<endl;
        }
        return 0;
    }    