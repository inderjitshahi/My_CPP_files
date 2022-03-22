#include <iostream>
using namespace std;
int i=1;
void fun(int n,int A,int B,int C)
{
   if(n>0){
     
           fun(n-1,A,C,B);   //moves n-1 rings from A to B using C
           cout<<i<<". "<<A<<" to "<<C<<"\n";i++;
           fun(n-1,B,A,C);  //move  n-1 rings from B to C using A
       
     
   }
     return;
}
int main()
{
   fun(3,1,2,3);

    return 0;
}