#include <iostream>
using namespace std;

class Hello
{
    public:
        void Display();   //function is defined outside the class
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
//Return_type_value class_Name :: function_name
void Hello :: Display() // it just like a member function of class Hello
{
    Demo obj;                        // object of class Demo is created
    cout << "a = " << obj.a << endl; // Accessible because it's public
    cout << "b = " << obj.b << endl; // Accessible because it's private and Display() is a friend of Demo
    cout << "c = " << obj.c << endl; // Accessible because it's protected and Display() is a friend of Demo
}

int main()
{
    Hello hobj;
    hobj.Display();
    return 0;
} 