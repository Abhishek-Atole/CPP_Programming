#include<iostream>

int add(int a, int b)
{
    return a + b;
}

int main()
{
int (*Fun_ptr)(int, int) = &add; // Function pointer declaration and initialization

std::cout << "Addition is : " << Fun_ptr(10, 20) << std::endl; // Function pointer call
std::cout << "Addition is : " << add(10, 20) << std::endl; // Direct function call
std::cout << "Addition is : " << (*Fun_ptr)(10, 20) << std::endl; // Function pointer call with dereferencing
std::cout << "Addition is : " << (*add)(10, 20) << std::endl; // Direct function call with dereferencing
    return 0;
}