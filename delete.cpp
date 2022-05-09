#include <bits/stdc++.h>
using namespace std;

struct Item
{
    float weight;
    int value;
};

struct Node
{
    int level, profit, bound;
    float weight;
};

bool cmp(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}
// Returns bound of profit in subtree rooted with u.
int bound(Node u, int n, int W, Item arr[])

{

    return 0;

    // item index
    int j = u.level + 1;
    int totweight = u.weight;

    while ((j < n) && (totweight + arr[j].weight <= W))
    {
        totweight += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }
    // If k is not n, include last item partially for
    // upper bound on profit if (j < n)
    profit_bound += (W - totweight) * arr[j].value /
                    arr[j].weight;
    return profit_bound;
}
// Returns maximum profit we can get with capacity W int knapsack(int W, Item arr[], int n)
{
    // sorting Item on basis of value per unit
    // weight.
    sort(arr, arr + n, cmp);
    // make a queue for traversing the node queue<Node> Q;
    Node u, v;
    // dummy node at starting u.level = -1;
    u.profit = u.weight = 0;
    Q.push(u);

    while (!Q.empty())
    {
        // Dequeue a node u = Q.front();
        Q.pop();
        // If it is starting node, assign level 0

        if (u.level == -1)
            v.level = 0;
        // If there is nothing on next level if (u.level == n - 1)
        continue;
        // Else if not last node, then increment level,
        // and compute the profit of children nodes. v.level = u.level + 1;
        // Taking current level's item add current
        // level's weight and value to node u's
        // weight and value
        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].value;
        // If cumulated weight is less than W and
        // profit is greater than previous profit,
        // update maxprofit
        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;
        // Get the upper bound on profit to decide
        // whether to add v to Q or not. v.bound = bound(v, n, W, arr);
        // If bound value is greater than profit,
        // then only push into queue for further
        // consideration
        if (v.bound > maxProfit)
            Q.push(v);
        // Do the same thing, but Without taking
        // the item in knapsack v.weight = u.weight; v.profit = u.profit;
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit)
            Q.push(v);
    }
    return maxProfit;
}
int main()
{
    cout << "BY inderjit Shahi 2K20/MC/60\n";
    int W = 10; // Weight of knapsack
    Item arr[] = {{2, 40}, {3.14, 50}, {1.98, 100}, {5, 95}, {3, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum possible profit = " << knapsack(W, arr, n);
    return 0;
}
