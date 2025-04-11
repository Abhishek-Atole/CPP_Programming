#include<iostream>
using namespace std;

class Demo
{
    public:
        int x,y;

        Demo()
        {
            cout<<"Inside Demo Constructor\n";
            x= 10;
            y = 20;

        }

        ~Demo()
        {
            cout<<"Inside Demo Destructor \n";
        }
        void Fun()
        {
            cout<<"Inside Fun of Demo \n";
        }
}