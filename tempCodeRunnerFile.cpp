#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define flase false
#define sz(x) ((int)x.size())
#define pii pair<int, int>
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)

int gen()
{
    int x;
    cin >> x;
    return x;
}
template <class T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag,
                  tree_order_statistics_node_update>;

void summ(list<ll> &st, ll sum, ll mini)
{
    if (sum <= 1)
        return;
    ll sum1 = sum / 2;
    ll sum2=sum1;
    if(sum&1) sum2+=1;
    // cout<<sum1<<" "<<sum2<<endl;
    
    st.push_back(sum1);
    st.push_back(sum2);
    if (mini >= sum1 || mini >= sum2)
        return;
    summ(st, sum1, mini);
    summ(st, sum2, mini);
    return;
}
bool sol()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll sum = 0;
    generate(all(v), gen);
    for (auto x : v)
    {
        sum = (sum + x) % INT64_MAX;
    }
    // cout<<"sum is"<<sum<<endl;
    list<ll> st;
    st.push_back(sum);
    ll mini = *min_element(all(v));
    summ(st, sum, mini);
    for(auto x:st) cout<<x<<"\t";
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        if (find(all(st),v[i]) == st.end())
        {
            return false;
        }
        else st.remove(v[i]);
    }

    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        if (sol())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
