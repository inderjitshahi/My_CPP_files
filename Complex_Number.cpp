#include <iostream>
using namespace std;
class complex
{
public:
    int real, img;

    complex(int r = 0, int i = 0)
    { //constructor
        real = r;
        img = i;
    }

    complex operator+(complex x)
    {
        complex temp;
        temp.real = real + x.real;
        temp.img = img + x.img;
        return temp;
    }
    void display()
    {
        cout << real << " +i(" << img << ")" << endl;
    }
    complex sub(complex x)
    {
        complex temp;
        temp.real = real - x.real;
        temp.img = img - x.img;
        return temp;
    }
    friend complex operator*(complex a, complex b);    //defining friend function for overloading
    friend ostream &operator<<(ostream &o, complex b); //defining friend-function(must) for output stream overloading
};

complex operator*(complex a, complex b)
{ //friend function without scope resolution
    complex temp;
    temp.real = a.real * b.real - a.img * b.img;
    temp.img = a.real * b.img + a.img * b.real;
    return temp;
}
ostream &operator<<(ostream &o, complex b)
{
    o << b.real << "+i" << b.img << endl;
    return o;
}
int main()
{
    complex c1(1, 1), c2(1, -1), c3, c4, c5, c6;
    c3 = c1 + c2;
    c4 = c1.sub(c2); //object c1 calling funtion sub with object c2 as argumnet
    c5 = c1 * c2;
    cout << c1; //using overloaded "<<" operator
    // c3.display();
    // c4.display();
    // c5.display();
    return 0;
}