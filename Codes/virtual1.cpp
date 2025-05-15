#include<iostream>
using namespace std;

// Base class declaration
class Base
{
public:
    int i, j, k; // Data members of the base class

    // Member function of the base class
    void fun()
    {
        cout << "Inside Base Fun" << endl;
    }
};

// Derived class inheriting from Base class
class Derived : public Base
{
public:
    int a, b; // Additional data members of the derived class

    // Member function of the derived class
    void Gun()
    {
        cout << "Inside Derived Gun" << endl;
    }
};

int main()
{
    Base bobj;     // Object of base class
    Derived dobj;  // Object of derived class

    // Displaying size of objects
    cout << "Size of Base class object: " << sizeof(bobj) << " bytes" << endl;
    cout << "Size of Derived class object: " << sizeof(dobj) << " bytes" << endl;

    // Calling base class function using base class object
    bobj.fun();  // Calls Base::fun()  
    // ( Here base class object is of 12 bytes because it has 3 int varisbles)

    // Calling inherited function using derived class object
    dobj.fun();  // Inherited from Base class

    // Calling derived class function
    dobj.Gun();  // Specific to Derived class   
    //( But in derived class it is of 20 bytes beacese of prent (Base) class is 12 bytes and derived (child) class is of 8 bytes -total 20 bytes)

    return 0;
}
