//Calculating Execution Time for a program

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
void fun()
{
    long long iterations = 100000000000, sum = 0, add = 0;
    for (int i = 0; i < iterations; i++)
    {
        sum = (sum + add) % 100;
        add /= 2.0;
    }
}
int main()
{
    // Start measuring time
    auto begin = high_resolution_clock::now();

    // function execution
    fun();

    // Stop measuring time and calculate the elapsed time
    auto end = high_resolution_clock::now();
    auto elapsed = duration_cast<nanoseconds>(end - begin);
    printf("Time measured: %.7f seconds.\n", elapsed.count() * 1e-9);

    return 0;
}


//Another Approach using time.h, but measures only seconds
// #include <bits/stdc++.h>
// using namespace std;

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

// 	fun();

// 	// Recording end time.
// 	time(&end);

// 	// Calculating total time taken by the program.
// 	double time_taken = double(end - start);
// 	cout << "Time taken by program is : " << fixed
// 		<< time_taken << setprecision(5);
// 	cout << " sec " << endl;
// 	return 0;
// }
