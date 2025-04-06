#include <iostream>
#include <vector>

int main()
{
    std::vector prime { 2, 3, 5, 7, 11, 13 };


    /* Accessing array elements using operator[] does no bounds checking */
    std::cout << "prime[3] = " << prime[3] << '\n';  // print the value of element with index 3 (7)
    std::cout << "prime[9] = " << prime[9];  // invalid index (undefined behavior)

    /* Accessing array elements using the at() member function 
    does runtime bounds checking */


    std::cout << prime.at(3); // print the value of element with index 3
    std::cout << prime.at(9); // invalid index (throws exception)

    /* Because it does runtime bounds checking on every call, at() is slower (but safer) 
    than operator[]. Despite being less safe, operator[] is typically used over at(),
    primarily because it’s better to do bounds checking prior to indexing, 
    so we don’t try to use an invalid index in the first place. */

    /* Indexing std::vector with a constexpr signed int */
    constexpr int i { 3 };

    // okay: constexpr index implicitly converted to std::size_t, not a narrowing conversion
    std::cout << prime[i] << '\n';

    /* Indexing std::vector with a non-constexpr value */
    std::size_t j { 3 };
    // operator[] expects an index of type std::size_t, no conversion required
    std::cout << prime[j] << '\n';
    return 0;
}