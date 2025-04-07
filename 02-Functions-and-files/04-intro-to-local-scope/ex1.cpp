/* Local variables */

/*
Variables defined inside the body of a function are called local variables (as opposed to global 
variables, which we’ll discuss in a future chapter):
int add(int x, int y)
{
    int z{ x + y }; // z is a local variable

    return z;
}

Function parameters are also generally considered to be local variables, and we will include them 
as such:
int add(int x, int y) // function parameters x and y are local variables
{
    int z{ x + y };

    return z;
}

Local variable lifetime
=======================

Function parameters are created and initialized when the function is entered, and variables within 
the function body are created and initialized at the point of definition.

The natural follow-up question is, "so when is an instantiated variable destroyed?". Local variables
are destroyed in the opposite order of creation at the end of the set of curly braces in which it 
is defined (or for a function parameter, at the end of the function).

Much like a person's lifetime is defined to be the time between their birth and death, an 
object's lifetime is defined to be the time between its creation and destruction. Note that 
variable creation and destruction happen when the program is running (called runtime), not at 
compile time. Therefore, lifetime is a runtime property.

int add(int x, int y)
{
    int z{ x + y };

    return z;
} // z, y, and x destroyed here

What happens when an object is destroyed?
=========================================
In most cases, nothing. The destroyed object simply becomes invalid. Any use of an object after it 
has been destroyed will result in undefined behavior. At some point after destruction, the memory 
used by the object will be deallocated (freed up for reuse).
*/

// a slightly more complex program demonstrating the lifetime of a variable named x

#include <iostream>

void say_hello()
{
    std::cout << "Hello!\n";
}

int main()
{
    int x{ 0 };    // x's lifetime begins here

    say_hello(); // x is still alive during this function call

    return 0;
} // x's lifetime ends here
