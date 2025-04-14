#include<iostream>
#include<stdlib.h> // stdlib.h is used for malloc and free beacaue this header file contains the declaration of malloc and free functions
using namespace std;

int main()
{
    int Arr[5];             //20 Bytes
    int *ptr1 = (int *)malloc(5 * sizeof(int)); // 20 Bytes             //Dynamic in C programming



    int *ptr2 = new int[5]; // 20 Bytes                         //Dynamic in C++ programming

    free(ptr1); // free the memory allocated by malloc (for C programming)
    delete[] ptr2; // free the memory allocated by new (for C++ programming)

    return 0;   
}