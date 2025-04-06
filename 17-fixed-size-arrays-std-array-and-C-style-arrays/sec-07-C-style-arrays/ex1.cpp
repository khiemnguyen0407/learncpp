#include <iostream>

int main()
{
    // Defines a C-style array named testScore that contains 30 
    // value-initialized int elements (no include required)
    int int_numbers[30] {};

    // When declaring an array (e.g. int arr[5]), the use of [] is part 
    // of the declaration syntax, not an invocation of the subscript 
    // operator operator[].
    int arr1[5]; // define an array of 5 int values
    arr1[1] = 42;
    std::cout << "arr1[1] = " << arr1[1] << '\n';

    /* Unlike the standard library container classes 
    We can use the signed and unsigned index in C-style array */

    const int arr2[] {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i { 2 };
    std::cout << "arr2[2] = " << arr2[i] << '\n';

    unsigned int j { 4 };
    std::cout << "arr2[4] = " << arr2[j] << '\n';

    /* Aggregate initialization of C-style arrays */
    int fibonnaci[6] = { 0, 1, 1, 2, 3, 5 };    // copy-list initialization using braced list
    int primes[5] {2, 3, 5, 7, 11};             // list initialization using braced list (prefereced)

    int a[5];       // members default initialized int elements are left uninitialized
    int b[5] {};    // members value initialized (int elements are zero) (preferred)
    

    int c[] { 1, 2, 3, 4 };     // compilation error: too many initializers
    int d[4] { 1, 2 };              // d[2] and d[3] are valu initialized (=0)
    return 0;
}