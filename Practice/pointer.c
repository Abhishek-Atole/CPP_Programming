#include<stdio.h>

int main()
{
    int iValue = 10;
    int *pValue = &iValue; // Pointer to iValue
    int **ppValue = &pValue; // Pointer to pointer to iValue
    int ***pppValue = &ppValue; // Pointer to pointer to pointer to iValue

    printf("Value of iValue: %d\n", iValue);        // Value of iValue
    printf("Value of pValue : %p\n", pValue);   // Address of iValue    
    printf("Value of pValue: %d\n", *pValue);   // Value of iValue
    printf("Value of ppValue: %d\n", **ppValue);    // Value of iValue
    printf("Value of pppValue: %d\n", ***pppValue);   // Value of iValue

    return 0;

}