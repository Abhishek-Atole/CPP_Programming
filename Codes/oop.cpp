#include <iostream>
using namespace std;
class Demo
{
public:
    int i;
    int j;

    void fun()
    {
        cout << "Inside Fun of Demo Class\n";
    }
};

int main()
{
    Demo obj1;
    Demo obj2;

    obj1.i = 11;
    obj1.j = 21;

    obj2.i = 31;
    obj2.j = 41;

    obj1.fun();
    obj2.fun();
    return 0;
}