/* Subscripting a C-style array actually applies operator[] to the decayed pointer */

// Because a C-style arrays decays to a pointer when evaluated, when a 
// C-style array is subscripted, the subscript is actually operating on 
// the decayed array pointer:

// When passing a C-style array as an argument, the array decays into 
// a pointer, and the pointer holding the address of the first element 
// of the array is what gets passed to the function. So although it looks 
// like we’re passing the C-style array by value, we’re actually passing 
// it by address! This is how making a copy of the C-style array argument 
// is avoided.

// Key insights:
// C-style arrays are passed by address, even when it looks like they are 
// passed by value.

// Two C-style arrays with the same element type but different lengths 
// will decay into the same pointer type.
#include <iostream>


// See the comment in the end of this program.
void print_first_element_using_pointer(const int* array) // pass by constant address
{
    std::cout << array[0];
}

void print_first_element_using_array(const int array[])
{
    std::cout << array[0];
}

int main()
{
    const int array[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // subscript decayed array to get element 2.
    std::cout << "Print array using array: \n";
    for (int i {0}; i < 10; ++i)
        std::cout << array[i] << '\t';      
    std::cout << '\n';
    // We can also use operator[] directly on a pointer. If that pointer is 
    // holding the address of the first element, the result will be identical:
    const int* ptr {array};
    std::cout << "Print array using pointer ptr: \n";
    for (int i {0}; i < 10; ++i)
        std::cout << ptr[i] << '\t';
    std::cout << std::endl;

    const int primes[] { 2, 3, 5, 7, 11 };  // 5 elements
    const int squares[] { 1, 4, 9, 16, 25, 36, 49, 64, 81}; // 9 elements
    std::cout << "primes[0] = ";
    print_first_element_using_pointer(primes);        // primes decays to a const int* pointer
    std::cout << "\nsquares[0]= ";
    print_first_element_using_pointer(squares);       // squares decays to a const int* pointer

    std::cout << "primes[0] = ";
    print_first_element_using_array(primes);    // different syntax but the array decays to const int* pointer
    std::cout << "\nsquares[0]= ";
    print_first_element_using_array(squares);   // different syntax but the array decays to const int* pointer

}

/* Remark: 
One problem with declaring the function parameter as int* arr is that it's not obvious 
that arr is supposed to be a pointer to an array of values rather than a pointer to 
a single integer. For this reason, when passing a C-style array, its preferable to 
use the alternate declaration form int arr[].

Using const int array[] in the function declaration, the compiler will interpret function 
parameter const int arr[] the same as const int*. However, this has the advantage of 
communicating to the caller that arr is expected to be a decayed C-style array, not a 
pointer to a single value. Note that no length information is required between the square 
brackets (since it is not used anyway). If a length is provided, it will be ignored.

BEST PRACTICE:
A function parameter expecting a C-style array type should use the array syntax 
(e.g. int arr[]) rather than pointer syntax (e.g. int *arr).
*/