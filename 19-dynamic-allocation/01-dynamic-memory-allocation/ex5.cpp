/* MEMORY LEAKS */

/*
Dynamically allocated memory stays allocated until it is explicitly deallocated or until the 
program ends (and the operating system cleans it up, assuming your operating system does that). 
However, the pointers used to hold dynamically allocated memory addresses follow the normal scoping 
rules for local variables. This mismatch can create interesting problems.

Consider the following code snippet:

void do_something()
{
    int* ptr { new int { 0 } };
}

This function allocates an integer dynamically, but never frees it using delete. Because pointers 
variables are just normal variables, when the function ends, ptr will go out of scope. And because 
ptr is the only variable holding the address of the dynamically allocated integer, when ptr is 
destroyed there are no more references to the dynamically allocated memory. This means the program 
has now “lost” the address of the dynamically allocated memory. As a result, this dynamically 
allocated integer can not be deleted.

This is called a memory leak. Memory leaks happen when your program loses the address of some bit 
of dynamically allocated memory before giving it back to the operating system. When this happens, 
your program can’t delete the dynamically allocated memory, because it no longer knows where it is. 
The operating system also can’t use this memory, because that memory is considered to be still in 
use by your program.

Although memory leaks can result from a pointer going out of scope, there are other ways that 
memory leaks can result. For example, a memory leak can occur if a pointer holding the address of 
the dynamically allocated memory is assigned another value:

Code snipet:
int value { 42 };
int* ptr { new int {} };    // allocate memory
ptr = &value;               // old address lost, memory leak results

This can be fixed by deleting the pointer before reassigning 

int value { 42 };
int* ptr { new int {} };    // allocate memory
delete ptr;                 // return memory back to operating system
ptr = &value;               // reassign pointer to address of value

Relatedly, it is also possible to get a memory leak via double-allocation

int* ptr { new int {} };
ptr = new int {};           // old address lost, memory leak results
The address returned from the second allocation overwrites the address of the first allocation. 
Consequently, the first allocation becomes a memory leak! Similarly, this can be avoided by 
ensuring you delete the pointer before reassigning.


Conclusion:

(1) Operators new and delete allow us to dynamically allocate single variables for our programs.
(2) Dynamically allocated memory has dynamic duration and will stay allocated until you deallocate 
    it or the program terminates.
(3) Be careful not to perform dereference a dangling or null pointers.
*/

#include <iostream>

int main()
{
    int value { 42 };
    int* ptr { new int { 24 } };
    std::cout << "*ptr = " << *ptr << '\n';

    // We should delete ptr to return memory back to operating system.
    delete ptr;
    // if the above statement is not there, old address lost, memory leak results
    ptr = &value;       

    
    std::cout << "*ptr = " << *ptr;
}