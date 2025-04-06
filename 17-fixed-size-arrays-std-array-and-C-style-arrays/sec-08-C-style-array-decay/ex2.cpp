/* Array to pointer conversions -- Array decay */

// In most cases, when a C-style array is used in an expression, the array will 
// be implicitly converted into a pointer to the element type, initialized with 
// the address of the first element (with index 0). Colloquially, this is called 
// array decay (or just decay for short).


#include <iomanip>      // for std::boolalpha
#include <iostream>

int main()
{
    int array[5] { 1, 2, 3, 4, 5 };     // our array has elements of type int

    // First, let's prove that array decays into an int* pointer
    auto ptr { array };     // evaluation causes array to decay, type deduction should deduce type int*
    std::cout << "Whether (typeid(ptr) == typeid(int*)) is true or false: " << std::boolalpha << (typeid(ptr) == typeid(int*)) << '\n';
    std::cout << "Whether (typeid(ptr) == typeid(int*)) is true or false: " << (typeid(ptr) == typeid(int*)) << '\n';

    // Now let's prove that the pointer holds the address of the first element of the array
    std::cout << std::boolalpha << (&array[0] == ptr) << '\n';

    return 0;
}

// There is nothing special about the pointer that an array decays into. 
// It is a normal pointer that holds the address of the first element.
// Similarly, a const array (e.g. const int arr[5]) decays into a 
// pointer-to-const (const int*).
/*
In C++, there are a few common cases where an C-style array doesn’t decay:

    (1) When used as an argument to sizeof() or typeid().
    (2) When taking the address of the array using operator&.
    (3) When passed as a member of a class type.
    (4) When passed by reference.
*/