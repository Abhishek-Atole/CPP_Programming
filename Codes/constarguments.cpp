#include<iostream>
using namespace std;

void Display(int i,const int j)
{
    int a =10 ;
    const int b = 20;
     i++;//A

     //j++; // NA

     a++;
     cout << "a: " << a << endl;
     cout << "b: " << b << endl;
     
     //b++ ; //NA
     
};


int main()
{
    Display(11,21);
    
    return 0;
}