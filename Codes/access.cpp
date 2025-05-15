

/*

    Here, In the Class The Bydefault access specifer is Private.add_pointer

        1)  Public : For Public Specifier all the contentis avaliable  for all the external function and internal function.

        2)  Private : In private all the data is accessible to same class only.

        3)  Protected :In private the data is accessible to the same class and immediate child class.

*/

#include <iostream>
using namespace std;

class Demo
{
    int i;

public:
    int j;

private:
    int k;

protected:
    int a;

public:
    Demo()
    {
        i = 10;
        j = 20;
        k = 30;
        a = 40;
    }

    void Display()
    {
        cout << "Value of i is : " << i << endl; // Allowed
        cout << "Value of j is : " << j << endl; // Allowed
        cout << "Value of k is : " << k << endl; // Allowed
        cout << "Value of a is : " << a << endl; // Allowed
    }
};

int main()
{
    Demo obj;           //Object is created and memry is allocated here.

    // Main section is also the external function.

    cout<<"Value of i : "<<obj.i<< endl;    //Not Allowed because this is private  access variable.
    cout << "Value of j : " << obj.j << endl; // Allowed because this is public access variable.
    cout<<"Value of k : "<<obj.k << endl;     //Not Allowed because it is private access variable.
    cout<<"Value of a : "<< obj.a << endl;    //Not Allowed because it is protected access variable.
    obj.Display(); // Display(&obj)
    return 0;
}
