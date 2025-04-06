/* Range-based for loops and other standard container types */

/* Range-based for loops work with a wide variety of array types, 
including (non-decayed) C-style arrays, std::array, std::vector, 
linked list, trees, and maps. We haven’t covered any of these yet, 
so don’t worry if you don’t know what these are. Just remember 
that range-based for loops provide a flexible and generic way to 
iterate through more than just std::vector: */

#include <array>
#include <iostream>

int main()
{
    std::array fibonacci{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 }; // note use of std::array here

    for (auto number : fibonacci)
    {
        std::cout << number << '\t';
    }

    std::cout << '\n';

    return 0;
}
