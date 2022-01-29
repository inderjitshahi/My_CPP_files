#include <iostream>
#include <string>
#include <math.h>
#include <limits.h> //for INT_MAX
using namespace std;
int main()
{
    int n;
  string a="100";
string b="110010";
    if (a == "0" && b == "0")
    {
        cout << "0";
        return 0;
    }

    long long int pow = 0;
    string res;

    int i = a.length() - 1, j = b.length() - 1;
    while (i >= 0 && j >= 0)
    {
        int temp = a[i--] + b[j--] - 2 * 48 + pow;
        if (temp == 3)
        {
            res += '1';
            pow = 1;
        }
        else if (temp == 2)
        {
            res += '0';
            pow = 1;
        }
        else if (temp == 1 || temp == 0)
        {
            res += (char)(temp+48);
            pow=0;
        }
    }
    i++,j++;
    while (i > 0)
    {
         int temp = a[i--] - 48 + pow;
       
         if (temp == 2)
        {
            res += '0';
            pow = 1;
        }
        else if (temp == 1 || temp == 0)
        {
            res += (char)(temp+48);
             pow=0;
        }
    }
    while (j > 0)
    {
           int temp = b[j-1] - 48 + pow;
    
        if (temp == 2)
        {
            res += '0';
            pow = 1;
        }
        else if (temp == 1 || temp == 0)
        {
            res += (char)(temp+48);
             pow=0;
        }
       j--;
    }
    if (pow == 1)
        res += '1';
    int k = res.length() - 1;
    for (int j = 0; j <= k; j++, k--)
    {
        char temp = res[k];
        res[k] = res[j];
        res[j] = temp;
    }
    cout << res;
    return 0;
}