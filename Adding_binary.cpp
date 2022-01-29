#include <iostream>
#include <string>
#include <math.h>
#include <limits.h> //for INT_MAX
using namespace std;
int main()
{
//    string z="11001";
//    cout<<z;
    long long int n1 = 0, n2 = 0;
    string res;
 string a="101000001001001101";
string b="1101010010111010111110111111";
    for (int i = a.length() - 1, j = 0; i >= 0; i--, j++)
    {

        if (a[i] == '1')
            n1 += pow(2, j);
    }
    for (int i = b.length() - 1, j = 0; i >= 0; i--, j++)
    {

        if (b[i] == '1')
            n2 += pow(2, j);
    }
    int num = n1 + n2;
    // cout<<num;
    int i = 0;
    while(num > 0)
    {
        res+=(char)(num % 2 + 48);
        num = num / 2;
    }
    i--;
        
        for(int j=0;j<=i;j++,i--){
            char temp=res[i];
            res[i]=res[j];
            res[j]=temp;
        }
        cout<<res;
        return 0;
}