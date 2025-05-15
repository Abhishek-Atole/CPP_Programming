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
        cout << "Inside Derived Gun" << endl;
    }
};

int main()
{
    /* 
     * No-Casting (Base pointer to Base object)
     * Base class pointer 'bp1' is created and points to a Base class object.
     * Both the pointer and the object are of the same type and size (Base class, 12 bytes).
     */
    Base *bp1 = new Base;

    /*
     * No-Casting (Derived pointer to Derived object)
     * Derived class pointer 'dp1' is created and points to a Derived class object.
     * Both the pointer and object match in type and size (Derived class, 20 bytes).
     */
    Derived *dp1 = new Derived;

    /*
     * Up-Casting (Base pointer to Derived object)
     * Base class pointer 'bp2' points to a Derived class object.
     * This is valid and safe in C++ because a Derived object **is-a** Base object (Base subobject exists inside Derived).
     * However, bp2 can only access Base class members (i, j, k, and fun()), not members specific to Derived (a, b, and Gun()).
     * This is known as "object slicing" in a broader sense (though not slicing in this specific context since we're using pointers).
     */
    Base *bp2 = new Derived;

    /*
     * Down-Casting (Derived pointer to Base object)
     * This is **not allowed** directly and will result in a compilation error without an explicit cast.
     * A Base object does not contain Derived class members (a, b), so trying to treat a Base as a Derived is unsafe.
     * C++ requires the use of explicit casting (e.g., `dynamic_cast`) and proper runtime checks when down-casting.
     *
     * Example (would require virtual functions to enable RTTI and safe dynamic_cast):
     * Derived *dp2 = dynamic_cast<Derived*>(bp1);  // Safe only if bp1 actually points to a Derived object.
     */
    // Derived *dp2 = new Base; // Invalid: cannot assign Base object to a Derived pointer (Unsafe Down-Casting)

    return 0;
}
