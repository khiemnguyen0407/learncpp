#include <iostream>

int main()
{
    /* Pointers and lvalue references behave similarly. 
    Consider the following code snippet */
    int x{ 5 };
    int& ref { x };  // get a reference to x
    int* ptr { &x }; // get a pointer to x

    std::cout << "x = " << x << '\n';
    std::cout << "ref = " << ref << '\n';  // use the reference to print x's value (5)
    std::cout << "*ptr = " << *ptr << "\n\n"; // use the pointer to print x's value (5)

    ref = 6; // use the reference to change the value of x
    std::cout << "x = " << x << '\n';
    std::cout << "ref = " << ref << '\n';  // use the reference to print x's value (6)
    std::cout << "*ptr = " << *ptr << "\n\n"; // use the pointer to print x's value (6)

    *ptr = 7; // use the pointer to change the value of x
    std::cout << "x = " << x << '\n';
    std::cout << "ref = " << ref << '\n';  // use the reference to print x's value (7)
    std::cout << "*ptr = " << *ptr << "\n\n"; // use the pointer to print x's value (7)


    /* The address-of operator returns a pointer 
    ==================================================== */

    int y{ 4 };
    std::cout << typeid(y).name() << '\n';      // print type of x
    std::cout << typeid(&y).name() << '\n';     // print type of &x

    /* Size of pointers (we are using 64-bit executable system)
    ===================================================== */
    char* char_ptr{};       // chars are 1 byte
    int* int_ptr{};         // ints are usually 4 bytes
    long double* ld_ptr{};  // long doubles are usually 8 or 12 bytes

    std::cout << sizeof(char_ptr) << '\n';  // print 8
    std::cout << sizeof(int_ptr) << '\n';   // print 8
    std::cout << sizeof(ld_ptr) << '\n';    // print 8

    float f{0.0};
    std::cout << sizeof(f) << '\n';
    return 0;
}