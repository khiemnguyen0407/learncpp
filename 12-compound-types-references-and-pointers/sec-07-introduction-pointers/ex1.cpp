#include <iostream>

int main()
{
    int x1 { 42 };
    std::cout << "x1 = " << x1 << '\n'; // print the value of variable x

    int* ptr = { &x1 }; // ptr holds the address of x
    std::cout << "x1 = " << *ptr << '\n'; // use dereference operator to print the value at the address that ptr is holding (which is x's address)

    /* =================================================================================
    Much like the type of a reference has to match the type of object 
    being referred to, the type of the pointer has to match the type of 
    the object being pointed to: 
    ====================================================================================*/

    int i{ 5 };
    double d{ 7.0 };

    int* iPtr{ &i };     // ok: a pointer to an int can point to an int object
    // int* iPtr2 { &d };   // not okay: a pointer to an int can't point to a double object

    double* dPtr{ &d };  // ok: a pointer to a double can point to a double object
    // double* dPtr2{ &i }; // not okay: a pointer to a double can't point to an int object

    /* ================================================================================
    With one exception that we’ll discuss next lesson, initializing a 
    pointer with a literal value is disallowed: 
    ===================================================================================*/

    // int* ptr{ 5 }; // not okay
    // int* ptr{ 0x0012FF7C }; // not okay, 0x0012FF7C is treated as an integer literal


    int y1{ 5 };
    int* ptr2 { &y1 };

    std::cout << "y1 = " << *ptr2 << '\n';
    
    int y2{ 10 };
    ptr2 = &y2;

    std::cout << "y2 = " << *ptr2 << '\n';

    /* We can also use a pointer to change the value being pointed at 
    ============================================================================== */
    int x{ 5 };
    int* ptr3{ &x }; // initialize ptr with address of variable x

    std::cout << x << '\n';    // print x's value
    std::cout << *ptr3 << '\n'; // print the value at the address that ptr is holding (x's address)

    *ptr3 = 6; // The object at the address held by ptr (x) assigned value 6 (note that ptr is dereferenced here)
    ptr3 = &y1;
    std::cout << x << '\n';
    std::cout << *ptr3 << '\n'; // print the value at the address that ptr is holding (x's address)

    return 0;

}