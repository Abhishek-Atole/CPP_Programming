#include <iostream>
using namespace std;

class Demo {
private:
    int i; // Private member, accessible only within this class

public:
    int j; // Public member, accessible everywhere

private:
    int k; // Private member, accessible only within this class

protected:
    int a; // Protected member, accessible in this class and its derived classes

public:
    Demo() {
        i = 10;
        j = 20;
        k = 30;
        a = 40;
    }

    void Display() {
        cout << "Value of i is: " << i << endl; // Allowed (private, accessible within class)
        cout << "Value of j is: " << j << endl; // Allowed (public)
        cout << "Value of k is: " << k << endl; // Allowed (private, accessible within class)
        cout << "Value of a is: " << a << endl; // Allowed (protected, accessible within class)
    }
};

class Hello : public Demo {
public:
    void HelloDisplay() {
        // cout << "Value of i is: " << i << endl; // Error: 'i' is private in Demo, inaccessible here
        cout << "Value of j is: " << j << endl; // Allowed (public, inherited from Demo)
        // cout << "Value of k is: " << k << endl; // Error: 'k' is private in Demo, inaccessible here
        cout << "Value of a is: " << a << endl; // Allowed (protected, accessible in derived class)
    }
};

int main() {
    Demo dobj; // Object of Demo class to access public members and methods
    Hello hobj; // Object of Hello class (derived from Demo)

    cout << "Inside Demo Class:" << endl;
    dobj.Display(); // Call Display() from Demo class using dot operator

    cout << "\nChild Level Class of Demo Class:" << endl;
    hobj.HelloDisplay(); // Call HelloDisplay() from Hello class using dot operator

    return 0;
}



/*      Output

Inside Demo Class:
Value of i is: 10
Value of j is: 20
Value of k is: 30
Value of a is: 40

Child Level Class of Demo Class:
Value of j is: 20
Value of a is: 40

*/