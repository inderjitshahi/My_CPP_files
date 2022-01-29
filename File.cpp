#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream f("My.txt");
    for (int i = 0; i < 5; i++)
    {
        f << 100 + i << "\t";
    }
    f << endl;
    for (int i = 0; i < 5; i++)
    {
        f << 100 * i << "\t";
    }
    f << endl;

    // f<<"Hello World\n";
    f.close();

    ifstream fb;
    fb.open("My.txt");
    for (int i = 0; i < 15; i++)
    {
        int a;
        fb >> a;
        cout << a<<"\t";
    }

    return 0;
}