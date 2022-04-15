// Calculating Execution Time for a program

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

void fun()
{
    map<int, int> res;
    int target=10;
    vector<int>nums={3,3,5,64,544,343,42,33,434,54,5,5,56,56,6,6,76,65,6,55,45,45,4};
    for (int i = 0; i < nums.size(); i++)
    {
        if (res.count(target - nums[i]))
        {
            cout<<res[target - nums[i]];
            cout<<","<<i;
           \
        }
        else
            res[nums[i]] = i;
    }
    return;
}
void fun2()
{
    map<int, int> res;
    int target=10;
    vector<int>nums={3,3,5,64,544,343,42,33,434,54,5,5,56,56,6,6,76,65,6,55,45,45,4};
    map<int ,int> m;
    map<int ,int> dm;
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]]!=0) dm[nums[i]]=i+1;
            else m[nums[i]]=i+1;
        }
        
        for(auto x:m){
            if(m[target-x.first]!=0){
                if((target-x.first)==x.first){
                  cout<<x.second-1;
                  cout<<dm[x.first]-1;
                    break;
                }
              else {
                cout<<(x.second-1);
                cout<<(m[target-x.first]-1);
                break;
            }
          } 
            
        }
        return;
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
