/* Subscripting is implemented via pointer arithmetic */

// We noted that operator[] can be applied to a pointer. It turns out that subscript 
// operation ptr[n] is a concise syntax equivalent to the more verbose expression 
// *((ptr) + (n)). You will note that this is just pointer arithmetic, with some 
// additional parenthesis to ensure things evaluate in the correct order, and an 
// implicit dereference to get the object at that address.

#include <iostream>

int main()
{
    // We noted that operator[] can be applied to a pointer
    //======================================================
    const int a[] { 1, 2, 3 };

    const int* ptr{ a }; // a normal pointer holding the address of element 0
    std::cout << "ptr[2] = " << ptr[2] << '\n';   // subscript ptr to get element 2, prints 5

    const int b[] { 3, 2, 1 };

    // First, let us use subscripting to get the address and values of our array elements
    std::cout << "Using array subscripting:\n";
    for (int i {0}; i < 3; ++i)
        std::cout << "&b[" << i << "] = " << &b[i] << '\t'<< "b[" << i << "] = " << b[i] << '\n';

    std::cout << "Using pointer arithmetic:\n";
    // Now, let us do the equivalent using pointer arithmetic
    for (int i {0}; i < 3; ++i)
        std::cout << "b + " << i << " = " << b + i << '\t' << "*(b + " << i << ") = " << *(b + i) << '\n'; 


    return 0;
}