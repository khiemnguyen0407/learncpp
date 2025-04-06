/* Function parameters and arguments */

/* 
In many cases, it is useful to be able to pass information to a function being called, so that 
the function has data to work with. For example, if we wanted to write a function to add two 
numbers, we need some way to tell the function which two numbers to add when we call it. Otherwise, 
how would the function know what to add? We do that via function parameters and arguments.

A function parameter is a variable used in the header of a function. Function parameters work 
almost identically to variables defined inside the function, but with one difference: they are 
initialized with a value provided by the caller of the function.

Function parameters
===================
Function parameters are defined in the function header by placing them in between the parenthesis 
after the function name, with multiple parameters being separated by commas.

Arguments
=========
An argument is a value that is passed from the caller to the function when a function call is made.
*/

#include <iostream>

// This function takes no parameters
// It does not rely on the caller for anything
void do_print()
{
    std::cout << "In do_print()\n";
}

// This function takes one integer parameter named x
// The caller will supply the value of x
void print_integer(int x)
{
    std::cout << x << '\n';
}

// This function has two integer parameters, one named x, and one named y
// The caller will supply the value of both x and y
int add(int x, int y)
{
    return x + y;
}

int main()
{
    do_print(); // this call has no arguments

    print_integer(42); // 42 is the argument passed to the function print_integer()

    add(24, 42); // 24 and 42 are the arguments passed to the function add()
    // Note that multiple arguments are also separated by commas.
}