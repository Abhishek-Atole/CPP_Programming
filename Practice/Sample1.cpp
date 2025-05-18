#include<iostream>
using namespace std;

int Fun(int a)
{
    a += 10;
    return a;
}
int main()

{
    int a = 5;
    Fun(a);
    cout << "a = " << a << endl; // Output: a = 5
    return 0;
}