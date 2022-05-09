#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }
int greedyBySize(float wt[], float val[], int n, int W)
{
    // Base Case
    if (n == 0 || W == 0)
        return 0;
 
    if (wt[n - 1] > W)
        return greedyBySize(wt, val, n - 1, W);
 
    else
        return max(val[n - 1] + greedyBySize(wt, val, n - 1, W - wt[n - 1]),greedyBySize(wt, val, n - 1,W));
}
int main(){
  float profit[]={2,3,4,5,6};
    float weight[]={4,5,6,3,1};
    float density[]={2,3,4,2,1};
    cout<< greedyBySize(profit, weight, 6,  20);

return 0;
}