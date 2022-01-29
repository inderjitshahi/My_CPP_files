#include <iostream>
#include<cstring>

using namespace std;

int main()
{

    char a[1000];
    bool peld;


    cout<<"enter the charecter you want to enter"<<endl;

    cin.getline(a,100);
int j=strlen(a)-1;
for(int i=0;i<=j;i++,j--){
    if(a[i]!=a[j]){
        peld=false;
        break;}
    else
        peld=true;

}
  if(peld)
    cout<<"a peldrome";
   else
    cout<<"not peldrome";
    return 0;
}
