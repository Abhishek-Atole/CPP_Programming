#include<stdio.h>
#include<stdlib.h>
s
int main()
{
    int Arr[5];             //20 Bytes
    float fValue;           //4 Bytes
    double Brr[4];           //32 Bytes    

    int isize=0;              //4 Bytes
    int *ptr = NULL;            //4 Bytes   // here ptr is not poointing to any memory location because it is NULL

    printf("Enter the size of array\n");
    scanf("%d",&isize);                                 //assume that the user give 6 as a input
    ptr = (int *)malloc(isize * sizeof(int));       // here m is for memory and alloc is for allocation

    //here is typecasting is done to convert the void pointer to int pointer
    //typecating is konwn as casting a perticular action for some  time

    // isize = 6 * sizeof(int);   // here isize is 6 and sizeof(int) is 4 so total size is 24 Bytes
    //after that the heap memory is allocated of 24 Bytes
    //ptr = (int *)malloc(6 * 4);   // here malloc is used to allocate 24 Bytes of memory in heap
    //the capacity of the int * is 4 Bytes
    //if the their is int ** then the capacity of the int ** is 8 Bytes

    //why malloc is used : to allocate memory dynamically for the array of size isize
    //malloc is used to allocate memory in heap
    //malloc returns a void pointer, so we need to typecast it to int *
    //malloc returns the address of the first byte of the allocated memory
    //malloc returns NULL if the memory allocation fails
    //malloc returns a pointer to the allocated memory
    //malloc returns a pointer to the first byte of the allocated memory
    //malloc returns a pointer to the allocated memory
    //malloc returns a pointer to the first byte of the allocated memory
    //malloc returns a pointer to the allocated memory
    //malloc returns a pointer to the first byte of the allocated memory
    //malloc returns a pointer to the allocated memory
    





    ptr[0] = 10;
    ptr[1] = 20;
    ptr[2] = 30;   
    free(ptr);          // here free is used to deallocate the memory allocated by malloc
    ptr = NULL;     // here ptr is set to NULL after freeing the memory 
    return 0;
}

//void *malloc(size_t size);

//void free(void *ptr);

//allocate - - use -- free the memory in c and c++