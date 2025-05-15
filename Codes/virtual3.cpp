#include <iostream>
using namespace std;

class Base
{
public:
    int i, j, k;
    void Fun() { cout << "Inside Fun Function" << endl; }
    void Gun() { cout << "inside Gun Function" << endl; }
    void Sun() { cout << "Inside Sun Function" << endl; }
    void Run() { cout << "Inside Run Function" << endl; }
};

class Derived : public Base
{
public:
    int a, b;

    void Gun() { cout << "inside Derived Gun Function" << endl; }
    void Run() { cout << "Inside Derived Run Function" << endl; }
};

int main()
{
    Base *bp = new Derived; // UC
    bp->Fun();
    bp->Gun();
    bp->Run();
    bp->Sun();

    return 0;
}