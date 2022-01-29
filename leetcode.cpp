#include<iostream>
using namespace std;
 double myPow(double x, int n) {
        static bool neg=false;
        static double pow=1;
        if(n<0) {
            neg=true;
            n=n*-1;}
       if(n==0) return 1;
        
        pow=pow*x;
        myPow(x,n-1);
        if(neg) return 1/pow;
        return pow;
        
    }
int main(){
cout<<myPow(2.1,10);

return 0;
}