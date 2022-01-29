//This Program is written for generation  of data for using as a test case in various DSA problems etc. or using generated data in ML related Projects

#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    long long l, u, n;
    char sorted,unique,seperator;
    cout << "Enter y/n for sorted, y/n for unique, seperator withot space of enter eg:'nn,' \n";
    long long num;
    cin >> sorted>>unique;
    seperator=cin.get();
    cout<<"Enter l, u and n\n";
    cin >> l >> u >> n;
    
    if (sorted == 'n'&&unique=='n')
    {
        while (n--)
        {
            num = (rand() % (u - l + 1)) + l;
            cout << num;
           if(n) putchar(seperator);
        }
    }
    else if(unique=='y'&&sorted=='n'){
        unordered_set<long long>s;
        while(s.size()!=n){
            num = (rand() % (u - l + 1)) + l;
            s.insert(num);
        }
        n-=1;
        for(auto x:s){
           cout << x;
            putchar(seperator);
        }
    }
    else if(unique=='y'&&sorted=='y'){
        set<long long>s;
        while(s.size()!=n){
            num = (rand() % (u - l + 1)) + l;
            s.insert(num);
        }
        for(auto x:s){
            cout <<x;
            putchar(seperator);
        }
    }
    else{
        vector<long long>s;
        while(s.size()!=n){
            num = (rand() % (u - l + 1)) + l;
            s.push_back(num);
        }
        sort(all(s));
        for(auto x:s){
           cout << x;
            putchar(seperator);
        }
    }

    return 0;
}