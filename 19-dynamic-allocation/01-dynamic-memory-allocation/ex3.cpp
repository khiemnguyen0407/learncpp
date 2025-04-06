/* Dangling pointers: Part 2 */

#include <iostream>

// Deallocating memory may create multiple dangling pointers. 
// Consider the following example:
int main()
{
    int* ptr{ new int };    // dynamically allocate an integer
    int* other_ptr { ptr }; // other_ptr is now pointed at the same memory location
    *ptr = 42; // put a value in that memory location

    delete ptr; // return the memory to the operating system.  ptr is now a dangling pointer.
    ptr = nullptr;      // ptr is now a null pointer


    // However, other_ptr is still a dangling pointer at this point.
    // This pointer will be quickly destroyed at the end of this program. But it is dangerous to
    // have dangling pointers staying around in the program.
    std::cout << "other_ptr = " << other_ptr << '\n';

    // this is dangerous as the memory has been freed.
    // Dereferencing other_ptr leads to undefined behavior. Indeed, the results can be different
    // in different compilations.
    std::cout << "*other_ptr = " << *other_ptr;     

    // Of course, we can set other_ptr = nullptr
    other_ptr = nullptr;

    return 0;
}

/* Further discussion:

There are a few best practices that can help deal with dangling pointers.alignas

(1) First, try to avoid having multiple pointers point at the same piece of dynamic memory. 
    If this is not possible, be clear about which pointer "owns" the memory (and is 
    responsible for deleting it) and which pointers are just accessing it.

(2) Second, when you delete a pointer, if that pointer is not going out of scope 
    immediately afterward, set the pointer to nullptr. We’ll talk more about null pointers, 
    and why they are useful in a bit.

*/