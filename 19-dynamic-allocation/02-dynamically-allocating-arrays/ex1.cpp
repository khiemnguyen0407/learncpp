/*
DYNAMICALLY ALLOCATING ARRAYS

In addition to dynamically allocating single values, we can also dynamically allocate arrays of 
variables. Unlike a fixed array, where the array size must be fixed at compile time, dynamically 
allocating an array allows us to choose an array length at runtime (meaning our length does not 
need to be constexpr).

While we can dynamically allocate a std::array, we are usually better off using a non-dynamically 
allocated std::vector in this case.


DYNAMICALLY DELETE ARRAYS

When deleting a dynamically allocated array, we have to use the array version of delete, 
which is delete[]. This tells the CPU that it needs to clean up multiple variables instead of a 
single variable. One of the most common mistakes that new programmers make when dealing with 
dynamic memory allocation is to use delete instead of delete[] when deleting a dynamically 
allocated array. Using the scalar version of delete on an array will result in undefined behavior, 
such as data corruption, memory leaks, crashes, or other problems.

One often asked question of array delete[] is, "How does array delete know how much memory to 
delete?"" The answer is that array new[] keeps track of how much memory was allocated to a 
variable, so that array delete[] can delete the proper amount. Unfortunately, this size/length 
isn't accessible to the programmer.

*/

#include <iostream>
#include <cstddef>

int main()
{
    std::cout << "Enter a positive integer for length of array: ";
    std::size_t length {};  // initialize to 0
    std::cin >> length;
    
    int* a { new int[length] {} };
    // We can also write the above code into two lines:
    int* b;
    b = new int[length];    // we do not initialize with list initialization here
    // If you compile and run the program several times, you may see different values for array b.

    a[0] = 42;
    b[0] = 24;

    for (int i {0}; i < length; ++i) {
        std::cout << "a[" << i << "] = " << a[i] << '\t';
    }
    std::cout << '\n';
    for (int i {0}; i < length; ++i) {
        std::cout << "b[" << i << "] = " << b[i] << '\t';
    }


    delete[] a; // use array delete to deallocate array -- Note the square brackets after delete
    delete[] b;

    // we don't need to set array to nullptr/0 here because it's going out of scope immediately 
    // after this anyway. Of course, we can do so if we want.
    a = nullptr;
    b = nullptr;

    return 0;
}