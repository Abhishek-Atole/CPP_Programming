#include <iostream>
using namespace std;

class Hello
{
    public:
        void fun();
        void gun();
};

class Demo
{
    public: int i;
    private:int j;
    protected: int k;
    public:

        Demo()              //constructor  and Constructor should be  in a Public Section
        {
            i = 10 ;  j = 20;  k = 30;
        }
        friend class Hello;         // friend class
};

void Hello :: fun()
{
    Demo obj;   
    cout<<"Value of i is : "<<obj.i<<endl;
    cout<<"Value of j is : "<<obj.j<<endl;
    cout<<"Value of k is : "<<obj.k<<endl;

}

void Hello :: gun()
{
    Demo obj;
    cout<<"Value of i is : "<<obj.i<<endl;
    cout<<"Value of j is : "<<obj.j<<endl;
    cout<<"Value of k is : "<<obj.k<<endl;

}
int main()
{
    Hello hobj;
    hobj.fun();
    hobj.gun();
    return 0;
}