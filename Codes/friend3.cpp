#include <iostream>
using namespace std;

class Hello
{
public:
    int a;
    void Display();
};
class Demo
{
public:
    int a;

private:
    int b;

protected:
    int c;

public:
    Demo()
    {
        a = 10;
        b = 20;
        c = 30;
    }
    friend void Hello ::Display(); // Declare Display as a friend function
    // By write friend void Display(); we are giving access to all the members of class Demo to function Display
    // alll the members which are are non publublic are accessible to Display
};

void Hello :: Display()
{
    Demo obj;                        // object of class Demo is created
    cout << "a = " << obj.a << endl; // Accessible because it's public
    cout << "b = " << obj.b << endl; // Not accessible because it's private
    cout << "c = " << obj.c << endl; // Not accessible because it's protected and void display() is not a friend of Demo
    // and also it is not a derived class of Demo
}
int main()
{
    Hello obj1;
    obj1.Display();
    return 0;
}