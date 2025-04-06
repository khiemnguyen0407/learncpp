#include <iostream>
#include <vector>

/* One of the defining characteristics of arrays is that the elements are always 
allocated contiguously in memory, meaning the elements are all adjacent 
in memory (with no gaps between them). */

int main()
{
    std::vector primes { 2, 3, 5, 7, 11 }; // hold the first 5 prime numbers (as int)

    std::cout << "An int is " << sizeof(int) << " bytes\n";
    for (unsigned int i {0}; i < primes.size(); i++) {
        std::cout << "Address of primes[" << i << "] = " << &primes[i] << '\n';
    }


    /* const and constexpr with std::vector */

    /* A const std::vector must be initialized, and then cannot be modified. 
    The elements of such a vector are treated as if they were const. The element type 
    of a std::vector must not be defined as const 
    (e.g. std::vector<const int> is disallowed). 
    */
    const std::vector<int> v {-5, -4, -3, -2, -1, 0, 1, 2, 2, 3, 4, 5};
    // Now, we cannot change the element of v.
    // v[0] = 1;       // compilation error

    // The standard library containers were not designed to have const elements.
    // A containers const-ness comes from const-ing the container itself, not the elements.


    /* =============================================================================
    Why is it called a vector?
    ================================================================================
    When people use the term “vector” in conversation, they typically mean a geometric vector, 
    which is an object with a magnitude and direction. So how did std::vector get its name 
    when it’s not a geometric vector?

    In the book “From Mathematics to Generic Programming”, Alexander Stepanov wrote, 
    “The name vector in STL was taken from the earlier programming languages Scheme 
    and Common Lisp. Unfortunately, this was inconsistent with the much older meaning 
    of the term in mathematics… this data structure should have been called array. 
    Sadly, if you make a mistake and violate these principles, the result might stay 
    around for a long time.”

    So, basically, std::vector is misnamed, but it’s too late to change it now. */

    return 0;
}