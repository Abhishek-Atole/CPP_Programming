#include<iostream>
using namespace std;

class Demo
{
    public:
        int i,j,k;
        Demo()
        {
            cout<<"Inside Default Constructor\n";
        }
        ~Demo()
        {
            cout<<"Inside Destructor\n";
        }
        void Display()
        {
            cout<<"Inside Display\n";
        }
};

int main()
{
    Demo *ptr = (Demo *) malloc(sizeof(Demo)); // here new is used to allocate the memory in heap    (Demo is the class name)
    ptr ->Display();

    free(ptr); // here delete is used to deallocate the memory allocated by new
    return 0;   
}