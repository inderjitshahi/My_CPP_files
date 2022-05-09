#include <bits/stdc++.h>
using namespace std;
void greedyBySize(float profit[], float sizes[], int N, int volume)
{
    float x =0;
    float w = 0;
    float p = 0;
    float minweight = 0;
    int i = 0, j=0;
    int para = 0;
    cout << " Greedy By Volume" << endl;
    cout << " Subset = {";
    while (para < volume)
    {
        i = 0;
        j = 0;
        minweight = sizes[i];
        while (i < N)
        {
            if (minweight > sizes[i])
            {
                minweight = sizes[i];
                j = i;
            }
            i++;
        }
        w = w + minweight;
        para = w;
        if (w > volume)
        {
            w = w - minweight;
        }
        else
        {
            p = p + profit[j];
            while (j < N)
            {
                sizes[j] = sizes[j + 1];
                profit[j] = profit[j + 1];
                j++;
            }
            sizes[j] = 0;
            profit[j] = 0;
            N = N - 1;
        }
        if (j != 0)
        {
            cout<<j<<",";
        }
        else
        {
            para = volume;
        }
    }
    cout << "}" << endl;
    cout << "capacity = " << volume << endl;
    cout << " total profit = " << p << endl;
    cout << " total volume = " << w << endl;
    cout << endl;
}
void greedyByDensity(float profit[], float weight[], float density[], int N, int capacity)
{
    float x = 0;
    float w = 0;
    float p = 0;
    float maxdensity = 0;
    int i = 0, j=0;
    int para = 0;
    cout << " Greedy By Density"<< endl;
    cout << " Subset = {";
    while (para < capacity)
    {
        i = 0;
        j = 0;
        maxdensity = 0;
        ;
        while (i < N)
        {
            if (maxdensity < density[i])
            {
                maxdensity = density[i];
                j = i;
            }
            i++;
        }
        w = w +weight[j];
        para = w;
        if (w >
            capacity)
        {
            w = w -weight[j];
        }
        else
        {
            p = p + profit[j];
            while (j < N)
            {
                weight[j] = weight[j + 1];
                profit[j] = profit[j + 1];
                j++;
            }
            weight[j] = 0;
            profit[j] = 0;
            N = N -1;
        }
        if (j != 0)
        {
            cout<<j<<",";
        }
        else
        {
            para = capacity;
        }
    }
    cout << "}" << endl;
    cout << " total profit = "<<p <<endl; cout << " total weight = "<<w <<endl; 
}

int main()
{
    float profit[]={2,3,4,5,6};
    float weight[]={4,5,6,3,1};
    float density[]={2,3,4,2,1};
    greedyByDensity(profit, weight,  density,  6,  20);
    cout<<"\n";
    greedyBySize(profit, weight, 6,  20);

    return 0;
}