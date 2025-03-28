#include<iostream>  // Include the standard input-output stream library
using namespace std;

class Demo
{
    public:
        int i;  // Member variable i
        int j;  // Member variable j

        // Default Constructor  
        // Direct Jaun Ganpati gheun ghari yene without any specific requirement  
        // is called a default constructor (No arguments are needed).  
        Demo()
        {
            cout << "Inside Default Constructor\n"; // Message indicating constructor execution
            i = 0;  // Initialize i to 0    
            j = 0;  // Initialize j to 0

        }

        // Parameterized Constructor  
        // Ganpati basnyacha thodya divas aadhi jaun, tya murtikarala requirements sangun,  
        // just like "red patal, yellow feta, black undir," he sangun murti banvun ghyane  
        // is called a parameterized constructor (Giving values while creating an object).
        Demo(int A, int B)
        {
            cout << "Inside Parameterized Constructor\n"; // Message indicating constructor execution
            i = A;  // Assign value of A to i
            j = B;  // Assign value of B to j
            cout << "A: " << A << "\n";  // Print value of A
            cout << "B: " << B << "\n";  // Print value of B
            cout << "i: " << i << "\n";  // Print assigned value of i
            cout << "j: " << j << "\n";  // Print assigned value of j
        }

        // Copy Constructor  
        // Murtikarala ek photo dakhvun, "Mala heech murti havi" mhun tyach photo sarkhi  
        // exact copy banvun ghyane is called a copy constructor (Creating an object by copying another object).
        Demo(Demo &ref)
        {
            cout << "Inside Copy Constructor\n"; // Message indicating constructor execution
            i = ref.i;  // Copy value of i from the reference object
            j = ref.j;  // Copy value of j from the reference object
            cout << "Copied i: " << i << "\n";  // Print copied value of i
            cout << "Copied j: " << j << "\n";  // Print copied value of j
        }
        ~Demo() // tild - bitwise operator who performs destructor work
        //The Demo class has an inline destructor that outputs "Inside Destructor" to the console when an object of the class is destroyed
        {
            cout<<"Inside Destructor\n";
        }
};

int main()
{
    Demo obj1;        // Calls Default Constructor - Brings Ganpati home without asking for details  
    Demo obj2(11,22); // Calls Parameterized Constructor - Gives specific instructions before making the idol  
    Demo obj3(obj2);  // Calls Copy Constructor - Makes an exact copy of an existing idol  

    return 0; // End of program
}
