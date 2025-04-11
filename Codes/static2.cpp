#include <iostream>
using namespace std;


//memory is allocated in the class is non static 
//static memory is allcated outside class
//:: Scope Resolution operator
//static = seperate (external)
// by default all varibles datatypes are non static
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
        cout << "Value of i : " << i << "\n";
        cout << "value of j : " << j << "\n";
    }
};

int Demo :: k = 111;

int main()
{
    cout<<"Value of k is : "<<Demo::k<<"\n";

    Demo obj1(11,21);
    Demo obj2(51,101);
    Demo obj3(101,151);

    cout<<"Size of object is : "<<sizeof(obj1)<<"\n";

    obj1.Display();
    obj2.Display();
    obj3.Display();
    return 0;
}
