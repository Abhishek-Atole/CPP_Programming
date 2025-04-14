#include<stdio.h>
#include<stdlib.h>

int main()
{
    int isize=0;              //4 Bytes
    int *ptr = NULL;            //4 Bytes   // here ptr is not poointing to any memory location because it is NULL

    printf("Enter the size of array\n");
    scanf("%d",&isize);                                 //assume that the user give 6 as a input
    ptr = (int *)calloc(isize, sizeof(int));            // difference between malloc and calloc is that malloc allocates memory in bytes and calloc allocates memory in blocks
    //here is typecasting is done to convert the void pointer to int pointer
    //c =  is knows as calculate and alloc is known as allocation
    ptr[0] = 10;
    ptr[1] = 11;
    ptr[2] = 12;   
    free(ptr);          // here free is used to deallocate the memory allocated by malloc
    ptr = NULL;     // here ptr is set to NULL after freeing the memory 
    return 0;
}
