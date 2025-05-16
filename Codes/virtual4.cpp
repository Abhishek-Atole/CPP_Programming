#include <iostream>
using namespace std;

class Base
{
public:
    int i, j, k;
    virtual void Fun() // 1000
    {
        cout << "Inside Fun Function" << endl;
    }
    virtual void Gun() // 2000
    {
        cout << "inside Gun Function" << endl;
    }
    void Sun() // 3000
    {
        cout << "Inside Sun Function" << endl;
    }
    void Run() // 4000
    {
        cout << "Inside Run Function" << endl;
    }
};

class Derived : public Base
{
public:
    int a, b;

    void Gun() // 5000
    {
        cout << "inside Derived Gun Function" << endl;
    }
    void Run() // 6000
    {
        cout << "Inside Derived Run Function" << endl;
    }

    virtual void Mun()
    {
        cout << "Inside Derived  Mun" << endl;
    }
};

int main()
{

    cout << sizeof(Base) << endl;
    cout << sizeof(Derived) << endl;

    Base *bp = new Derived; // UC
    bp->Fun();
    bp->Gun();
    bp->Run();
    bp->Sun();
    // bp ->Mun();

    return 0;
}