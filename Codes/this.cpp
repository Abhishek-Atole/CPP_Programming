#include <iostream>             // Includes standard I/O stream for input/output operations
using namespace std;           // To avoid using std:: prefix repeatedly

// Class Definition Begins
class Demo
{
public:
    int i, j, k;               // Three public data members of the class

    // Constructor with default arguments
    // Called automatically when an object is instantiated
    // Default values provided: a = 10, b = 30, c = 40
    Demo(int a = 10, int b = 30, int c = 40)
    {
        // 'this' is an implicit pointer passed to all non-static member functions
        // It points to the calling object
        cout << "Value of this : " << this << "\n";

        // Using 'this' pointer to distinguish between class members and parameters
        this->i = a;
        this->j = b;
        this->k = c;
    }

    // Fun(Demo *this, int a, int b) -- this is what the compiler converts it to internally
    void Fun(int No1, int No2)
    {
        // No1 and No2 are received but not used — focus here is on accessing class members
        cout << "Inside Fun\n";

        // Access and display object-specific values using 'this'
        cout << "Value of i : " << this->i << "\n";
        cout << "value of j : " << this->j << "\n";
        cout << "Value of k : " << this->k << "\n";
    }

    void Display()
    {
        cout << "Inside Display Function : \n";
        
        // Display the memory address of the object (same as &object in main)
        cout << "Value of this pointer is : " << this << "\n";
    }
};

// Main Function – Entry point of the program
int main()
{
    // Object Creation – Constructor is called
    Demo obj1;                // Demo(&obj1, 10, 30, 40); → uses default values

    Demo obj2(11, 21, 51);    // Demo(&obj2, 11, 21, 51); → uses user-defined values

    // Member function call
    obj1.Fun(5, 6);           // Fun(obj1, 5, 6);
                              // Internally becomes: Fun(&obj1, 5, 6);

    obj2.Fun(8, 9);           // Fun(obj2, 8, 9)
                              // Internally becomes: Fun(&obj2, 8, 9)

    // Print object address using main function
    cout << "Address of Obj1 is  : " << &obj1 << "\n";

    obj1.Display();           // Display(&obj1);
                              // Internally becomes: Display(100); ← if we imagined address

    cout << "Address of obj2 is : " << &obj2 << "\n";

    obj2.Display();           // Display(&obj2);
                              // Internally becomes: Display(200);

    return 0;                 // Exit status: success
}
