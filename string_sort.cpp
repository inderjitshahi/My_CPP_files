#include<iostream>
#include<string>
#include<algorithm>
 using namespace std;
 
 bool compare(string a, string b){
     if(a.length()==b.length()){
         return a<b;
     }
     return a.length()>b.length();
 }

 
 int main(){ 
cout<<"enter the no. of strings "<<endl;
int n;
cin>>n;
cin.get();
string S[100];
cout<<"enter strings"<<endl;
for (int i = 0; i < n; i++)
{
    getline(cin,S[i]);
}
cout<<"\n";
sort(S,S+n,compare);

for (int i = 0; i < n; i++)
{
    
    cout<<S[i]<<endl;
}

 }
 