#include <iostream>

int main()
{
    int* ptr {}; // ptr is a null pointer, and is not holding an address
    std::cout << ptr << '\n';
    int x { 5 };
    ptr = &x; // ptr now pointing at object x (no longer a null pointer)

    std::cout << *ptr << '\n'; // print value of x through dereferenced ptr

    return 0;
}