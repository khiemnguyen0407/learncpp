/* Pointer arithmetic and subscripting are relative addresses */

// When first learning about array subscripting, it’s natural to assume that 
// the index represents a fixed element within the array: Index 0 is always 
// the first element, index 1 is always the second element, etc...

// This is a illusion. Array indices are actually relative positions. 
// The indices just appear fixed because we almost always index from the start 
// (element 0) of the array!

// Remember, given some pointer ptr, both *(ptr + 1) and ptr[1] return the 
// next object in memory (based on the type being pointed to). Next is a 
// relative term, not an absolute one. Thus, if ptr is pointing to element 0, 
// then both *(ptr + 1) and ptr[1] will return element 1. But if ptr is 
// pointing to element 3 instead, then both *(ptr + 1) and ptr[1] will 
// return element 4!

#include <array>
#include <iostream>

int main()
{
    const int arr[] { 9, 8, 7, 6, 5 };
    const int *ptr { arr }; // arr decays into a pointer to element 0

    // Prove that we're pointing at element 0
    std::cout << *ptr << " -- " << ptr[0] << '\n'; // prints 99
    // Prove that ptr[1] is element 1
    std::cout << *(ptr+1) << " -- " << ptr[1] << '\n'; // prints 88

    // Now set ptr to point at element 3
    ptr = &arr[3];

    // Prove that we're pointing at element 3
    std::cout << *ptr << " -- " << ptr[0] << '\n'; // prints 66
    // Prove that ptr[1] is element 4!
    std::cout << *(ptr+1) << " -- " << ptr[1] << '\n'; // prints 55

    return 0;
}

/* BEST PRACTICE
Favor subscripting when indexing from the start of the array (element 0), so the 
array indices line up with the element. Favor pointer arithmetic when doing 
relative positioning from a given element.
*/