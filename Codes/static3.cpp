#include <iostream>
using namespace std;

class Demo
{
public:
    int i = 0;
    int j = 0;
    static int k;
    Demo(int a = 10, int b = 20)
    {
        i = a;
        j = b;
    }

    void Display()
    {
        cout << "Inside Non Static Method Display \n\n";            //non static method of class can access static as welll ass non static characteristics
        cout << "Value of k : " << k << "\n";
        cout << "Value of i : " << i << "\n";
        cout << "value of j : " << j << "\n\n";
    }

    static void Fun()                           //static metod can not acces non static characteristics
    {
        cout << "Inside Static Methode Fun :  \n";
        cout << "Value of k : " << k << "\n";
    }
};

int Demo ::k = 111;

int main()
{
    cout << "Value of k is : " << Demo::k << "\n\n";
    Demo ::Fun();

    Demo obj1(11, 21);
    Demo obj2(51, 101);
    Demo obj3(101, 151);

    cout << "Size of object is : " << sizeof(obj1) << "\n\n";

    obj1.Display();
    obj2.Display();
    obj3.Display();

    obj1.Fun();

    return 0;
}
