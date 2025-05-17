#include <iostream>
using namespace std;

class Demo
{
public:
    int i;
    int j;
    int k;
    // Here assingment is done in the constructor
    // becaus ethe initialization of the variable in the class directly is notgood programming practice
    // and also it is not possible to assign the value of the variable in the class directly
    // because the value of the variable is not known at that time.
    // Thats why we use constructor to assign the value of the variable
    // parameterized constructor
    // Demo(int a, int b, int c) : j(b), k(c)
    // in the above comment this format describes that  j = b and k = c
    // and also you can use this format in the constructor
    Demo(int a, int b, int c)
    {
        i = a;
        j = b;
        k = c;
    }
    // copy constructor
    void fun()
    {
        i++;
        j++;
        k++;
    }
    void gun(int x, const int y) const
    {
        int no1 = 10;
        const int no2 = 20;

        x++;
        // y++; // ❌ Error: Cannot modify a const variable
        no1++;
        // no2++; // ❌ Error: Cannot modify a const variable
        // i++;
        // j++;
        // k++;
    }
};

int main()
{
    Demo obj(11, 21, 51);
    obj.fun();
    obj.gun(51, 101);
    const Demo obj2(11, 21, 51);
    // obj2.fun(); // ❌ Error: Cannot modify a const object
    obj2.gun(51, 101);
    return 0;
}