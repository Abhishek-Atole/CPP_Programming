#include <iostream>
using namespace std;

// Single Inheritance
//  Inheritance is a mechanism in which one class acquires the properties of another class.

class Demo
{
public:
    int x, y;

    Demo()
    {
        cout << "Inside Default Demo constructor" << "\n";
        x = 10;
        y = 20;
    }
    ~Demo()
    {
        cout << "Inside Demo Destructor" << "\n";
    }
    void fun()
    {
        cout << "Inside Fun of Demo Function" << "\n";
    }
};

// class Hello Extends Demo

// class Hello is derived from class Demo
// Child class is Hello
// Parent class is Demo
// class Hello is derived from class Demo
// here first the constructor of parent class is called and then the constructor of child class is called
// first child destructor is called and then parent destructor is called

class Hello : public Demo /// in this class object the size of this object is 20 bytes beacause of 2 int form parent class

{
public:
    int a, b, c;
    Hello()
    {
        cout << "Inside Default constructor of Hello" << "\n";
        a = 30;
        b = 40;
        c = 50;
    }
    ~Hello()
    {
        cout << "Inside Hello Destructor" << "\n";
    }
    void gun()
    {
        cout << "Inside gun of Hello Function" << "\n";
    }
};
int main()
{
    Hello hobj;
    cout << "Size of Hello class (hobj) is =" << sizeof(hobj) << "\n";   //Output : Size of Hello class (hobj) is =20
    //(total size of Hello class) (parent class + child class)= 8 (Demo class) + 12 (Hello class)=20 bytes
    cout << "Value of x=" << hobj.x << "\n";
    cout << "Value of y=" << hobj.y << "\n";
    cout << "Value of a=" << hobj.a << "\n";
    cout << "Value of b=" << hobj.b << "\n";
    cout << "Value of c=" << hobj.c << "\n";
    hobj.fun();
    hobj.gun();
    return 0;
}