/* Dynamic arrays are almost identical to fixed arrays */

/*
In Section "C-style Array Decay", you learned that a fixed array holds the memory address of the 
first array element. You also learned that a fixed array can decay into a pointer that points to 
the first element of the array. In this decayed form, the length of the fixed array is not 
available (and therefore neither is the size of the array via sizeof()), but otherwise there is 
little difference.

A dynamic array starts its life as a pointer that points to the first element of the array. 
Consequently, it has the same limitations in that it doesn’t know its length or size. A dynamic 
array functions identically to a decayed fixed array, with the exception that the programmer is 
responsible for deallocating the dynamic array via the delete[] keyword.

RESIZING ARRAYS
================================================================================================
Dynamically allocating an array allows you to set the array length at the time of allocation. 
However, C++ does not provide a built-in way to resize an array that has already been allocated. 
It is possible to work around this limitation by dynamically allocating a new array, copying the 
elements over, and deleting the old array. However, this is error prone, especially when the 
element type is a class (which have special rules governing how they are created).

Consequently, we recommend avoiding doing this yourself. Use std::vector instead.
*/

#include <iostream>
void print_array(int* ptr, int size)
{
    for (int i { 0 }; i < size; ++i)
        std::cout << ptr[i] << '\t';
    std::cout << '\n';
}
int main()
{
    // Initializing dynamically allocated arrays
    // If you want to initialize a dynamically allocated array to 0, the syntax is quite simple:
    int* a { new int[5] {}};

    // Prior to C++11, there was no easy way to initialize a dynamic array to a non-zero value 
    // (initializer lists only worked for fixed arrays). This means you had to loop through the 
    // array and assign element values explicitly. Super annoying!!!

    // Starting with C++11, it's possible to initialize dynamic arrays using initializer lists!

    // initialize a fixed array before C++11
    // explicitly stating the size of the array is optional
    int fixed_array[] { 1, 2, 3, 4, 5, 6, 7 }; 
    
    // initialize a dynamic array since C++11
    int* b { new int[7] { 7, 6, 5, 4, 3, 2, 1 } };

    // To prevent writing the type twice, we can use auto. This is often done for types 
    // with long names.
    auto* c { new int[] { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 } };

    std::cout << "a =\n";
    print_array(a, 5);

    std::cout << "fixed_array =\n";
    print_array(fixed_array, 7);

    std::cout << "b =\n";
    print_array(b, 7);

    std::cout << "c =\n";
    print_array(c, 10);

}