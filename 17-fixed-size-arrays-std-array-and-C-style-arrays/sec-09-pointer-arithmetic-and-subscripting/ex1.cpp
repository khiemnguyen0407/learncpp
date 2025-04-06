/* Pointer arithmetic */

// Pointer arithmetic is a feature that allows us to apply certain integer 
// arithmetic operators (addition, subtraction, increment, or decrement) 
// to a pointer to produce a new memory address.


#include <iostream>

int main()
{
    int x {};
    const int* ptr{ &x }; // assume 4 byte ints

    for (int i {0}; i < 5; ++i)
        std::cout << "ptr + " << i << " = " << ptr + i << '\n';
    std::cout << '\n';
    
    // Given some pointer ptr, ptr - 1 returns the address of the previous object in 
    // memory (based on the type being pointed to)
    for (int i {0}; i < 5; ++i)
        std::cout << "ptr - " << i << " = " << ptr - i << '\n';

    return 0;
}