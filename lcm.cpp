#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int lcm(vector<int> a)
{
    int lcm1 = 1;
    int i = 2;
    bool div = true, not_increment = false;
    int max = *max_element(a.begin(), a.end());
    while (i <= max)
    {
        not_increment = false;
        for (int j = 0; j < a.size(); j++)
        {
            if (a[j] % i == 0 && div)
            {
                lcm1 = lcm1 * i;
                div = false;
            }
            if (a[j] % i == 0)
                a[j] = a[j] / i;
            if (a[j] % i == 0)
                not_increment = true;
        }
        div = true;
        if (!not_increment)
            i++;
    }
    return lcm1;
}

int main()
{
    vector<int> a{2,4};
    int lcm1 = lcm(a);
    cout << lcm1;
    return 0;
}