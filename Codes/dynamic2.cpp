#include<iostream>
using namespace std;

class Demo 
{
    public:
        int i,j,k;

        Demo()
        {
            cout<<"Inside Constructor"<<endl;
        }

        ~Demo()
        {
            cout<<"Inside Destructor"<<endl;            
        }

        void Display()
        {
            cout<<"Inside Display Function"<<endl;
        }

};

int main()
{
    Demo *ptr = new Demo;  //

    ptr ->Display();

    delete ptr;

    return 0;
}