#include <iostream>
using namespace std;
void fun(int n,int A,int B,int C)
{
    if(n>0){
        fun(n-1,A,C,B);
        cout<<A<<"to"<<C<<endl;
        fun(n-1,B,A,C);
    }
}
int main()
{
   fun(7,1,2,3);

    return 0;
}