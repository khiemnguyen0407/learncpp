/* The [[fallthrough]] attribute */

/*
Commenting intentional fallthrough is a common convention to tell other developers that fallthrough 
is intended. While this works for other developers, the compiler and code analysis tools don't know 
how to interpret comments, so it won’t get rid of the warnings.

To help address this, C++17 adds a new attribute called [[fallthrough]].

Attributes are a modern C++ feature that allows the programmer to provide the compiler with some 
additional data about the code. To specify an attribute, the attribute name is placed between 
double brackets. Attributes are not statements -- rather, they can be used almost anywhere where 
they are contextually relevant.

The [[fallthrough]] attribute modifies a null statement to indicate that fallthrough is intentional 
(and no warnings should be triggered):
*/
#include <iostream>

int main()
{
    switch (2)
    {
    case 1:
        std::cout << 1 << '\n';
        break;
    case 2:
        std::cout << 2 << '\n'; // Execution begins here
        [[fallthrough]]; // intentional fallthrough - note the semicolon to indicate the null statement
    case 3:
        std::cout << 3 << '\n'; // This is also executed
        
        break;
    }

    return 0;
}