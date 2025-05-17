#include <iostream>
using namespace std;

class Demo
{
public:
    int i;
    const int j;
    const int k;
    // parameterized constructor
    Demo(int a, int b, int c) : j(b), k(c)
    {
        i = a;
    }
};
int main()
{
    Demo obj(10, 20, 30);
    cout << "i: " << obj.i << endl;
    cout << "j: " << obj.j << endl;
    cout << "k: " << obj.k << endl;

    obj.i = 40; // ✅ Valid modification
    cout << "i after modification: " << obj.i << endl;

    obj.i++;
    cout << "i after increment: " << obj.i << endl;
    // obj.j = 40; // ❌ Error: Cannot modify a const variable
    // obj.k = 50; // ❌ Error: Cannot modify a const variable

    return 0;
}