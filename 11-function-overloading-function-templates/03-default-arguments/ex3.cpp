/* Default arguments and function overloading */

/* 
Functions with default arguments may be overloaded.
*/

#include <iostream>
#include <string_view>

void print(std::string_view s)
{
    std::cout << s << '\n';
}

void print(double x = 0.0)
{
    std::cout << x << '\n';
}

/* Default values are not part of a function's signature, so the following function declarations
are differentiation overloads.
*/

int main()
{
    print("Hello, world"); // resolves to print(std::string_view)
    print(0.0);            // resolves to print(double)
    print();               // resolves to print(double)

    return 0;
}