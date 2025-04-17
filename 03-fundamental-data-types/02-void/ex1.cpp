/* Void */

/*
Void is the easiest of the data types to explain. Basically, void means “no type”! 

Void is our first example of an incomplete type. An incomplete type is a type that has been 
declared but not yet defined. The compiler knows about the existence of such types, but does not 
have enough information to determine how much memory to allocate for objects of that type. void is 
intentionally incomplete since it represents the lack of a type, and thus cannot be defined.

Incomplete types can not be instantiated:

void value; // won't work, variables can't be defined with incomplete type void

Void is typically used in several different contexts. Most commonly, void is used to indicate that 
a function does not return a value.
*/

#include <iostream>
void return_nothing(int x)
{
    std::cout << "x = " << x << '\n';
}

int main()
{
    return_nothing(10);

    return 0;
}