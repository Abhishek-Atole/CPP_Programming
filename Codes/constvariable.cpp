#include <iostream>
using namespace std;

class Base {
public:
    int i;                // Non-const data member
    const int j = 0;      // Constant data member (initialized at declaration)

    void Increament(int a = 10, int b = 20)
    {
        i = a;
        // j = b;         // ❌ Error: Cannot assign to const variable
        cout << "Inside Increament Function" << endl;
        i++;
        // j++;           // ❌ Error: Cannot modify a const variable
    }

    ~Base()
    {
        cout << "Inside Destructor" << endl;
    }
};

int main()
{
    Base obj;
    obj.Increament();       // Sets i to 10, then increments it to 11
    // obj.j = 30;          // ❌ Error: Cannot modify const variable

    obj.i = 42;             // ✅ Valid modification
    cout << "i: " << obj.i << endl;
    cout << "j: " << obj.j << endl;
    cout << "j is constant variable, that's why it's not changed" << endl;

    return 0;
}
