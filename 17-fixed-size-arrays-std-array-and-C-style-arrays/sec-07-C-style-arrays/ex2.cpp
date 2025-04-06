/* C++ arrays don’t support assignment */
#include <iostream>
#include <algorithm> // for std::copy

int main()
{
    int a[] { 1, 2, 3 }; // okay: initialization is fine
    a[0] = 4;            // assignment to individual elements is fine

    /* Technically, this doesn’t work because assignment requires the 
    left-operand to be a modifiable lvalue, and C-style arrays are not 
    considered to be modifiable lvalues. */
    // b = { 5, 6, 7 };     // compile error: array assignment not valid


    /* If you need to assign a new list of values to an C-style array, 
    it’s best to use a std::vector instead. Alternatively, you can 
    assign new values to a C-style array element-by-element, or use 
    std::copy to copy an existing C-style array */

    int arr[] { 1, 2, 3 };
    int src[] { 5, 6, 7 };

    // Copy src into arr
    std::copy(std::begin(src), std::end(src), std::begin(arr));
    for (int i {0}; i < 3; i++)
        std::cout << arr[i] << '\t';
        
    std::cout << '\n';
    for (int i {0}; i < 3; i++) 
        std::cout << src[i] << '\t';
    std::cout << '\n';
    return 0;
}