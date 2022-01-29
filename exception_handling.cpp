#include <iostream>
using namespace std;
int main()
{
    int x=10,y=0,z;
    cin>>x>>y;
    try
    {
        if(y==0)
        throw 101;
        z=x/y;
        cout<<"x/y= "<<z<<endl;
    }
    catch(int e)
    {
        cout<<"not divisible by zero error"<<e<<endl;
    }
   
    return 0;
}