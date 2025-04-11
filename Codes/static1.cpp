#include <iostream>
using namespace std;

class Demo
{
public:
    int i = 0;
    int j = 0;

    Demo(int a = 10, int b = 20)
    {
        i = a;
        j = b;
    }
    
    /* Demo()               it generates ambiguis error
    {} */ 
    void Display()
    {
        cout << "Value of i : " << i << "\n";
        cout << "value of j : " << j << "\n";
    }
};

int main()
{
    Demo obj1;
    obj1.Display();

    Demo obj2(11);
    obj2.Display();

    Demo obj3(100,250);
    obj3.Display();

    return 0;
}
