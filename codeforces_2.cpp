#include<bits/stdc++.h>
using namespace std;
char min(string s){
    char x='z';int i=0;
    while(s[i]!='\0'){
        if(x>s[i])x=s[i];i++;
    }
    return x;
}
string bb(string s,string a){
    bool t=1;int i=0;string b;
    while(s[i]!='\0'){
        if(s[i]==a[0]&&t){
            t=0;i++;continue;}
       
        else{
           b+=s[i];  
        }
        i++;
    }
    return b;
}
int main(){
int t;
cin>>t;
getchar();
string s;
for(int i=0;i<t;i++){
getline(cin,s);
string a,b;
a+=min(s);
b=bb(s,a);
cout<<a<<"\t";
cout<<b<<endl;
}

return 0;
}
