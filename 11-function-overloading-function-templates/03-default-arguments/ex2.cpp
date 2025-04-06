/* Multiple default arguments */

/*
Of course, just like in Python programming you already learned, a function can have multiple
parameters with default arguments.

The following discussion is relevant after reading the code.
============================================================
C++ does not (as of C++23) support a function call syntax such as print(,,3) (as a way to provide 
an explicit value for z while using the default arguments for x and y. This has three major 
consequences:

    (1) In a function call, any explicitly provided arguments must be the leftmost arguments 
        (arguments with defaults cannot be skipped).
    (2) If a parameter is given a default argument, all subsequent parameters (to the right) must 
        also be given default arguments. This is not a surprise as it must be so in Python too.
        The following defintion is not allowed:
        void print(int x=10, int y); // not allowed
    (3) If more than one parameter has a default argument, the leftmost parameter should be the one 
        most likely to be explicitly set by the user.


*/

#include <iostream>

void print_numbers(int x=10, int y=20, int z=30)
{
    std::cout << "Values: " << x << " " << y << " " << z << '\n';
}

void print_mixed(std::string_view sv="Hello", double d=10.0)
{
    std::cout << "string: " << sv << '\n';
    std::cout << "double value: " << d << '\n';
}

int main()
{
    print_numbers(1, 2, 3); // all explicit arguments
    print_numbers(1, 2); // rightmost argument defaulted
    print_numbers(1); // two rightmost arguments defaulted
    print_numbers(); // all arguments defaulted

    print_mixed();
    print_mixed("Sparghetti");
    // print_mixed(42.0);  // error: does not match above function (cannot skip argument for sv)

    return 0;
}