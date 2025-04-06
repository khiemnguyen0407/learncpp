/* Dangling pointers: Part 1 */

#include <iostream>

int main()
{
    int* ptr{ new int }; // dynamically allocate an integer
    *ptr = 42; // put a value in that memory location
    std::cout << "ptr = " << ptr << '\n';
    std::cout << "*ptr = " << *ptr << '\n';
    delete ptr; // return the memory to the operating system.  ptr is now a dangling pointer.

    // Dereferencing a dangling pointer will cause undefined behavior
    // std::cout << *ptr; 

    // trying to deallocate the memory again will also lead to undefined behavior.
    // delete ptr; 

    ptr = nullptr;                              // ptr is now a null pointer
    std::cout << "ptr = " << ptr << '\n';       // prints ptr = 0.
    std::cout << "nullptr is printed as " << nullptr;   // it prints nullptr.

    return 0;
}