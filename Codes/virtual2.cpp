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
    /* Representation of No-casting, UP-Casting  */
    return 0;
}
