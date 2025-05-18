#include <iostream>
using namespace std;
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
    friend void Display(); // Declare Display as a friend function
    // By write friend void Display(); we are giving access to all the members of class Demo to function Display  
    // alll the members which are are non publublic are accessible to Display
};

    void Display()
{
    Demo obj;                        // object of class Demo is created
    cout << "a = " << obj.a << endl; // Accessible because it's public
    cout << "b = " << obj.b << endl; // Not accessible because it's private
    cout << "c = " << obj.c << endl; // Not accessible because it's protected and void display() is not a friend of Demo
    // and also it is not a derived class of Demo
}
int main()
{
    Display();
    return 0;
}