#include <iostream>

int main()
{
    const int x { 5 };
    const int& ref { x };

    std::cout << ref << '\n';       // okay: we cann access the const object
    ref = 6;                        // error: we cannot modify an object through a const reference

    /* Initilizing an lvalue reference to constant with a modifiable lvalue */
    int x { 5 };
    const int& ref { x };

    std::cout << ref << '\n';       // okay: we can access the object through our const reference
    ref = 7;                        // error: we can not modify an object through a const reference
    x = 6;      // okay: x is a modifiable lvalue, we can still modify it through the original identifier

    /* Surprisingly, lvalues references to const can also bind to rvalues */
    const int& ref { 5 };           // okay: 5 is an rvalue
    std::cout << ref << '\n';

    /* Initialzing an lvalue reference to const with a value of a different type */
    /*===========================================================================*/
    // case 1
    const double& r1 { 5 };  // temporary double initialized with value 5, r1 binds to temporary

    std::cout << r1 << '\n'; // prints 5

    // case 2
    char c { 'a' };
    const int& r2 { c };     // temporary int initialized with value 'a', r2 binds to temporary

    std::cout << r2 << '\n'; // prints 97 (since r2 is a reference to int)

    /* Warning:
    We normally assume that a reference is identical to the object it is bound to -- but 
    when the reference is bound to a temporary copy of the object rather than the object 
    itself, this assumption is broken. Any modifications subsequently made to the original 
    object will not be seen by the reference (as it is referencing a copy).

    Here's a silly example showing this:
    */
   
    short bombs { 1 };         // I can has a bomb

    const int& you { bombs };  // You likes to set bombs off
    --bombs;                   // I can disarmed a bomb

    if (you)                   // If you can still has a bomb
    {
        std::cout << "Bombs away!  Goodbye, cruel world.\n";
    }

    return 0;

}