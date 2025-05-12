#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{

    int iValue = 5;

    int *ptr = (int *) malloc (5 * sizeof(int));

    int *ptr1 = new int[5] ;

    free(ptr);

    delete [] ptr1;

    return 0;
}