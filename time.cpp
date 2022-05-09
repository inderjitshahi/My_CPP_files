// Calculating Execution Time for a program
#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
int profit[] = {597, 141, 210, 877, 393, 654, 533, 333, 859, 35, 293, 579, 28, 778, 370, 74, 576, 236, 321, 247, 182, 398, 309, 534, 361, 750, 510, 127, 562, 340, 635, 900, 326, 150, 90, 457, 292, 271, 437, 34, 207, 459, 93, 423, 904, 794, 180, 774, 887, 326, 968, 109, 345, 546, 364, 666, 764, 359, 292, 987, 629, 339, 548, 980, 599, 634, 306, 630, 825, 906, 660, 102, 929, 58, 862, 985, 880, 960, 1000, 525, 31, 74, 85, 619, 538, 390, 737, 159, 587, 668, 41, 233, 876, 244, 298, 768, 767, 257, 106, 624};

int weight[] = {604, 897, 844, 207, 869, 156, 23, 378, 322, 687, 371, 507, 330, 171, 985, 22, 590, 539, 315, 415, 810, 185, 406, 368, 454, 309, 98, 72, 650, 535, 132, 644, 822, 798, 711, 217, 875, 454, 923, 754, 436, 545, 180, 626, 575, 424, 164, 333, 581, 554, 333, 30, 618, 804, 427, 986, 355, 272, 186, 102, 11, 832, 680, 515, 771, 708, 685, 929, 471, 32, 560, 826, 471, 174, 13, 452, 500, 286, 454, 867, 225, 272, 991, 740, 405, 263, 534, 182, 147, 88, 85, 525, 86, 420, 434, 833, 849, 940, 535, 338};

int density[] = {184, 558, 796, 399, 311, 638, 806, 959, 841, 322, 662, 765, 338, 487, 37, 268, 33, 687, 813, 149, 235, 254, 815, 413, 51, 896, 267, 756, 969, 555, 258, 839, 951, 75, 206, 521, 147, 542, 451, 314, 745, 685, 927, 731, 519, 264, 514, 476, 575, 308, 271, 111, 599, 955, 944, 297, 820, 497, 381, 7, 471, 100, 140, 23, 710, 277, 699, 593, 278, 975, 401, 885, 96, 435, 838, 977, 997, 155, 952, 155, 43, 480, 510, 858, 587, 651, 802, 581, 246, 313, 694, 343, 948, 602, 227, 414, 344, 172, 99, 54};
int max(int a, int b) { return (a > b) ? a : b; }
void fun(int profit[], int sizes[], int N, int volume)
{
    cout << "For Greedy Approach\n";
    float x = 0;
    float w = 0;
    float p = 0;
    float minweight = 0;
    int i = 0, j = 0;
    int para = 0;
    // cout << " Greedy By Volume" << endl;
    // cout << " Subset = {";
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
            // cout<<j<<",";
        }
        else
        {
            para = volume;
        }
    }
    //     cout << "}" << endl;
    //     cout << "capacity = " << volume << endl;
    //     cout << " total profit = " << p << endl;
    //     cout << " total volume = " << w << endl;
    //     cout << endl;
}
int fun2(int wt[], int val[], int n, int W)
{
    // Base Case
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
        return fun2(wt, val, n - 1, W);

    else
        return max(val[n - 1] + fun2(wt, val, n - 1, W - wt[n - 1]), fun2(wt, val, n - 1, W));
}

int main()
{
    // Start measuring time
    auto begin = high_resolution_clock::now();

    // function execution
    // fun(profit, weight, 100, 1000);

    cout << "For Brute Force Approach:\n";
    fun2(profit, weight, 100, 1000);

    // Stop measuring time and calculate the elapsed time
    auto end = high_resolution_clock::now();
    auto elapsed = duration_cast<nanoseconds>(end - begin);
    printf("\nTime measured: %.7f seconds.\n", elapsed.count() * 1e-9);

    return 0;
}

// Another Approach using time.h, but measures only seconds
//  #include <bits/stdc++.h>
//  using namespace std;

// // A sample function whose time taken to
// // be measured
// vector<int> del;
// void fun()
// {
// 	for (int i=0; i<1000000; i++)
// 	{
//         del.push_back(i);
//         sort(del.begin(),del.end());
// 	}
// 	for (int i=0; i<10000; i++)
// 	{
//         del.pop_back();
//         // sort(del.begin(),del.end());
// 	}
// }

// int main()
// {
// 	/* Time function returns the time since the
// 		Epoch(jan 1 1970). Returned time is in seconds. */
// 	time_t start, end;

// 	/* You can call it like this : start = time(NULL);
// 	in both the way start contain total time in seconds
// 	since the Epoch. */
// 	time(&start);

// 	// unsync the I/O of C and C++.
// 	ios_base::sync_with_stdio(false);
//    // function execution
//     fun(profit, weight, 6,  20);
// 	// Recording end time.
// 	time(&end);

// 	// Calculating total time taken by the program.
// 	double time_taken = double(end - start);
// 	cout << "Time taken by program is : " << fixed
// 		<< time_taken << setprecision(5);
// 	cout << " sec " << endl;
// 	return 0;
// }
