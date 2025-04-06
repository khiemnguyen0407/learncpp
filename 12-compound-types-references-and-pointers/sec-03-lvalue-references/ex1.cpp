#include <iostream>

int main()
{
    /* First straightforward example */
    int x { 5 };    // x is a normal integer variable
    int& ref { x }; // ref is an lvalue reference variable that can now be used as an alias for variable x

    std::cout << x << '\n';  // print the value of x (5)
    std::cout << ref << '\n'; // print the value of x via ref (5)

    x = 6;
    std::cout << "x = " << x << "-- ref = " << ref << '\n';

    ref = 7;
    std::cout << "x = " << x << "-- ref = " << ref << '\n';

    /* Invalid example 1 */
    // int& invalid_ref;       // error: references must be initialized

    /* Invalid example 2 */

    // const int y { 5 };
    // int& invalid_ref { y };         // invalid: non-const lvalue reference cannot bind to a non-modifiable lvalue
    // int& invliad_ref2 { 0 };        // invalid: non-const lvalue reference cannot bind to an rvalue

    /* Invalid example 3 */

    // double d {6.0};
    // int& invalid_Ref {d};           // invalid: conversion of double to int is narrowing conversion, disallowed by list initialization
    // double& invalid_ref2 { x };     // invalid: non-const lvalue reference can't bind to rvalue (result of converting x to double)


    /* Lifetime of reference and referant */

    int x { 5 };
    {
        int& ref2 {x};
        std::cout << ref << '\n';
    }       // ref is destroyed here -- x is unware of this
    std::cout << x << '\n';
    std::cout << ref2 << '\n';
    /* Dangling references */
    

    return 0;
}