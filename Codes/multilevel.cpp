#include <iostream>
using namespace std;
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

//class Hello : extends Demo 
class Hello : public Demo 
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

//class Marvellous : extends Hello
class Marvellous : public Hello
{
public:
    int p;
    Marvellous()
    {
        cout << "Inside Default constructor of Marvellous" << "\n";
        p = 60;
    }
    ~Marvellous()
    {
        cout << "Inside Marvellous Destructor" << "\n";
    } 
    void sun()
    {
        cout << "Inside sun of Marvellous Function" << "\n";
    }  
};
int main()
{
    Marvellous mobj;        // this will call all the constructors in the hierarchy because of multilevel inheritance
    cout << "Size of Marvellous class (mobj) is =" << sizeof(mobj) << "\n";   
    cout << "Value of x=" << mobj.x << "\n";
    cout << "Value of y=" << mobj.y << "\n";
    cout << "Value of a=" << mobj.a << "\n";
    cout << "Value of b=" << mobj.b << "\n";
    cout << "Value of c=" << mobj.c << "\n";
    cout << "Value of p=" << mobj.p << "\n";
    mobj.fun();
    mobj.gun();
    mobj.sun();
    return 0;
}