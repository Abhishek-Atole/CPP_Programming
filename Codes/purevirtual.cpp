#include<iostream>
using namespace std;
// Base class declaration
class Base
{
public:
    int i, j, k; // Data members of the base class (3 integers, 4 bytes each = 12 bytes total)

    // Member function of the base class
    void fun()
    {
        cout << "Inside Base Fun" << endl;
    }
    virtual void Gun()
    {
        cout << "inside Base Gun Function" << endl;
    }
    //abstract function
    virtual int addition(int a, int b) = 0;
    // Pure virtual function
    // This function must be overridden in derived classes
    // and cannot be called directly from the base class
    // It makes the base class abstract

    
};
// Derived class inheriting from Base class
class Derived : public Base
{
public:
    int a, b; // Additional data members of the derived class (2 integers, 4 bytes each = 8 bytes)
              // Total size of Derived object = 12 (Base) + 8 (Derived) = 20 bytes
    // Member function of the derived class
    void Gun()
    {
        cout << "inside Derived Gun Function" << endl;
    }
    virtual void Sun()
    {
        cout << "Inside Derived Sun Function" << endl;
    }
    // Overriding the pure virtual function from the base class
    int addition(int a, int b)
    {
        return a + b;
    }

};

int main()
{
    
     
    //Base bobj; // Base class object
    cout << "Size of Base class: " << sizeof(Base) << endl; // Size of Base class object
    cout << "Size of Derived class: " << sizeof(Derived) << endl; // Size of Derived class object

    Derived dobj; // Derived class object

    Base *bp = new Derived; // UC
    bp->fun();
    bp->Gun();

    int Ret = bp->addition(10, 20);
    cout << "Addition is: " << Ret << endl;
    // bp ->Sun(); // This will not work because Sun() is not a member of Base class
    // To call Sun(), we need to cast the Base pointer to a Derived pointer

    return 0;
}