/* Pointers to pointers and dynamic multidimensional arrays */

/*
As a pointer is a data type, an object, it has its own address on the memory. Bingo! A pointer to
a pointer is exactly what you’d expect: a pointer that holds the address of another pointer.

A normal pointer to an int is declared using a single asterisk. A pointer to a pointer to an int is 
declared using two asterisks

int** ptr_to_intptr;

A pointer to a pointer works just like a normal pointer — you can dereference it to retrieve the 
value pointed to. And because that value is itself a pointer, you can dereference it again to get 
to the underlying value. These dereferences can be done consecutively

*/

#include <iostream>
int main () 
{
    int value { 42 };
    int* ptr { &value };       // pointer to an int, one asterisk
    std::cout << "*ptr = " << *ptr << '\n';

    int** ptrptr { &ptr };   // pointer to a pointer to an int, two asterisks
    std::cout << "**ptrptr = " << **ptrptr << '\n';

    // Array of 10 integers
    int* array {new int[] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} };
    
    /* Arrays of pointers */
    int** ptr_array { new int* [10] };
    for (int j {0}; j < 10; ++j) {
        ptr_array[j] = &array[j];
        std::cout << "ptr_array[" << j << "] = " << ptr_array[j]<< '\n';
    }

}