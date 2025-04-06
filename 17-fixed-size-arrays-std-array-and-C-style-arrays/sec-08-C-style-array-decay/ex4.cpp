/* The problems with array decay */

// Although array decay was a clever solution to ensure C-style arrays of 
// different lengths could be passed to a function without making expensive 
// copies, the loss of array length information makes it easy for several 
// types of mistakes to be made.

#include <iostream>

void print_array_size(int array[])
{
    std::cout << sizeof(array) << '\n'; // prints 40 (assuming 32-bit addresses)
}

int main()
{
    int array[]{ 1, 2, 3, 4, 5, 6, 6, 7, 8, 9, 0 };

    std::cout << sizeof(array) << '\n'; // prints 40 (assuming 4 byte ints)

    std::cout << "using function print_array_size():\n";
    print_array_size(array);        // decay to int* pointer.
    // The compiler will give you warning too.

    return 0;
}

/* LAST WORDS:

C-style arrays should be avoided in most cases

Because of the non-standard passing semantics (pass by address is used instead of pass 
by value) and risks associated with decayed arrays losing their length information, 
C-style arrays have generally fallen out of favor. We recommend avoiding them as much 
as possible.

BEST PRACTICE

Avoid C-style arrays whenever practical.

    * Prefer std::string_view for read-only strings (string literal symbolic constants and string parameters).
    * Prefer std::string for modifiable strings.
    * Prefer std::array for non-global constexpr arrays.
    * Prefer std::vector for non-constexpr arrays.

It is okay to use C-style arrays for global constexpr arrays.


========================================================
So when are C-style arrays used in modern C++?
========================================================

In modern C++, C-style arrays are typically used in two cases:

    To store constexpr global (or constexpr static local) program data. 
    Because such arrays can be accessed directly from anywhere in the 
    program, we do not need to pass the array, which avoids decay-related 
    issues. The syntax for defining C-style arrays can be a little less 
    wonky than std::array. More importantly, indexing such arrays does 
    not have sign conversion issues like the standard library container 
    classes do.

    As parameters to functions or classes that want to handle non-constexpr 
    C-style string arguments directly (rather than requiring a conversion 
    to std::string_view). There are two possible reasons for this: First, 
    converting a non-constexpr C-style string to a std::string_view requires 
    traversing the C-style string to determine its length. If the function 
    is in a performance critical section of code and the length isn’t needed 
    (e.g. because the function is going to traverse the string anyway) then 
    avoiding the conversion may be useful. Second, if the function (or class) 
    calls other functions that expect C-style strings, converting to a 
    std::string_view just to convert back may be suboptimal (unless you 
    have other reasons for wanting a std::string_view).
*/